/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cl_kernel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:23:22 by epainter          #+#    #+#             */
/*   Updated: 2019/12/30 21:28:16 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define BUFFSIZE 4096

t_params	create_cl_kernel(t_params params)
{
	int		fd;
	size_t	source_size;
	char	*source_str;
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFSIZE + 1));
	fd = open("srcs/test.cl", O_RDONLY);
	source_str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[ret] = '\0';
		source_str = ft_strjoinfree(&source_str, &buf, 1);
	}
	free(buf);
	source_size = ft_strlen(source_str);
	buf = NULL;
	params.cl_params.program = clCreateProgramWithSource(\
	params.cl_params.context, 1, (const char **)&source_str,\
					(const size_t *)&source_size, &params.cl_params.ret);
	params.cl_params.ret = clBuildProgram(params.cl_params.program, 1,\
			&params.cl_params.device_id, NULL, NULL, NULL);
	params.cl_params.kernel = clCreateKernel(params.cl_params.program,\
			"test", &params.cl_params.ret);
	return (params);
}
