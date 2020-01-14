/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cl_kernel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:23:22 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 20:35:43 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#define BUFFSIZE 4096

t_params	create_cl_kernel(t_params params, char *file_name)
{
	size_t	source_size;
	char	*source_str;

	source_size = read_cl_src(&source_str, file_name);
	params.cl.program = clCreateProgramWithSource(params.cl.context, 1,\
	(const char **)&source_str, (const size_t *)&source_size, &params.cl.ret);
	error(params.cl.ret);
	params.cl.ret = clBuildProgram(params.cl.program, 1,\
			&params.cl.device_id, NULL, NULL, NULL);
	// Determine the size of the log
	size_t log_size;
	clGetProgramBuildInfo(params.cl.program, params.cl.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

	// Allocate memory for the log
	char *log = (char *) malloc(log_size);

	// Get the log
	clGetProgramBuildInfo(params.cl.program, params.cl.device_id, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

	// Print the log
	printf("%s\n", log);
	error(params.cl.ret);
	params.cl.kernel = clCreateKernel(params.cl.program,\
			"draw", &params.cl.ret);
	error(params.cl.ret);
	free(source_str);
	return (params);
}
