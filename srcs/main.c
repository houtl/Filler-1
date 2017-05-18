/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:56:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/18 06:59:17 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_champ	*champ;
	t_board	*board;
	t_piece	*piece;

	if (!(board = (t_board*)ft_memalloc(sizeof(t_board))))
		return (EXIT_FAILURE);
	if (!(champ = ft_init_champion()))
		return (EXIT_FAILURE);
	ft_get_board_stats(board);
	if (!(piece = ft_get_piece()))
		return (EXIT_FAILURE);
	if (!(ft_get_piece_stats(piece)))
		return (EXIT_FAILURE);
	return (0);
}
