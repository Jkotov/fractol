/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:58:43 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 22:31:39 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	cl_buffer(t_params p)
{
	int		mem_len;

	mem_len = WIN_SIZE_X * WIN_SIZE_Y;
	p.cl.memobj = clCreateBuffer(p.cl.context, CL_MEM_READ_WRITE,\
			mem_len * sizeof(cl_int), NULL, &p.cl.ret);
	error(p.cl.ret);
	p.cl.ret = clEnqueueWriteBuffer(p.cl.command_queue, p.cl.memobj, CL_TRUE,\
			0, mem_len * sizeof(cl_int), p.mlx.img_data, 0, NULL, NULL);
	error(p.cl.ret);
	p.cl.ret = clSetKernelArg(p.cl.kernel, 0,\
			sizeof(cl_mem), (void *)&p.cl.memobj);
	error(p.cl.ret);
	return (p);
}
