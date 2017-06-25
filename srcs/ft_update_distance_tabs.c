/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_distance_tabs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 08:09:01 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 08:10:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			ft_update_distance_tab(uint32_t *distance
										, t_board *board, t_coord pos)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;

	i = 0;
	while (i < board->len_y)
	{
		u = 0;
		while (u < board->long_nbr)
		{
			x = 0;
			while (x < 64)
			{
				distance[i * board->len_x + u * 64 + x] =
					ft_get_manhattan_distance(pos, (t_coord){u * 64 + x, i});
				x++;
			}
			u++;
		}
		i++;
	}
	distance[-1] = 1;
}

void				ft_update_distance_tabs(uint32_t distance_tab[10000][10001]
											, t_board *board)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;

	i = 0;
	while (i < board->len_y)
	{
		u = 0;
		while (u < board->long_nbr)
		{
			x = ~0U;
			while (++x < 64)
				if (((((t_champ*)&board->player_1)
					[board->player_index ^ 1].map.map
					[i * board->long_nbr + u]) >> (63 - x)) & 1
					&& !distance_tab[i * board->len_x + u * 64 + x][0])
					ft_update_distance_tab(distance_tab[i * board->len_x
					+ u * 64 + x] + 1, board, (t_coord){u * 64 + x, i});
			u++;
		}
		i++;
	}
}
