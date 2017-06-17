/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_to_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 06:49:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/22 02:50:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_put_longs_piece(uint64_t *longs, t_piece *piece)
{
	uint32_t	i;
	uint32_t	u;

	u = 0;
	while (u < piece->len_y)
	{
		i = 0;
		while (i < piece->long_nbr)
		{
			ft_printf("%064b", longs[u * piece->long_nbr + i]);
			i++;
		}
		ft_putendl("");
		u++;
	}
	u = 0;
}

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
	ft_put_longs_piece(longs, piece);
	piece->lines = longs;
	return (1);
}
