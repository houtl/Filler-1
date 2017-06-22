/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:42:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/22 13:46:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint32_t	ft_get_distance_from_piece(t_piece *piece, t_coord pos_piece
											, uint32_t *distance_tab)
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
					if ((tmp = distance_tab[(i + pos_piece.y) * piece->len_x + u * 64 + x + pos_piece.x]) < distance)
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

static void			ft_update_distance_tab(uint32_t *distance, t_board *board, t_coord pos)
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

static void			ft_update_distance_tabs(uint32_t distance_tab[10000][10001], t_board *board)
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
				if (((((t_champ*)&board->player_1)[board->player_index ^ 1]
					  .map.map[i * board->long_nbr + u]) >> (63 - x)) & 1 && !distance_tab[i * board->len_x + u * 64 + x][0])
				{
					ft_update_distance_tab(distance_tab[i * board->len_x + u * 64 + x] + 1, board, (t_coord){u * 64 + x, i});
				}
				x++;
			}
			u++;
		}
		i++;
	}
}

uint32_t		ft_get_distance(t_board *board, t_piece *piece, t_coord pos)
{
	static uint32_t	distance_tab[10000][10001];
	uint32_t	i;
	/* uint32_t	u; */
	/* uint32_t	x; */
	uint32_t	distance;
	uint32_t	tmp;

	i = 0;
	ft_update_distance_tabs(distance_tab, board);
	distance = ~0U;
	(void)piece;
	/* while (i < board->len_y) */
	/* { */
	/* 	u = 0; */
	/* 	while (u < board->long_nbr) */
	/* 	{ */
	/* 		x = 0; */
	/* 		while (x < 64) */
	/* 		{ */
	/* 			if (((((t_champ*)&board->player_1)[board->player_index ^ 1] */
	/* 				.map.map[i * board->long_nbr + u]) >> (63 - x)) & 1) */
	/* 			{ */
	/* 				if (distance > (tmp = ft_get_manhattan_distance(pos, (t_coord){u * 64 + x, i}))) */
	/* 					distance = tmp; */
	/* 			} */
	/* 			x++; */
	/* 		} */
	/* 		u++; */
	/* 	} */
	/* 	i++; */
	/* } */
	uint32_t	map_size;

	map_size = board->len_x * board->len_y;
	while (i < map_size)
	{
		if (distance_tab[i][0])
			if ((tmp = ft_get_distance_from_piece(piece, pos, distance_tab[i] + 1)) < distance)
				distance = tmp;
		i++;
	}
	return (distance);
}
