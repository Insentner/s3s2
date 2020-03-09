#include <head.h>

int *display_metrics(int out[])
{
	out[0] = GetSystemMetrics(SM_CXSCREEN);
	out[1] = GetSystemMetrics(SM_CYSCREEN);
	return 0;
}