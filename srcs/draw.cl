__kernel void draw(__global int* pixel, int win_size_x, int win_size_y, int max_iteration, float zoom, float shift_x, float shift_y)
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
	y0 = (double)(gid / win_size_x) / (double)zoom - (double)shift_y;
	x0 = (double)(gid % win_size_x) / (double)zoom - (double)shift_x;
	iteration = 0;
	while ((x * x + y * y) <= 4.0 && iteration < max_iteration)
	{
		tmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmp;
		iteration++;
	}
	pixel[gid] = iteration * (iteration + 1) / 2 + 15000;
}
