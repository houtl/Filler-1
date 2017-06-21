/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_extra_col.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 01:22:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/20 01:50:16 by sclolus          ###   ########.fr       */
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

void		ft_normalize_extra_col(t_piece *piece)
{
	uint32_t	i;
	uint32_t	right_emptyness;

	i = piece->len_x - 1;
	right_emptyness = 0;
	while (42)
	{
		if (ft_is_col_empty(piece, i))
			right_emptyness++;
		else
			break;
		if (i == 0)
			break;
		i--;
	}
	ft_putstr_fd("right_emptyness: ", 2);
	ft_putnbr_fd((int)right_emptyness, 2);
	ft_putchar_fd('\n', 2);
	piece->len_x -= right_emptyness;
}
