/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:20:31 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 21:02:58 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_params(char *set)
{
	t_params params;

	params.args.zoom = 300;
	params.args.iterations = MAX_ITERATION;
	params.cl = cl_init();
	params.mlx = mlx_params();
	if (ft_strcmp(set, "mandelbrot") == 0)
		params = init_maldelbrot(params);
	params = cl_buffer(params);
	return (params);
}
