#include <head.h>

int *sys_metrics(int out[])
{
	out[0] = GetSystemMetrics(SM_CXSCREEN);
	out[1] = GetSystemMetrics(SM_CYSCREEN);
	return out;
}