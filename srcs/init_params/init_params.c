/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:20:31 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 13:57:49 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_params(char *set)
{
	t_params params;

	params.args.zoom = 300;
	params.args.iterations = MAX_ITERATION;
	params.args.c_x = -0.4;
	params.args.c_y = 0.6;
	params.args.is_locked = 1;
	params.cl = cl_init();
	params.mlx = mlx_params();
	if (ft_strcmp(set, "mandelbrot") == 0)
		params = init_maldelbrot(params);
	if (ft_strcmp(set, "julia") == 0)
		params = init_julia(params);
	params = cl_buffer(params);
	return (params);
}
