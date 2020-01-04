/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cl_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:27:11 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 19:20:04 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_cl_args(t_params p)
{
	p.cl.ret = clSetKernelArg(p.cl.kernel, 1, sizeof(int), &p.mlx.win_size_x);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 2, sizeof(int), &p.mlx.win_size_y);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 3, sizeof(int), &p.args.iterations);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 4, sizeof(p.args.zoom),\
			&p.args.zoom);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 5, sizeof(p.args.shift_x),\
			&p.args.shift_x);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 6, sizeof(p.args.shift_y),\
			&p.args.shift_y);
	if (p.cl.ret)
		exit(-1);
}
