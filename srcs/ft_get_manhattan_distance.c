/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_manhattan_distance.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 04:15:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 04:23:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

uint32_t	ft_get_manhattan_distance(t_board *board, uint32_t player_index
									  , t_coord pos)
{
	if (!player_index)
		return ((uint32_t)ft_distance(board->player_1.last_piece.x, pos.x) +
				(uint32_t)ft_distance(board->player_1.last_piece.y, pos.y));
	else
		return ((uint32_t)ft_distance(board->player_2.last_piece.x, pos.x) +
				(uint32_t)ft_distance(board->player_2.last_piece.y, pos.y));
}
