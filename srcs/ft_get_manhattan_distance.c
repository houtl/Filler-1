/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_manhattan_distance.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 04:15:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 04:50:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

uint32_t	ft_get_manhattan_distance(t_coord pos_1
									, t_coord pos_2)
{
	return ((uint32_t)ft_distance(pos_1.x, pos_2.x)
			+ (uint32_t)ft_distance(pos_2.y, pos_1.y));
}
