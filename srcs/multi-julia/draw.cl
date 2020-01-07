__kernel void draw(__global int* pixel, int win_size_x, int win_size_y, int max_iteration, double zoom, double shift_x,
				   double shift_y, double color, double c_x, double c_y)
{
	double	tmp_x;
	int		gid;
	int		iteration;
	double	x;
	double	y;
	double	tmp;

	gid = get_global_id(0);
	y = (double)(gid / win_size_x) / zoom - shift_y;
	x = (double)(gid % win_size_x) / zoom - 3.0 / 2 - shift_x;
	iteration = 0;
	while ((x * x + y * y) < 9.0 && iteration < max_iteration)
	{
		tmp = (x * x + y * y) * (x * x + y * y);
		tmp_x = tmp * cos(4 * atan2(y, x)) + c_x;
		y = tmp * sin(4 * atan2(y, x)) + c_y;
		x = tmp_x + c_x;
		iteration++;
	}
	tmp = ((double)iteration / (double)max_iteration) - color;
	tmp = tmp > 0 ? tmp : -tmp;
	pixel[gid] = ((unsigned int)(9.0 * (1.0 - tmp) * tmp * tmp * tmp * 255) << (unsigned)16);
	pixel[gid] = ((unsigned int)(15.0 * (1.0 - tmp) * (1.0 - tmp) * tmp * tmp * 255) << (unsigned)8) | pixel[gid];
	pixel[gid] = (unsigned char)(8.5 * (1.0 - tmp) * (1.0 - tmp) * (1.0 - tmp) * tmp * 255) | pixel[gid];
}