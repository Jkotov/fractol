/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maldelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:03:03 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 21:03:03 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_maldelbrot(t_params params)
{
	params.args.shift_x = 2.5;
	params.args.shift_y = 1;
	params.fractal_type = "mandelbrot";
	params = create_cl_kernel(params, "srcs/mandelbrot/draw.cl");
	error(params.cl.ret);
	return (params);
}
