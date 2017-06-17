/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 02:52:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 02:55:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_coord(t_coord coord)
{
	ft_putnbr((int)coord.x); //please fix explicite conversion
	ft_putchar(' ');
	ft_putnbr((int)coord.y);
	ft_putchar('\n');
}
