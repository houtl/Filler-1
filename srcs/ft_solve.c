/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:45:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 04:42:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_solve(t_board *board, t_piece *piece)
{
	t_coord		pos;
	uint32_t	i;
	uint32_t	size;
	uint32_t	current_distance;
	uint32_t	tmp_distance;

	i = 0;
	size = board->len_x * board->len_y;
	current_distance = ~0U;
	pos = (t_coord){123123123, 123123123};
	while (i < size)
	{
		if (ft_claim(piece, board, ft_get_pos(i, board)))
		{
			if ((tmp_distance = ft_get_distance(board, piece
				, ft_get_pos(i, board))) < current_distance)
			{
				current_distance = tmp_distance;
				pos = ft_get_pos(i, board);
			}
		}
		i++;
	}
	ft_print_coord(pos, piece);
}
