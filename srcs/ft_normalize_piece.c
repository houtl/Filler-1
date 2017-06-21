/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:26:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/20 01:49:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			ft_putnbr_bin(uint64_t nbr)
{
	if (nbr > 1)
	{
		ft_putnbr_bin(nbr / 2);
		ft_putnbr_bin(nbr % 2);
	}
	else
		ft_putchar_fd((char)nbr + '0', 2);
}

static void			ft_print_piece(t_piece *piece)
{
	uint32_t	i;
	uint32_t	u;

	i = 0;
	while (i < piece->len_y)
	{
		u = 0;
		while (u < piece->long_nbr)
		{
//			ft_printf("%64b", piece->lines[i * piece->long_nbr + u]);
			ft_putnbr_bin(piece->lines[i * piece->long_nbr + u]);
			u++;
		}
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void			ft_normalize_piece(t_piece *piece)
{
	ft_bzero(&piece->empty_pos, sizeof(t_coord));
	ft_normalize_lines(piece);
	ft_normalize_col(piece);
	ft_normalize_extra_lines(piece);
	ft_normalize_extra_col(piece);
	ft_print_piece(piece);
	ft_putstr_fd("\ny: ", 2);
	ft_putnbr_fd((int)piece->len_y, 2);
	ft_putstr_fd("\nx: ", 2);
	ft_putnbr_fd((int)piece->len_x, 2);
	ft_putchar_fd('\n', 2);
}
