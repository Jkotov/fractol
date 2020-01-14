/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:06:02 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 18:35:26 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_params p)
{
	int		mem_len;
	size_t	global_work_size;

	mem_len = WIN_SIZE_X * WIN_SIZE_Y;
	global_work_size = WIN_SIZE_X * WIN_SIZE_Y;
	set_cl_args(p);
	p.cl.ret = clEnqueueNDRangeKernel(p.cl.command_queue, p.cl.kernel, 1,\
			NULL, &global_work_size, NULL, 0, NULL, NULL);
	error(p.cl.ret);
	p.cl.ret = clEnqueueReadBuffer(p.cl.command_queue, p.cl.memobj,\
			CL_TRUE, 0, mem_len * sizeof(int), p.mlx.img_data, 0, NULL, NULL);
	error(p.cl.ret);
	mlx_put_image_to_window(p.mlx.mlx,\
			p.mlx.window, p.mlx.img, 0, 0);
}
