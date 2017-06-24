/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_to_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 01:29:29 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 06:07:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_assign_t_board_players(uint64_t *longs, t_board *board)
{
	board->player_1.map.map = longs;
	board->player_1.map.size = board->size_longs;
	board->player_1.map.long_nbr = board->long_nbr;
	board->player_1.map.len_x = board->len_x;
	board->player_1.map.len_y = board->len_y;
	board->player_2.map.map = longs + board->size_longs;
	board->player_2.map.size = board->size_longs;
	board->player_2.map.long_nbr = board->long_nbr;
	board->player_2.map.len_x = board->len_x;
	board->player_2.map.len_y = board->len_y;
}

uint32_t		ft_lines_to_long(t_list *lst, t_board *board)
{
	uint64_t	*longs;
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;
	uint32_t	size;

	lst = lst->next;
	board->long_nbr = (board->len_x / 64) + ((board->len_x % 64) ? 1 : 0);
	size = board->long_nbr * board->len_y;
	board->size_longs = size;
	if (!(longs = (uint64_t *)ft_memalloc(sizeof(uint64_t) * size * 2)))
		return (0);
	u = ~0U;
	while (lst && (i = ~0U) == ~0U && (++u || 1))
	{
		while (++i < board->long_nbr && (x = ~0U) == ~0U)
			while (++x < 64 && ((char*)lst->content)[(i * 64) + x + 4])
				if (((char*)lst->content)[(i * 64) + x + 4] == 'O')
					longs[u * board->long_nbr + i] |= (1UL << 63) >> x;
				else if (((char*)lst->content)[(i * 64) + x + 4] == 'X')
					longs[u * board->long_nbr + i + size] |= (1UL << 63) >> x;
		lst = lst->next;
	}
	ft_assign_t_board_players(longs, board);
	return (1);
}
