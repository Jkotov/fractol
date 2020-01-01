__kernel void draw(__global int* pixel, int win_size_x, int win_size_y, int max_iteration)
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
	y0 = (2 * (double)((int)gid / (int)win_size_x) / (double)win_size_y) - 1;
	x0 = (3.5 * (double)((int)gid % (int)win_size_x) / (double)win_size_x) - 2.5;
	iteration = 0;
	while ((x * x + y * y) <= 2.0 && iteration < max_iteration)
	{
		tmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmp;
		iteration++;
	}
	if (iteration == max_iteration)
		pixel[gid] = 0x0ff;
	else
		pixel[gid] = 0xffff;
}
