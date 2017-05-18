/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 06:41:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/18 06:42:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece	*ft_get_piece(void)
{
	t_piece	*piece;

	if (!(piece = ft_memalloc(sizeof(t_piece))))
		return (NULL);
	return (piece);
}
