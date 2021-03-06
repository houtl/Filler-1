/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 01:41:08 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 04:34:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_clean_line_board(char **line_board)
{
	free(*line_board);
}

static int32_t	ft_get_board_lens(t_board *board)
{
	char		*line_board __attribute__((cleanup(ft_clean_line_board)));
	uint32_t	*lens;
	int32_t		ret;

	if ((ret = get_next_line(0, &line_board)) == -1)
		return (-1);
	if (ft_strnequ(line_board, MAP_LENS_HEADER, MAP_LENS_HEADER_LEN))
	{
		lens = ft_get_filler_lens(line_board);
		if (!lens || !(ft_memcpy(board, lens, sizeof(uint32_t) * 2)))
			return (-1);
	}
	else
		return (ft_error(1, (char*[]){INVALID_MAP_HEADER}, -1));
	return (0);
}

static t_list	*ft_get_playing_board_lines(t_board *board)
{
	t_list		*lst;
	t_list		*tmp;
	char		*line;
	uint32_t	i;

	i = ~0U;
	lst = NULL;
	while (++i < board->len_y + 1 && get_next_line(0, &line) > 0)
	{
		if (!(tmp = ft_lstnew(0, 0)) && !ft_error(1, (char*[]){ALLOC_LINES}, 0))
		{
			free(line);
			ft_free_lst(lst);
			return (NULL);
		}
		tmp->content = line;
		ft_lst_push_back(&lst, tmp);
	}
	if (i != board->len_y + 1)
	{
		ft_free_lst(lst);
		ft_error(1, (char*[]){"Invalid line number"}, 0);
		return (NULL);
	}
	return (lst);
}

int32_t			ft_get_board_stats(t_board *board)
{
	t_list	*lst;

	if (ft_get_board_lens(board) == -1)
		return (0);
	if (!(lst = ft_get_playing_board_lines(board)))
		return (0);
	if (!ft_check_board_lines(lst, board))
	{
		ft_free_lst(lst);
		ft_free_board(board);
		ft_error(1, (char*[]){"Parsing error on board"}, 0);
		return (0);
	}
	ft_lines_to_long(lst, board);
	ft_free_lst(lst);
	return (1);
}
