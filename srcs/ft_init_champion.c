/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:58:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/29 21:35:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


/* static void	ft_put_list(t_list *lst) */
/* { */
/* 	uint32_t	i; */

/* 	i = 0; */
/* 	ft_putendl(""); */
/* 	while (lst) */
/* 	{ */
/* 		ft_putnbr((int)i++); */
/* 		ft_putstr(": "); */
/* 		ft_putendl(lst->content); */
/* 		lst = lst->next; */
/* 	} */
/* } */

/* static int32_t	ft_is_line_champ_stats(char *line) */
/* { */
/* 	uint32_t	len; */
/* 	char		*player_name; */

/* 	if (!line) */
/* 		return (0); */
/* 	len = ft_strlen(line); */
/* 	if ((ft_strncmp(line, PLAYER_SETTING_LINE, PLAYER_SETTING_LINE_LEN))) */
/* 		return (0); */
/* 	if ((player_name = ft_strstr(line, ": [")) */
/*  		&& ft_strstr(player_name + 3, CHAMP_NAME)) */
/* 		return (1); */
/* 	else */
/* 		return (0); */
/* } */

/* static int32_t	ft_fill_champ_stats(char *line, t_champ *champ) */
/* { */
/* 	if (!line) */
/* 		return (-1); */
/* 	if ((line = ft_strchr(line, 'p'))) */
/* 	{ */
/* 		champ->player_number = ft_atoi(line + 1); */
/* 		if (champ->player_number != 1 && champ->player_number != 2) */
/* 		{ */
/* 			champ->player_number = 0; */
/* 			return (ft_error(1, (char*[]){"Invalid player_number"}, -1)); */
/* 		} */
/* 		if ((line = ft_strstr(line, ": [") + 2)) */
/* 		{ */
/* 			if (!(champ->player_name = ft_strdup(CHAMP_NAME))) */
/* 				return (ft_error(1, (char*[]){"Malloc failed"}, -1)); */
/* 			return (0); */
/* 		} */
/* 		return (ft_error(1, (char*[]){"No player_name to be found"}, -1)); */
/* 	} */
/* 	else */
/* 		return (ft_error(1, (char*[]){"Parsing error at player_number"}, -1)); */
/* } */

/* static t_champ	*ft_get_champ(t_list *lines) */
/* { */
/* 	t_champ	*champ; */

/* 	if (!(champ = (t_champ*)ft_memalloc(sizeof(t_champ)))) */
/* 		return (NULL); */
/* 	while (lines) */
/* 	{ */
/* 		if (ft_is_line_champ_stats(lines->content)) */
/* 		{ */
/* 			if (ft_fill_champ_stats(lines->content, champ) == -1) */
/* 			{ */
/* 				ft_free_t_champ(champ); */
/* 				return (NULL); */
/* 			} */
/* 			return (champ); */
/* 		} */
/* 		lines = lines->next; */
/* 	} */
/* 	free(champ); */
/* 	return (NULL); */
/* } */

/* static void	ft_put_champ(t_champ *champ) */
/* { */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr(champ->player_number); */
/* 	ft_putstr(": "); */
/* 	ft_putendl(champ->player_name); */
/* } */

static t_list	*ft_get_header_vm_lines(void)
{
	t_list		*tmp;
	t_list		*lines;
	char		*line;
	uint32_t	i;

	i = 0;
	lines = NULL;
	while (get_next_line(0, &line) > 0 && i < 8)
	{
		i++;
		if (line && *line == '#')
		{
			free(line);
			continue ;
		}
		if (!(tmp = ft_lstnew(0, 0)))
			return (NULL);
		tmp->content = line;
		ft_lst_push_back(&lines, tmp);
	}
	return (lines);
}

static int32_t	ft_exec_launched_statement(char *line, t_champ *champs)
{
	(void)line;
	(void)champs;
	return (1);
}

static int32_t	ft_get_player_stats(char *line, t_champ *champs)
{
	uint32_t	i;
	uint32_t	u;

	i = 0;
	if (champs->player_number != 0)
		i = 1;
	line = line + 9;
	if (*line == 'p')
		line++;
	else
		return (ft_error(1, (char*[]){"Parsing error at player_number"}, 0));
	if (ft_isdigit(*line))
	{
		champs[i].player_number = ft_atoi(line);
		if (champs[i].player_number != 1 && champs[i].player_number != 2)
			return (ft_error(1, (char*[]){"Invalid player_number"}, 0));
	}
	else
		return (ft_error(1, (char*[]){"Invalid player_number"}, 0));
	u = 0;
	while (ft_isdigit(line[u]))
		u++;
	if (ft_strncmp(" : [", line + u, 4))
		return (ft_error(1, (char*[]){"Parsing error at player_name"}, 2));
	line[ft_strlen(line) - 1] = 0;
	if (!(champs[i].player_name = ft_strdup(line + u + 4)))
		return (0);
	return (1);
}

static int32_t			ft_put_init_error(char *line, t_champ *champs)
{
	(void)line;
	(void)champs;
	return (ft_error(2, (char*[]){"Parsing error at: ", line}, 0));
}

int32_t			ft_init_champs(t_list *lines, t_board *board)
{
	static t_init_champs_f		init_f[] = {
		{PLAYER_SETTING_LINE, &ft_get_player_stats},
		{LAUNCHED, &ft_exec_launched_statement},
		{"", &ft_put_init_error}};
	uint32_t					i;

	while (lines)
	{
		i = 0;
		while (i < sizeof(init_f) / sizeof(t_init_champs_f))
		{
			if (!(ft_strncmp(init_f[i].id, lines->content
							, ft_strlen(init_f[i].id))))
			{
				if (!init_f[i].f(lines->content, &board->player_1))
				{
					ft_free_champs(&board->player_1);
					return (0);
				}
				else
					break;
			}
			i++;
		}
		lines = lines->next;
	}
	return (1);
}

int32_t		ft_init_champion(t_board *board)
{
	t_list		*lines;

	if (!(lines = ft_get_header_vm_lines()))
		return (0);
	if (!(ft_init_champs(lines, board)))
	{
		ft_free_lst(lines);
		return (0);
	}
	return (1);
}
