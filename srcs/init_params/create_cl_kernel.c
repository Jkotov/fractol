/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cl_kernel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:23:22 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 22:35:07 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define BUFFSIZE 4096

t_params	create_cl_kernel(t_params params)
{
	size_t	source_size;
	char	*source_str;

	source_size = read_cl_src(&source_str, "srcs/draw.cl");
	params.cl.program = clCreateProgramWithSource(params.cl.context, 1,\
	(const char **)&source_str, (const size_t *)&source_size, &params.cl.ret);
	if (params.cl.ret)
		exit(-1);
	params.cl.ret = clBuildProgram(params.cl.program, 1,\
			&params.cl.device_id, NULL, NULL, NULL);
	if (params.cl.ret)
		exit(-1);
	params.cl.kernel = clCreateKernel(params.cl.program,\
			"draw", &params.cl.ret);
	if (params.cl.ret)
		exit(-1);
	free(source_str);
	return (params);
}
