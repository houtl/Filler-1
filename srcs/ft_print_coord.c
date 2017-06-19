/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 02:52:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/19 03:57:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_coord(t_coord coord)
{
	ft_putnbr((int)coord.y); //please fix explicite conversion
	ft_putchar(' ');
	ft_putnbr((int)coord.x);
	ft_putchar('\n');
}

void	ft_print_coord_err(t_coord coord)
{
	ft_putnbr_fd((int)coord.y, 2); //please fix explicite conversion
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd((int)coord.x, 2);
	ft_putchar_fd('\n', 2);
}
