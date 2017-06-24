/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 16:38:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/23 17:08:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_cleanup_map(t_board *board, t_piece *piece)
{
	free(board->player_1.map.map);
	free(piece->lines - (piece->empty_pos.y * piece->long_nbr));
}
