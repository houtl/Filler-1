/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:58:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 04:52:22 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int32_t			ft_get_player_stats(char *line, t_board *board)
{
	uint32_t	i;
	uint32_t	u;

	i = 0;
	line = line + 9;
	if (*line == 'p')
		line++;
	else
		return (ft_error(1, (char*[]){"Parsing error at player_number"}, 0));
	if (ft_isdigit(*line))
	{
		board->player_index = (uint32_t)ft_atoi(line) - 1;
		if (board->player_index != 0 && board->player_index != 1)
			return (ft_error(1, (char*[]){"Invalid player_number"}, 0));
	}
	else
		return (ft_error(1, (char*[]){"Invalid player_number"}, 0));
	u = 0;
	while (ft_isdigit(line[u]))
		u++;
	if (ft_strncmp(" : [", line + u, 4))
		return (ft_error(1, (char*[]){"Parsing error at player_name"}, 2));
	return (1);
}

static int32_t			ft_put_init_error(char *line, t_board *board)
{
	(void)line;
	(void)board;
	return (ft_error(2, (char*[]){"Parsing error at: ", line}, 0));
}

int32_t					ft_init_champs(char *line, t_board *board)
{
	static t_init_champs_f		init_f[] = {
		{PLAYER_SETTING_LINE, &ft_get_player_stats},
		{"", &ft_put_init_error}};
	uint32_t					i;

	i = 0;
	while (i < sizeof(init_f) / sizeof(t_init_champs_f))
	{
		if (!(ft_strncmp(init_f[i].id, line
						, ft_strlen(init_f[i].id))))
		{
			if (!init_f[i].f(line, board))
			{
				ft_free_champs(&board->player_1);
				return (0);
			}
			else
				break ;
		}
		i++;
	}
	return (1);
}

static void				ft_free_header_line(char **line)
{
	free(*line);
}

int32_t					ft_init_champion(t_board *board)
{
	char	*line __attribute__((cleanup(ft_free_header_line)));

	line = NULL;
	if (get_next_line(0, &line) == -1)
		return (ft_error(1, (char*[]){"Get_next_line() failed"}, -1));
	if (!(ft_init_champs(line, board)))
		return (0);
	return (1);
}
