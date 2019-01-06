/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:33:27 by tidadi            #+#    #+#             */
/*   Updated: 2019/01/04 20:33:38 by tidadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct		s_board
{
	char			board[104][104];
	int				size;
}					t_board;

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	int				content_size;
}					t_list;

typedef struct		s_tet
{
	int				row;
	int				col;
	char			letter;
	char			shape[4][4];
}					t_tet;

typedef struct		s_piece
{
	int				num;
	int				connection;
	int				left;
	int				top;
}					t_piece;

void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_putstr(const char *str);
int					display_usage_error(int error_code);
t_list				*ft_lstnew(void *tet_piece);
t_list				*ft_lstpush(t_list **head, t_list *last, t_list *new_ele);
t_list				*create_list(int fd, char *buf);
int					get_board_size(int pieces);
void				initialize_board(char board[104][104]);
void				print_board(char board[104][104], int size);
int					count_pieces(t_list *tetriminos);
void				initialize_piece(t_piece *piece);
int					count_connections(char *str, int position);
void				modify_piece(t_piece *piece, char *str, int row, int pos);
t_tet				*new_tet(char *str, int top, int left, int count);
void				add_tet(t_board *bd, int row, int col, t_tet *tet);
void				delete_tet(t_board *bd, int row, int col, t_tet *tet);
t_tet				*check_tet(char *str, int count);
int					fits_on_board(t_board *bd, t_tet *tet, int row, int col);
int					next_tet(t_board *bd, t_list *tetriminos);
int					solve(t_board *bd, t_list *tetriminos);

#endif
