/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 01:15:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/18 03:58:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_board(t_board *board)
{
	uint32_t	i;

	i = 0;
	while (board->lines[i])
		free(board->lines[i++]);
	free(board->lines);
	free(board);
}
