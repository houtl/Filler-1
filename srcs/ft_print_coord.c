/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 02:52:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/21 05:51:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_coord(t_coord coord, t_piece *piece)
{
	ft_putnbr((int)coord.y - (int)piece->empty_pos.y); //please fix explicite conversion
	ft_putchar(' ');
	ft_putnbr((int)coord.x - (int)piece->empty_pos.x); //please fix explicite conversion);
	ft_putchar('\n');
}

void	ft_print_coord_err(t_coord coord, t_piece *piece)
{
	ft_putnbr_fd((int)coord.y - (int)piece->empty_pos.y, 2); //please fix explicite conversion
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd((int)coord.x - (int)piece->empty_pos.x, 2);
	ft_putchar_fd('\n', 2);
}
