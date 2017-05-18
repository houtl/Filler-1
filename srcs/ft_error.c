/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 01:07:10 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/13 01:08:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int32_t	ft_error(uint32_t n, char **str, int32_t return_status)
{
	uint32_t	i;

	i = 0;
	ft_putstr_fd(FILLER_NAME, 2);
	while (i < n)
	{
		ft_putstr_fd(str[i], 2);
		i++;
	}
	ft_putstr_fd("\n", 2);
	return (return_status);
}
