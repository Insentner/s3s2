#include <head.h>

int local_time(SYSTEMTIME *sys_time)
{
	ZeroMemory(sys_time, sizeof(SYSTEMTIME));
	GetLocalTime((SYSTEMTIME*)sys_time);
	return 0;
}