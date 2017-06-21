/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:46:48 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/20 01:02:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int32_t	ft_is_col_empty(t_piece *piece, uint32_t index)
{
	uint32_t	i;

	i = 0;
	while (i < piece->len_y)
	{
		if (((piece->lines[i * piece->long_nbr] >> (63 - index)) & 1))
			return (0);
		i++;
	}
	return (1);
}

static void		ft_col_shift(t_piece *piece, uint32_t left_emptyness)
{
	uint64_t	tmp;
	uint32_t	i;
	uint32_t	u;

	i = 0;
	while (left_emptyness > 63)
	{
		ft_col_shift(piece, 63);
		left_emptyness -= 63;
	}
	while (i < piece->len_y)
	{
		u = 0;
		while (u < piece->long_nbr)
		{
			tmp = piece->lines[i * piece->long_nbr + u] << left_emptyness;
			if (u < piece->long_nbr - 1)
				tmp |= piece->lines[i * piece->long_nbr + u + 1] >> (63 - left_emptyness);
			piece->lines[i * piece->long_nbr + u] = tmp;
			u++;
		}
		i++;
	}
}

void		ft_normalize_col(t_piece *piece)
{
	uint32_t	i;
	uint32_t	left_emptyness;

	i = 0;
	left_emptyness = 0;
	while (i < piece->len_x)
	{
		if (ft_is_col_empty(piece, i))
		{
			piece->len_x--;
			left_emptyness++;
		}
		else
			break;
		i++;
	}
	ft_putstr_fd("Left_emptyness: ", 2);
	ft_putnbr_fd((int)left_emptyness, 2);
	ft_putchar_fd('\n', 2);
	piece->empty_pos.x = left_emptyness;
	ft_col_shift(piece, left_emptyness);
}
