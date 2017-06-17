/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sand_box_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 03:31:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/22 04:42:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long	*ft_get_sandbox_map(t_board *board)
{
	static long	*sandbox = NULL;

	if (!sandbox)
		if (!(sandbox = (long*)ft_memalloc(board->size_longs)))
			return (NULL);
	return (sandbox);
}
