/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:30:30 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 19:28:23 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE_X 1366
# define WIN_SIZE_Y 766
# define MAX_ITERATION 100

# include <OpenCL/opencl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>

# ifdef cl_khr_fp64
#  pragma OPENCL EXTENSION cl_khr_fp64 : enable
# elif defined(cl_amd_fp64)
#  pragma OPENCL EXTENSION cl_amd_fp64 : enable
# endif

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
	int					win_size_x;
	int					win_size_y;
}						t_mlx;

typedef	struct			s_fract_args
{
	double				zoom;
	double				shift_x;
	double				shift_y;
	int					iterations;
}						t_fract_args;

typedef	struct			s_params
{
	t_cl				cl;
	t_mlx				mlx;
	t_fract_args		args;
}						t_params;

t_cl					cl_init(void);
t_mlx					mlx_params(void);
t_params				init_params(void);
t_params				create_cl_kernel(t_params params);
size_t					read_cl_src(char **src, char *file_name);
t_params				cl_buffer(t_params p);
void					set_cl_args(t_params p);
void					draw(t_params p);
void					push_control(t_params *p);
#endif
