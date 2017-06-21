/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_extra_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 01:21:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/21 03:11:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int32_t	ft_is_line_empty(t_piece *piece, uint32_t index)
{
	uint32_t	i;

	i = 0;
	while (i < piece->long_nbr)
	{
		if (piece->lines[index * piece->long_nbr + i])
			return (0);
		i++;
	}
	return (1);
}

void			ft_normalize_extra_lines(t_piece *piece)
{
	uint32_t	i;

	i = piece->len_y - 1;
	while (42)
	{
		if (ft_is_line_empty(piece, i))
			piece->len_y--;
		else
			break ;
		if (i == 0)
			break ;
		i--;
	}
}
