/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 05:49:17 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/20 00:26:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_clean_line_piece(char **line_piece)
{
	free(*line_piece);
}

static int32_t	ft_get_piece_lens(t_piece *piece)
{
	char		*line_piece __attribute__ ((cleanup(ft_clean_line_piece)));
	uint32_t	*lens;

	if (get_next_line(0, &line_piece) > 0)
	{
		if (ft_strnequ(line_piece, PIECE_HEADER, PIECE_HEADER_LEN))
		{
			#if DEBUG == 1
			ft_putendl_fd(line_piece, 2);
#endif
			lens = ft_get_filler_lens(line_piece);
			if (!lens || !(ft_memcpy(&piece->len_x, lens, sizeof(uint32_t) * 2)))
				return (-1);
		}
		else
			return (ft_error(1, (char*[]){INVALID_PIECE_HEADER}, -1));
	}
	else
		return (ft_error(1, (char*[]){INVALID_PIECE_LINE}, -1));
	return (0);
}

static t_list	*ft_get_playing_piece_lines(t_piece *piece)
{
	t_list		*lst;
	t_list		*tmp;
	char		*line;
	uint32_t	i;

	i = 0;
	lst = NULL;
	while (i < piece->len_y && get_next_line(0, &line) > 0)
	{
		if (!(tmp = ft_lstnew(0, 0)))
		{
			free(line);
			ft_free_lst(lst);
			ft_error(1, (char*[]){"Malloc failed at ft_get_playing_piece_lines()"}, 0);
			return (NULL);
		}
		tmp->content = line;
		ft_lst_push_back(&lst, tmp);
		i++;
	}
	if (i != piece->len_y)
	{
		ft_free_lst(lst);
		ft_error(1, (char*[]){"Invalid line number"}, 0);
		return (NULL);
	}
	return (lst);
}

# if DEBUG == 1
static void	ft_put_lst(t_list *lst)
{
	while (lst)
	{
		ft_putchar_fd('-', 2);
		ft_putendl_fd(lst->content, 2);
		lst = lst->next;
	}
}

#endif

uint32_t	ft_get_piece_stats(t_piece *piece)
{
	t_list	*lst;

	if (ft_get_piece_lens(piece) == -1)
		return (0);
	if (!(lst = ft_get_playing_piece_lines(piece)))
		return (0);
	if (!ft_check_piece_lines(lst, piece))
	{
		ft_free_lst(lst);
		ft_free_piece(piece);
		ft_error(1, (char*[]){"Parsing error on piece"}, 0);
		return (0);
	}
	# if DEBUG == 1
	ft_put_lst(lst);
#endif
	ft_piece_to_long(lst, piece);
	ft_normalize_piece(piece);
	return (1);
}
