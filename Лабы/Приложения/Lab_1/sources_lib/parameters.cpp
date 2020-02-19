#include <head.h>

int *sys_parameters(int aMouseInfo[])
{
        
	SystemParametersInfo(SPI_GETMOUSE, 0, aMouseInfo, 0);
	return aMouseInfo;
}