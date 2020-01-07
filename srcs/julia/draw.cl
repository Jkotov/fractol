__kernel void draw(__global int* pixel, int win_size_x, int win_size_y, int max_iteration, double zoom, double shift_x,
				   double shift_y, double c_x, double c_y)
{
	double	tmp;
	int		gid;
	int		iteration;
	double	x;
	double	y;

	gid = get_global_id(0);
	y = (double)(gid / win_size_x) / zoom - shift_y;
	x = (double)(gid % win_size_x) / zoom - 3.0 / 2 - shift_x;
	iteration = 0;
	while ((x * x + y * y) < 9.0 && iteration < max_iteration)
	{
		tmp = x * x - y * y;
		y = 2 * x * y + c_y;
		x = tmp + c_x;
		iteration++;
	}
	pixel[gid] = iteration * (iteration + 1) / 2 + 0x00aaaa;
	if (iteration == max_iteration)
		pixel[gid] = 0xff;
}