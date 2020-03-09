#include <head.h>

int *mouse_parameters(int mouse_info[])
{
	SystemParametersInfo(SPI_GETMOUSE, 0, mouse_info, 0);
	return 0;
}