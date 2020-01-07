/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:12:40 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 17:38:46 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr("usage: ./fractol <set>\nsets: mandelbrot, julia,");
	ft_putstr(" multi_julia, burning_ship\n");
	exit(0);
}
