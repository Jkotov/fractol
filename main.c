/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:36:34 by epainter          #+#    #+#             */
/*   Updated: 2019/12/22 21:12:51 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/opencl.h>

int		main()
{
	cl_int	ret;
	cl_platform_id	platform_id;
	cl_uint			ret_num_platforms;
	cl_device_id	device_id;
	cl_uint			ret_num_devices;
	cl_context		context;

	ret = clGetPlatformIDs(2, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	return (0);
}
