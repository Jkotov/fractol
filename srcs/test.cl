__kernel void test(__global int* message)
{
	int gid = get_global_id(0);

	if (gid & 1)
		message[gid] = 0xffffff;
	else
		message[gid] = 0xff;
}
