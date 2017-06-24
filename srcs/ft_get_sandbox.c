/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sandbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 04:44:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 04:46:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*ft_get_sandbox_map(t_board *board)
{
	static t_map	sandbox;

	if (!sandbox.map)
	{
		if (!(sandbox.map = (uint64_t*)ft_memalloc(board->size_longs
										* sizeof(uint64_t))))
			return (NULL);
		ft_memcpy(&sandbox.len_x, &board->len_x, sizeof(uint32_t) * 4);
	}
	return (&sandbox);
}
