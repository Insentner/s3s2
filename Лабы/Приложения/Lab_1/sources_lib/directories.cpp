#include <head.h>

string sys_dir(void) 
{
	char buffer[MAX_PATH + 1] = "";
	GetSystemDirectory(buffer, sizeof(buffer));
	return string(buffer);
}

string win_dir(void)
{
	char buffer[MAX_PATH + 1] = "";
	GetWindowsDirectory(buffer, sizeof(buffer));
	return string(buffer);
}

string temp_path(void)
{
	char buffer[MAX_PATH + 1] = "";
	GetTempPath(MAX_PATH + 1, buffer);
	return string(buffer);
}