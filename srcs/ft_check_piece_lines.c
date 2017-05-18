/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 06:44:01 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/18 06:53:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int32_t	ft_check_piece_integrity(char *line)
{
	uint32_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

int32_t			ft_check_piece_lines(t_list	*lst, t_piece *piece)
{
	uint32_t	len;
	uint32_t	i;

	i = 0;
	len = piece->len_x;
	while (i < piece->len_y)
	{
		if (ft_strlen(lst->content) != len)
			return (ft_error(1, (char*[]){"Invalid piece line len"}, 0));
		else if (!ft_check_piece_integrity(lst->content))
			return (ft_error(1, (char*[]){"Piece integrity check failed"}, 0));
		lst = lst->next;
		i++;
	}
	return (1);
}

