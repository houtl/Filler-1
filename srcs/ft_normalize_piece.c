/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:26:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/23 17:00:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_normalize_piece(t_piece *piece)
{
	ft_bzero(&piece->empty_pos, sizeof(t_coord));
	ft_normalize_lines(piece);
	ft_normalize_col(piece);
	ft_normalize_extra_lines(piece);
	ft_normalize_extra_col(piece);
}
