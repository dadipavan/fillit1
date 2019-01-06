/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:34:30 by tidadi            #+#    #+#             */
/*   Updated: 2019/01/04 20:34:33 by tidadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(t_list *tetriminos)
{
	int count;

	count = 0;
	while (tetriminos)
	{
		count++;
		tetriminos = tetriminos->next;
	}
	return (count);
}

void	initialize_piece(t_piece *piece)
{
	piece->num = 0;
	piece->connection = 0;
	piece->left = 4;
	piece->top = 4;
}

int		count_connections(char *str, int position)
{
	int count;

	count = 0;
	if (position % 5 > 0 && str[position - 1] == '#')
		count++;
	if (position % 5 < 4 && str[position + 1] == '#')
		count++;
	if (position / 5 > 0 && str[position - 5] == '#')
		count++;
	if (position / 5 < 4 && str[position + 5] == '#')
		count++;
	return (count);
}

void	modify_piece(t_piece *piece, char *str, int row, int pos)
{
	if (row < piece->top)
		piece->top = row;
	if (pos % 5 < piece->left)
		piece->left = pos % 5;
	piece->connection += count_connections(str, pos);
	piece->num += 1;
}
