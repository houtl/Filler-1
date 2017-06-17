/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_liberties_after_claim.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:19:53 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 03:08:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_set_sandbox(t_board *board, uint32_t index_player
						, t_map *sandbox)
{
	uint32_t	i;

	i = 0;
	ft_bzero(sandbox->map, board->size_longs);
	while (i < board->size_longs)
	{
		sandbox->map[i] |= board->player_1.map.map[board->size_longs * index_player + i];
		i++;
	}
}

uint32_t	ft_get_liberties_after_claim(t_board *board, t_piece *piece
										 , t_coord pos, uint32_t index_player)
{
	t_map			*sandbox;
	uint64_t		*tmp;
	uint32_t	liberties;

	if (!(sandbox = ft_get_sandbox_map(board)))
		return (~0U);
	ft_set_sandbox(board, index_player, sandbox);
	ft_put_piece(sandbox, piece, pos);
	if (!index_player)
	{
		tmp = board->player_1.map.map;
		board->player_1.map.map = sandbox->map;
	}
	else
	{
		tmp = board->player_2.map.map;
		board->player_2.map.map = sandbox->map;
	}
	liberties = ft_get_liberties(board, index_player);
	if (!index_player)
		board->player_1.map.map = tmp;
	else
		board->player_2.map.map = tmp;
	return (liberties);
}
