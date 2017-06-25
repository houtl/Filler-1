/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:42:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 08:09:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint32_t	ft_get_piece_nbr_coords(t_piece *piece)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;
	uint32_t	nbr_coords;

	i = 0;
	nbr_coords = 0;
	while (i < piece->len_y)
	{
		u = 0;
		while (u < piece->long_nbr)
		{
			x = ~0U;
			while (++x < 64)
				if (((piece->lines[i * piece->long_nbr + u]) >> (63 - x)) & 1)
					nbr_coords++;
			u++;
		}
		i++;
	}
	return (nbr_coords);
}

static t_coord	*ft_get_piece_coords(t_piece *piece, uint32_t nbr_coords
									, t_coord pos)
{
	t_coord		*coords;
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;
	uint32_t	count;

	i = 0;
	count = 0;
	if (!(coords = (t_coord*)ft_memalloc(sizeof(t_coord) * nbr_coords)))
		return (NULL);
	while (i < piece->len_y)
	{
		u = 0;
		while (u < piece->long_nbr)
		{
			x = ~0U;
			while (++x < 64)
				if (((piece->lines[i * piece->long_nbr + u]) >> (63 - x)) & 1)
					coords[count++] = (t_coord){u * 64 + x + pos.x, i + pos.y};
			u++;
		}
		i++;
	}
	return (coords);
}

static uint32_t	ft_get_distance_from_piece(t_coord *piece_coords, t_board *board
								, uint32_t *distance_tab, uint32_t nbr_coords)
{
	uint32_t	i;
	uint32_t	distance;
	uint32_t	tmp;

	i = 0;
	distance = 0xFFFFFFFF;
	while (i < nbr_coords)
	{
		if ((tmp = distance_tab[board->len_x * piece_coords[i].y
								+ piece_coords[i].x]) < distance)
			distance = tmp;
		i++;
	}
	return (distance);
}

uint32_t		ft_get_distance(t_board *board, t_piece *piece, t_coord pos)
{
	static uint32_t	distance_tab[10000][10001];
	t_coord			*piece_coords __attribute__((cleanup(CLEANUP_NORM)));
	uint32_t		nbr_coords;
	uint32_t		map_size;
	uint32_t		tab[3];

	tab[0] = ~0U;
	ft_update_distance_tabs(distance_tab, board);
	nbr_coords = ft_get_piece_nbr_coords(piece);
	piece_coords = NULL;
	if (!(piece_coords = ft_get_piece_coords(piece, nbr_coords, pos)))
		return (~0U);
	tab[1] = 0xFFFFFFFF;
	map_size = board->len_x * board->len_y;
	while (++tab[0] < map_size)
	{
		if (distance_tab[tab[0]][0])
			if ((tab[2] = ft_get_distance_from_piece(piece_coords, board
				, distance_tab[tab[0]] + 1, nbr_coords)) < tab[1])
				tab[1] = tab[2];
	}
	return (tab[1]);
}
