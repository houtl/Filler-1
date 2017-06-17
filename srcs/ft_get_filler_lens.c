/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filler_lens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:53:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/01 19:55:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

uint32_t	*ft_get_filler_lens(char *line)
{
	static uint32_t	lens[2];

	while (*line != ' ')
		line++;
	line++;
	if (!ft_isdigit(*line))
	{
		ft_error(1, (char*[]){"Invalid lens format"}, 0);
		return (NULL);
	}
	lens[1] = (uint32_t)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line)
		line++;
	else
	{
		ft_error(1, (char*[]){"Invalid lens format"}, 0);
		return (NULL);
	}
	if (!ft_isdigit(*line))
	{
		ft_error(1, (char*[]){"Invalid lens format"}, 0);
		return (NULL);
	}
	lens[0] = (uint32_t)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (!*line || ft_strcmp(":", line))
	{
		ft_error(1, (char*[]){"Invalid lens format"}, 0);
		return (NULL);
	}
	return (lens);
}
