/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:45:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/19 05:06:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


uint32_t	ft_solve(t_board *board, t_piece *piece)
{
	uint32_t	i;
	uint32_t	size;
	t_coord		pos;
	uint32_t	max_liberties;
	uint32_t	current_distance;
	uint32_t	tmp;
	uint32_t	tmp_distance;

	i = 0;
	size = board->len_x * board->len_y;
	max_liberties = ~0U;
	current_distance = ~0U;
	pos = (t_coord){~0U, ~0U};
	while (i < size)
	{
		if (ft_claim(piece, board, ft_get_pos(i, board)))
		{
//			ft_putchar_fd('$', 2);
			if ((tmp = ft_get_liberties_after_claim(board, piece
			, ft_get_pos(i, board), 0)) < max_liberties
				|| pos.x == ~0U)
			{
				max_liberties = tmp;
				current_distance = ft_get_manhattan_distance(board, 0, pos);
				pos = ft_get_pos(i, board);
			}
			else if (tmp == max_liberties
					&& (tmp_distance = ft_get_manhattan_distance(board, 0, pos))
					 < current_distance)
			{
				max_liberties = tmp;
				current_distance = tmp_distance;
				pos = ft_get_pos(i, board);
			}
		}
		i++;
# if DEBUG == 1
		if (i % board->len_x == 0)
			ft_putchar_fd('\n', 2);
#endif
	}
	ft_print_coord(pos);
	ft_print_coord_err(pos);
	return (1);
}
