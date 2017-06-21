/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:42:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/21 04:32:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint32_t	ft_get_distance_from_piece(t_piece *piece, t_coord pos_piece
											, t_coord pos_ennemy)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;
	uint32_t	distance;
	uint32_t	tmp;

	i = 0;
	distance = 0xFFFFFFF;
	while (i < piece->len_y)
	{
		u = 0;
		while (u < piece->long_nbr)
		{
			x = 0;
			while (x < 64)
			{
				if (((piece->lines[i * piece->long_nbr + u]) >> (63 - x)) & 1)
				{
					if ((tmp = ft_get_manhattan_distance(
						(t_coord){(u << 6) + x + pos_piece.x, i + pos_piece.y}
						, pos_ennemy)) < distance)
						distance = tmp;

				}
				x++;
			}
			u++;
		}
		i++;
	}
	return (distance);
}

uint32_t		ft_get_distance(t_board *board, t_piece *piece, t_coord pos)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;
	uint32_t	distance;
	uint32_t	tmp;

	i = 0;
	distance = ~0U;
	while (i < board->len_y)
	{
		u = 0;
		while (u < board->long_nbr)
		{
			x = 0;
			while (x < 64)
			{
				if (((((t_champ*)&board->player_1)[board->player_index ^ 1]
					.map.map[i * board->long_nbr + u]) >> (63 - x)) & 1)
				{
					if (distance > (tmp = ft_get_distance_from_piece(piece, pos, (t_coord){u * 64 + x, i})))
						distance = tmp;
				}
				x++;
			}
			u++;
		}
		i++;
	}
	return (distance);
}
