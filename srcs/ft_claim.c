/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:47:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 08:02:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint32_t	ft_bin_mask_no_touch(t_piece *piece, t_board *board
									, t_coord *coord, uint32_t y)
{
	uint64_t	ret;
	uint64_t	tmp;
	uint32_t	x;

	ret = 0;
	x = 0;
	while ((x < piece->long_nbr || ret) && ((coord->x / 64) + x
											< board->long_nbr))
	{
		tmp = (x < piece->long_nbr ? (piece->lines[y * piece->long_nbr + x]
				>> (coord->x & 63)) | ret : ret);
		if (tmp & ((t_champ*)&board->player_1)[board->player_index ^ 1].map
			.map[(coord->y) * board->long_nbr + x + (coord->x / 64)])
			return (0);
		if ((coord->x & 63))
			ret = (x < piece->long_nbr ? (piece->lines[y * piece->long_nbr + x]
					<< (64 - (coord->x & 63))) : 0);
		else
			ret = 0;
		x++;
	}
	return (1);
}

uint32_t		ft_overwrite_board(t_piece *piece, t_board *board
							, t_coord pos)
{
	uint32_t	i;
	uint32_t	u;

	u = pos.y;
	i = pos.x;
	if (u + piece->len_y > board->len_y
		|| i + piece->len_x > board->len_x)
		return (0);
	while (u < board->len_y
		&& u - pos.y < piece->len_y)
	{
		if (!ft_bin_mask_no_touch(piece, board, &(t_coord){i, u}, u - pos.y))
			return (1);
		u++;
	}
	return (0);
}

static uint32_t	ft_bin_mask_one_touch(t_piece *piece, t_board *board
									, t_coord coord, t_coord long_coord)
{
	uint64_t	tmp;
	uint64_t	r;
	uint32_t	i;
	uint64_t	mask;
	uint32_t	nbr_touch;

	i = ~0U;
	nbr_touch = 0;
	r = 0;
	while ((++i < piece->long_nbr || r) && (long_coord.x + i < board->long_nbr))
	{
		tmp = (i < piece->long_nbr) ? piece->lines
			[long_coord.y * piece->long_nbr + i] >> (coord.x & 63) | r : r;
		if (!ft_is_power_of_two((mask = tmp & ((t_champ*)&board->player_1)
[board->player_index].map.map[(coord.y) * board->long_nbr + i + long_coord.x])))
			return (2);
		if (mask)
			nbr_touch++;
		if ((coord.x & 63) == 0)
			r = 0;
		else
			r = (i < piece->long_nbr) ? piece->lines[long_coord.y
					* piece->long_nbr + i] << (64 - (coord.x & 63)) : 0;
	}
	return (nbr_touch);
}

uint32_t		ft_can_be_connected(t_piece *piece, t_board *board
								, t_coord pos)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	nbr_touch;

	u = pos.y;
	i = pos.x;
	nbr_touch = 0;
	if (u + piece->len_y > board->len_y
		|| i + piece->len_x > board->len_x)
		return (0);
	while (u < pos.y + piece->len_y)
	{
		nbr_touch += ft_bin_mask_one_touch(piece, board
					, (t_coord){i, u}, (t_coord){pos.x / 64, u - pos.y});
		if (nbr_touch > 1)
			return (0);
		u++;
	}
	return (nbr_touch == 1 ? 1 : 0);
}

uint32_t		ft_claim(t_piece *piece, t_board *board, t_coord pos)
{
	if ((!ft_overwrite_board(piece, board, pos))
		&& (ft_can_be_connected(piece, board, pos)))
		return (1);
	return (0);
}
