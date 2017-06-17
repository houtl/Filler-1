/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 07:41:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/01 20:08:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint32_t	ft_put_piece_line(t_piece *piece, t_map *map
									 , t_coord *coord, uint32_t y)
{
	uint64_t	ret;
	uint64_t	tmp;
	uint32_t	x;

	ret = 0;
	x = 0;
	while (x < piece->long_nbr)
	{
		tmp = (piece->lines[y * piece->long_nbr + x] >> coord->x) | ret;
		if (tmp & map->map[(coord->y) * map->long_nbr + x])
			return (0);
		map->map[(coord->y) * map->long_nbr + x] |= tmp;
		ret = (piece->lines[y * piece->long_nbr + x] << (map->len_x - coord->x));
		x++;
	}
	return (1);
}

static uint32_t	ft_put_piece_lines(t_piece *piece, t_map *map
								   , t_coord *coord)
{
	uint32_t	i;
	uint32_t	u;

	u = coord->y;
	i = coord->x;
	while (u - coord->y < piece->len_y)
	{
		if (!ft_put_piece_line(piece, map, &(t_coord){i, u}, u - coord->y))
			return (1);
		u++;
	}
	return (0);
}

void	ft_put_piece(t_map *map, t_piece *piece
					, t_coord pos)
{
	ft_put_piece_lines(piece, map, &pos);
}
