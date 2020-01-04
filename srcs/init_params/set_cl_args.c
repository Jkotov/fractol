/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cl_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:27:11 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 16:32:32 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_cl_args(t_params p)
{
	int win_size_x;
	int win_size_y;
	float zoom = (float)p.args.zoom;
	float shift_x = (float)p.args.shift_x;
	float shift_y = (float)p.args.shift_y;

	win_size_x = WIN_SIZE_X;
	win_size_y = WIN_SIZE_Y;
	p.cl.ret = clSetKernelArg(p.cl.kernel, 1, sizeof(int), &win_size_x);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 2, sizeof(int), &win_size_y);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 3, sizeof(int), &p.args.iterations);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 4, sizeof(zoom),\
			&zoom);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 5, sizeof(shift_x),\
			&shift_x);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 6, sizeof(shift_y),\
			&shift_y);
	if (p.cl.ret)
		exit(-1);
}
