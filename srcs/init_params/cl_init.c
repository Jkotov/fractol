/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:29:16 by epainter          #+#    #+#             */
/*   Updated: 2020/01/02 15:49:45 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cl	cl_init(void)
{
	t_cl			cl_param;

	cl_param.ret = clGetPlatformIDs(2, &cl_param.platform_id,\
	&cl_param.ret_num_platforms);
	error(cl_param.ret);
	cl_param.ret = clGetDeviceIDs(cl_param.platform_id, CL_DEVICE_TYPE_GPU,\
	1, &cl_param.device_id, &cl_param.ret_num_devices);
	error(cl_param.ret);
	cl_param.context = clCreateContext(NULL, 1, &cl_param.device_id,\
	NULL, NULL, &cl_param.ret);
	error(cl_param.ret);
	cl_param.command_queue = clCreateCommandQueue(cl_param.context,\
	cl_param.device_id, 0, &cl_param.ret);
	error(cl_param.ret);
	return (cl_param);
}
