#include <head.h>

unsigned long sys_colors(void)
{
	return GetSysColor(COLOR_WINDOWFRAME);
}