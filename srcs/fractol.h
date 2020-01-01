/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:30:30 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 20:07:39 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE_X 1366
# define WIN_SIZE_Y 768

# include <OpenCL/opencl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>

typedef	struct			s_cl
{
	cl_int				ret;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	command_queue;
	cl_mem				memobj;

}						t_cl;

typedef	struct			s_mlx
{
	void				*window;
	void				*mlx;
	void				*img;
	int					*img_data;
}						t_mlx;

typedef	struct			s_params
{
	t_cl				cl;
	t_mlx				mlx;
}						t_params;

t_cl					cl_init(void);
t_mlx					mlx_params(void);
t_params				init_params(void);
t_params				create_cl_kernel(t_params params);
size_t					read_cl_src(char **src, char *file_name);
t_params				cl_buffer(t_params p);
#endif
