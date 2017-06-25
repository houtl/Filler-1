/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:45:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 09:31:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_solve(t_board *board, t_piece *piece)
{
	t_coord		pos;
	t_coord		current_pos;
	uint32_t	i;
	uint32_t	size;
	uint32_t	distance_tab[2];

	i = 0;
	size = board->len_x * board->len_y;
	distance_tab[0] = ~0U;
	pos = (t_coord){123123123, 123123123};
	while (i < size)
	{
		current_pos = ft_get_pos(i, board);
		if (ft_claim(piece, board, current_pos))
		{
			if ((distance_tab[1] = ft_get_distance(board, piece
				, current_pos)) < distance_tab[0])
			{
				distance_tab[0] = distance_tab[1];
				pos = current_pos;
			}
		}
		i++;
	}
	ft_print_coord(pos, piece);
}
