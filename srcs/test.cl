#include <stdio.h>

__kernel void test(__global int* message)
{
	// получаем текущий id.
	int gid = get_global_id(0);

	message[gid] += gid;
	printf("hi");
}
