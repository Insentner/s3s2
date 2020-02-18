#include <head.h>

string sys_metrics(void)
{
	return string("%d", GetSystemMetrics(SM_CXSCREEN));
}