
#if defined(cl_khr_fp64)  // Khronos extension available?
#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#define DOUBLE_SUPPORT_AVAILABLE
#elif defined(cl_amd_fp64)  // AMD extension available?
#pragma OPENCL EXTENSION cl_amd_fp64 : enable
#define DOUBLE_SUPPORT_AVAILABLE
#endif
__kernel void draw(__global int* pixel, int win_size_x, int win_size_y, int max_iteration, double zoom, double shift_x,
				   double shift_y, double color)
{
	double	x0;
	double	y0;
	double	tmp;
	int		gid;
	int		iteration;
	double	x;
	double	y;

	x = 0;
	y = 0;
	gid = get_global_id(0);
	y0 = (double)(gid / win_size_x) / zoom - shift_y;
	x0 = (double)(gid % win_size_x) / zoom - shift_x;
	iteration = 0;
	while ((x * x + y * y) <= 4.0 && iteration < max_iteration)
	{
		tmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmp;
		iteration++;
	}
	tmp = ((double)iteration / (double)max_iteration) - color;
	tmp = tmp > 0 ? tmp : -tmp;
	pixel[gid] = ((unsigned int)(9.0 * (1.0 - tmp) * tmp * tmp * tmp * 255) << (unsigned)16);
	pixel[gid] = ((unsigned int)(15.0 * (1.0 - tmp) * (1.0 - tmp) * tmp * tmp * 255) << (unsigned)8) | pixel[gid];
	pixel[gid] = (unsigned char)(8.5 * (1.0 - tmp) * (1.0 - tmp) * (1.0 - tmp) * tmp * 255) | pixel[gid];
}
