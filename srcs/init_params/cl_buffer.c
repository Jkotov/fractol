/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:58:43 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 20:07:39 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	cl_buffer(t_params p)
{
	int		mem_len;
	size_t	global_work_size[1];

	mem_len = WIN_SIZE_X * WIN_SIZE_Y;
	*global_work_size = WIN_SIZE_X * WIN_SIZE_Y;
	p.cl.memobj = clCreateBuffer(p.cl.context, CL_MEM_READ_WRITE,\
			mem_len * sizeof(cl_int), NULL, &p.cl.ret);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clEnqueueWriteBuffer(p.cl.command_queue, p.cl.memobj, CL_TRUE,\
			0, mem_len * sizeof(cl_int), p.mlx.img_data, 0, NULL, NULL);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 0,\
			sizeof(cl_mem), (void *)&p.cl.memobj);
	if (p.cl.ret)
		exit(-1);
	p.cl.ret = clEnqueueNDRangeKernel(p.cl.command_queue, p.cl.kernel, 1,\
			NULL, global_work_size, NULL, 0, NULL, NULL);
	p.cl.ret = clEnqueueReadBuffer(p.cl.command_queue, p.cl.memobj,\
			CL_TRUE, 0, mem_len * sizeof(int), p.mlx.img_data, 0, NULL, NULL);
	return (p);
}
