/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:34:02 by tidadi            #+#    #+#             */
/*   Updated: 2019/01/04 20:34:08 by tidadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_board bd;
	char	buf[20];
	t_list	*tetriminos;
	int		fd;

	if (argc != 2)
		return (display_usage_error(0));
	initialize_board(bd.board);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (display_usage_error(1));
	tetriminos = create_list(fd, buf);
	if (!tetriminos)
		return (display_usage_error(1));
	bd.size = get_board_size(count_pieces(tetriminos));
	if (!solve(&bd, tetriminos))
		return (display_usage_error(1));
	print_board(bd.board, bd.size);
	return (0);
}
