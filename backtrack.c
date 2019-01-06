/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:33:00 by tidadi            #+#    #+#             */
/*   Updated: 2019/01/04 20:33:04 by tidadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fits_on_board(t_board *bd, t_tet *tet, int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < (4 - tet->row))
	{
		j = 0;
		while (j < (4 - tet->col))
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
			{
				if (col + j >= bd->size || row + i >= bd->size || \
						(bd->board)[row + i][col + j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	next_tet(t_board *bd, t_list *tetriminos)
{
	int row;
	int col;

	if (!tetriminos)
		return (1);
	row = 0;
	while (row < bd->size)
	{
		col = 0;
		while (col < bd->size)
		{
			if (fits_on_board(bd, tetriminos->content, row, col))
			{
				add_tet(bd, row, col, tetriminos->content);
				if (next_tet(bd, tetriminos->next))
					return (1);
				else
					delete_tet(bd, row, col, tetriminos->content);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	solve(t_board *bd, t_list *tetriminos)
{
	while (!next_tet(bd, tetriminos))
		bd->size += 1;
	return (1);
}
