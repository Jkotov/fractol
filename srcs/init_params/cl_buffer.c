/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:58:43 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 18:23:34 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cl	cl_buffer(t_cl cl)
{
	cl_int	*mem;
	int		mem_len;
	size_t	global_work_size[1];

	mem_len = 10;
	*global_work_size = 10;
	if ((mem = (cl_int *)malloc(sizeof(cl_int) * mem_len)) == NULL)
		exit(-1);
	cl.memobj = clCreateBuffer(cl.context, CL_MEM_READ_WRITE,\
			mem_len * sizeof(cl_int), NULL, &cl.ret);
	if (cl.ret)
		exit(-1);
	cl.ret = clEnqueueWriteBuffer(cl.command_queue, cl.memobj, CL_TRUE, 0,\
			mem_len * sizeof(cl_int), mem, 0, NULL, NULL);
	if (cl.ret)
		exit(-1);
	cl.ret = clSetKernelArg(cl.kernel, 0, sizeof(cl_mem), (void *)&cl.memobj);
	if (cl.ret)
		exit(-1);
	cl.ret = clEnqueueNDRangeKernel(cl.command_queue, cl.kernel, 1,\
			NULL, global_work_size, NULL, 0, NULL, NULL);
	return (cl);
}
