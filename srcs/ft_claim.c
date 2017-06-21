/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:47:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/21 13:53:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
// you know that there is a problem in cases of nbr_long * 64 < x
static uint32_t	ft_bin_mask_no_touch(t_piece *piece, t_board *board
									 , t_coord *coord, uint32_t y)
{
	uint64_t	ret;
	uint64_t	tmp;
	uint32_t	x;

	ret = 0;
	x = 0;
	while ((x < piece->long_nbr && (coord->x / 64) + x < board->long_nbr) || (ret && (coord->x / 64) + x < board->long_nbr))
	{
		tmp = (x < piece->long_nbr ? (piece->lines[y * piece->long_nbr + x] >> (coord->x & 63)) | ret
			   : ret);
		if (tmp & ((t_champ*)&board->player_1)[board->player_index ^ 1].map
			.map[(coord->y) * board->long_nbr + x + (coord->x / 64)])
			return (0);
		if (coord->x)
			ret = (x < piece->long_nbr ? (piece->lines[y * piece->long_nbr + x] << (64 - (coord->x & 63))) :
				   0);
		else
			ret = 0;
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

/* static uint32_t	ft_bin_mask_one_touch(t_piece *piece, t_board *board */
/* 									 , t_coord *coord, uint32_t y) */
/* { */
/* 	uint64_t	ret; */
/* 	uint64_t	tmp; */
/* 	uint64_t	mask; */
/* 	uint64_t	nbr_touch; */
/* 	uint32_t	x; */

/* 	ret = 0; */
/* 	x = 0; */
/* 	nbr_touch = 0; */
/* 	while (x < piece->long_nbr || (ret && x + (coord->x / 64) */
/* 								   < board->long_nbr)) */
/* 	{ */
/* 		tmp = (x < piece->long_nbr ? (piece->lines[y * piece->long_nbr + x] >> (coord->x & 63)) | ret */
/* 			   : ret); */
/* 		if (!ft_is_power_of_two((mask = (tmp */
/* 			& ((t_champ*)&board->player_1)[board->player_index].map.map[(coord->y) */
/* 			* board->long_nbr + x + (coord->x / 64)])))) */
/* 			return (2); */
/* 		if (mask) */
/* 			nbr_touch++; */
/* 		if (coord->x) */
/* 			ret = (x < piece->long_nbr ? (piece->lines[y * piece->long_nbr + x] << (64 - (coord->x & 63))) : */
/* 				   0); */
/* 		else */
/* 			ret = 0; */
/* 		x++; */
/* 	} */
/* 	return (nbr_touch == 1 ? 1 : 0); */
/* } */

static uint32_t	ft_bin_mask_one_touch(t_piece *piece, t_board *board
									 , t_coord coord, uint32_t y)
{
	uint64_t	tmp;
	uint64_t	ret;
	uint32_t	i;
	uint64_t	mask;
	uint32_t	nbr_touch;

	i = 0;
	while (i < piece->long_nbr)
	{
		tmp = piece->lines[y *
		i++;
	}
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
	if (u + piece->len_y > board->len_y
		|| i + piece->len_x > board->len_x)
		return (0);
	while (u < pos.y + piece->len_y)
	{
		nbr_touch += ft_bin_mask_one_touch(piece, board, (t_coord){i, u}, u - pos.y);
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
	uint32_t a = (!ft_overwrite_board(piece, board, pos));
	uint32_t b = (ft_can_be_connected(piece, board, pos));
	if ((a = 1 /* !ft_overwrite_board(piece, board, pos) */)
		&& (b = ft_can_be_connected(piece, board, pos)))
	{
#if DEBUG == 1
		ft_putchar_fd('$', 2);
# endif
		return (1);
	}
	else
	{
#if DEBUG == 1
		if (!a && !b)
			ft_putchar_fd('#', 2);
		else if (!b)
			ft_putchar_fd('/', 2);
		else if (!a)
			ft_putchar_fd('o', 2);
		else
			ft_putchar_fd('.', 2);
# endif
	}
	return (0);
}
