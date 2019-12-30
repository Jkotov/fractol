/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cl_kernel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:23:22 by epainter          #+#    #+#             */
/*   Updated: 2019/12/30 22:02:23 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define BUFFSIZE 4096

t_params	create_cl_kernel(t_params params)
{
	size_t	source_size;
	char	*source_str;

	source_size = read_cl_src(&source_str, "srcs/test.cl");
	params.cl.program = clCreateProgramWithSource(params.cl.context, 1,\
	(const char **)&source_str, (const size_t *)&source_size, &params.cl.ret);
	params.cl.ret = clBuildProgram(params.cl.program, 1,\
			&params.cl.device_id, NULL, NULL, NULL);
	params.cl.kernel = clCreateKernel(params.cl.program,\
			"test", &params.cl.ret);
	free(source_str);
	return (params);
}
