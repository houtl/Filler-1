/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:56:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 04:25:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

uint32_t	ft_get_index(uint32_t y, uint32_t x, t_board *board);
uint32_t	ft_get_index(uint32_t y, uint32_t x, t_board *board)
{
	ft_printf("index: %u\n", board->len_y * y + x);
	return (board->len_y * y + x);
}

int	main(void)
{
	static t_board	board;
	static t_piece	piece;

	if (!(ft_init_champion(&board)))
		return (EXIT_FAILURE);
	if (!ft_get_board_stats(&board))
		return (EXIT_FAILURE);
	if (!(ft_get_piece_stats(&piece)))
		return (EXIT_FAILURE);
	ft_putnbr((int)ft_get_liberties(&board, 1));
	ft_solve(&board, &piece);
	return (0);
}
