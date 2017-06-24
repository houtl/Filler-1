/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_to_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 06:49:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/23 16:55:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

uint32_t		ft_piece_to_long(t_list *lst, t_piece *piece)
{
	uint64_t	*longs;
	uint32_t	i;
	uint32_t	u;
	uint32_t	x;
	uint32_t	size;

	piece->long_nbr = (piece->len_x / (sizeof(uint64_t) * 8))
					+ ((piece->len_x % (sizeof(uint64_t) * 8)) ? 1 : 0);
	size = piece->long_nbr * piece->len_y;
	piece->size_longs = size;
	if (!(longs = (uint64_t *)ft_memalloc(sizeof(uint64_t) * size)))
		return (0);
	u = 0;
	while (lst)
	{
		i = 0;
		while (i < piece->long_nbr)
		{
			x = 0;
			while (x < sizeof(uint64_t) * 8 && ((char*)lst->content)[(i * sizeof(uint64_t) * 8) + x])
			{
				if (((char*)lst->content)[(i * sizeof(uint64_t) * 8) + x] == '*')
					longs[u * piece->long_nbr + i] |= (1UL << ((sizeof(uint64_t) * 8) - 1)) >> x;
				x++;
			}
			i++;
		}
		lst = lst->next;
		u++;
	}
	piece->lines = longs;
	return (1);
}
