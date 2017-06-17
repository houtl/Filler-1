/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:47:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 03:58:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
// you know that there is a problem in cases of nbr_long * 64 < x
#define DEBUG 0
static uint32_t	ft_bin_mask_no_touch(t_piece *piece, t_board *board
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
#if DEBUG == 1
		ft_printf("At coord y:%u x:%u\n", coord->y, coord->x + x * 64);
		ft_printf("Piece->line[%u]: %064b\n", x, tmp);
		ft_printf("Board->line[%u]: %064b\n", coord->y, board->player_2[(coord->y) * board->long_nbr + x]);
		ft_printf("result->line[%u]: %064b\n", coord->y, tmp & board->player_2[(coord->y) * board->long_nbr + x]);
#endif
		if (tmp & board->player_2.map.map[(coord->y) * board->long_nbr + x])
			return (0);
		ret = (piece->lines[y * piece->long_nbr + x] << (board->len_x - coord->x));
		x++;
	}
	return (1);
}

uint32_t	ft_overwrite_board(t_piece *piece, t_board *board
							   , t_coord pos)
{
	uint32_t	i;
	uint32_t	u;

	u = pos.y;
	i = pos.x;
#if DEBUG == 1
	ft_printf("Starting pos y:%u x:%u\n", y, x);
#endif
	if (u + piece->len_y >= board->len_y
		|| i + piece->len_x >= board->len_x)
		return (0);
	while (u < pos.y + board->len_y
		&& u - pos.y < piece->len_y)
	{
		if (!ft_bin_mask_no_touch(piece, board, &(t_coord){i, u}, u - pos.y))
			return (1);
		u++;
	}
	return (0);
}

static uint32_t	ft_bin_mask_one_touch(t_piece *piece, t_board *board
									 , t_coord *coord, uint32_t y)
{
	uint64_t	ret;
	uint64_t	tmp;
	uint64_t	mask;
	uint64_t	nbr_touch;
	uint32_t	x;

	ret = 0;
	x = 0;
	nbr_touch = 0;
	while (x < piece->long_nbr)
	{
		tmp = (piece->lines[y * piece->long_nbr + x] >> coord->x) | ret;
#if DEBUG == 1
		ft_printf("At coord y:%u x:%u\n", coord->y, coord->x + x * 64);
		ft_printf("Piece->line[%u]: %064b\n", x, tmp);
		ft_printf("Board->line[%u]: %064b\n", coord->y, board->player_1[(coord->y) * board->long_nbr + x]);
		ft_printf("result->line[%u]: %064b\n", coord->y, tmp & board->player_1[(coord->y) * board->long_nbr + x]);
#endif
		if (!ft_is_power_of_two((mask = (tmp & board->player_1.map.map[(coord->y) * board->long_nbr + x]))))
			return (2);
		if (mask)
			nbr_touch++;
		ret = (piece->lines[y * piece->long_nbr + x] << (board->len_x - coord->x));
		x++;
	}
	return (nbr_touch == 1 ? 1 : 0);
}

uint32_t	ft_can_be_connected(t_piece *piece, t_board *board
								, t_coord pos)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	nbr_touch;

	u = pos.y;
	i = pos.x;
	nbr_touch = 0;
	if (u + piece->len_y >= board->len_y
		|| i + piece->len_x >= board->len_x)
		return (0);
	while (u < pos.y + piece->len_y)
	{
		nbr_touch += ft_bin_mask_one_touch(piece, board, &(t_coord){i, u}, u - pos.y);
		if (nbr_touch > 1)
			return (0);
		u++;
	}
	return (nbr_touch == 1 ? 1 : 0);
}

uint32_t	ft_claim(t_piece *piece, t_board *board, t_coord pos)
{
	uint32_t	x;
	uint32_t	y;

	y = pos.y;
	x = pos.x;
	if (!ft_overwrite_board(piece, board, pos)
		&& ft_can_be_connected(piece, board, pos))
		return (1);
	return (0);
}
