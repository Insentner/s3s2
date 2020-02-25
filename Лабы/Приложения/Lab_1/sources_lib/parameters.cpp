#include <head.h>

int *sys_parameters(int mouse_info[])
{
	SystemParametersInfo(SPI_GETMOUSE, 0, mouse_info, 0);
	return mouse_info;
}