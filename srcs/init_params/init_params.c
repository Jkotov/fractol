/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:20:31 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 20:03:56 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_params(void)
{
	t_params params;

	params.args.zoom = 1;
	params.args.shift_x = 0;
	params.args.shift_y = 0;
	params.cl = cl_init();
	params.mlx = mlx_params();
	params = create_cl_kernel(params);
	params = cl_buffer(params);
	return (params);
}
