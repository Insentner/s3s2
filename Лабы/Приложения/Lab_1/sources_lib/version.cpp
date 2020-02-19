#include <head.h>

const char *os_version_1(void)
{
	if (IsWindows8Point1OrGreater())
	{
		return "8.1";
	}
	if (IsWindows8OrGreater())
	{
		return "8";
	}
	if (IsWindows7OrGreater())
	{
		return "7";
	}
	if (IsWindowsVistaOrGreater())
	{
		return "Vista";
	}
	if (IsWindowsXPOrGreater())
	{
		return "XP";
	}
	return "Unknown";
}

OSVERSIONINFO os_version_0(void)
{
	OSVERSIONINFO ver;
	ZeroMemory(&ver, sizeof(OSVERSIONINFO));
	ver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx((OSVERSIONINFO*)&ver);
	return ver;
}