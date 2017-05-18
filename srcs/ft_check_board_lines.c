/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_board_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:17:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/18 01:07:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int32_t	ft_check_index_header(char *line)
{
	uint32_t	i;

	i = 0;
	while (line[i])
	{
		if (i < 4 && line[i] != ' ')
			return (0);
		else if (i > 3 && !ft_isdigit(line[i]) && line[i] != (i - 4) % 10)
			return (0);
		i++;
	}
	return (1);
}

static int32_t	ft_check_board_numbers(char *line, uint32_t index)
{
	uint32_t	i;
	uint32_t	tmp;

	i = 0;
	if (!line)
		return (0);
	if (!index)
		return (ft_check_index_header(line));
	while (i < 3)
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (line[i] != ' ')
		return (0);
	tmp = ft_atoi(line);
	if (index - 1 == tmp)
		return (1);
	return (0);
}

static int32_t	ft_check_line_integrity(char *line)
{
	uint32_t	i;

	i = 4;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != 'x' && line[i] != 'X'
			&& line[i] != 'o' && line[i] != 'O')
			return (0);
		i++;
	}
	return (1);
}

int32_t			ft_check_board_lines(t_list	*lst, t_board *board)
{
	uint32_t	len;
	uint32_t	i;

	i = 0;
	len = board->len_x + 4;
	while (i < board->len_y + 1)
	{
		if (ft_strlen(lst->content) != len)
			return (ft_error(1, (char*[]){"Invalid board line len"}, 0));
		else if (!ft_check_board_numbers(lst->content, i))
			return (ft_error(1, (char*[]){"Invalid line indexes"}, 0));
		else if (i > 0 && !ft_check_line_integrity(lst->content))
			return (ft_error(1, (char*[]){"Line integrity check failed"}, 0));
		lst = lst->next;
		i++;
	}
	return (1);
}
