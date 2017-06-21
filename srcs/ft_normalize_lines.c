/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:45:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/20 01:25:19 by sclolus          ###   ########.fr       */
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

void			ft_normalize_lines(t_piece *piece)
{
	uint32_t	i;

	i = 0;
	while (i < piece->len_y)
	{
		if (ft_is_line_empty(piece, i))
		{
			piece->len_y--;
			piece->empty_pos.y++;
			piece->lines += piece->long_nbr;
			i--;
		}
		else
			break ;
		i++;
	}
}
