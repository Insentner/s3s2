#include <head.h>

string pc_name(void) 
{
	char buffer[MAX_COMPUTERNAME_LENGTH + 1] = "";
	unsigned long buffer_len = MAX_COMPUTERNAME_LENGTH + 1;
	GetComputerName(buffer, &buffer_len);
	return string(buffer);
}

string user_name(void)
{
	char buffer[UNLEN + 1] = "";
	unsigned long buffer_len = UNLEN + 1;
	GetUserName(buffer, &buffer_len);
	return string(buffer);
}