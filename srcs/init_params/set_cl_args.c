/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cl_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:27:11 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 16:40:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	set_julia_args(t_params p)
{
	p.cl.ret = clSetKernelArg(p.cl.kernel, 8, sizeof(p.args.c_x),\
				&p.args.c_x);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 9, sizeof(p.args.c_y),\
				&p.args.c_y);
	error(p.cl.ret);
}

void			set_cl_args(t_params p)
{
	p.cl.ret = clSetKernelArg(p.cl.kernel, 1, sizeof(int), &p.mlx.win_size_x);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 2, sizeof(int), &p.mlx.win_size_y);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 3, sizeof(int), &p.args.iterations);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 4, sizeof(p.args.zoom),\
			&p.args.zoom);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 5, sizeof(p.args.shift_x),\
			&p.args.shift_x);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 6, sizeof(p.args.shift_y),\
			&p.args.shift_y);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 7, sizeof(p.args.color),\
			&p.args.color);
	error(p.cl.ret);
	if (ft_strcmp(p.fractal_type, "julia") == 0)
		set_julia_args(p);
}
