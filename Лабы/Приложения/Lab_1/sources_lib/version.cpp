#include <head.h>

 unsigned long os_version()
{
	OSVERSIONINFO ver;
	ZeroMemory(&ver, sizeof(OSVERSIONINFO));
	ver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx((OSVERSIONINFO*)&ver);
	return ver.dwMinorVersion;
}