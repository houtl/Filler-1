/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_to_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 01:29:29 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/23 16:38:02 by sclolus          ###   ########.fr       */
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
	board->long_nbr = (board->len_x / (sizeof(uint64_t) * 8))
					+ ((board->len_x % (sizeof(uint64_t) * 8)) ? 1 : 0);
	size = board->long_nbr * board->len_y;
	board->size_longs = size;
	if (!(longs = (uint64_t *)ft_memalloc(sizeof(uint64_t) * size * 2)))
		return (0);
	u = 0;
	while (lst)
	{
		i = 0;
		while (i < board->long_nbr)
		{
			x = 0;
			while (x < sizeof(uint64_t) * 8 && ((char*)lst->content)[(i * sizeof(uint64_t) * 8) + x + 4])
			{
				if (((char*)lst->content)[(i * sizeof(uint64_t) * 8) + x + 4] == 'O')
					longs[u * board->long_nbr + i] |= (1UL << ((sizeof(uint64_t) * 8) - 1)) >> x;
				else if (((char*)lst->content)[(i * sizeof(uint64_t) * 8) + x + 4] == 'X')
					longs[u * board->long_nbr + i + size] |= (1UL << ((sizeof(uint64_t) * 8) - 1)) >> x;
				x++;
			}
			i++;
		}
		lst = lst->next;
		u++;
	}
	ft_assign_t_board_players(longs, board);
	return (1);
}
