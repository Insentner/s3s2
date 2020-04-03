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

int os_version_0(OSVERSIONINFO *ver)
{
	ZeroMemory(ver, sizeof(OSVERSIONINFO));
	ver->dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx((OSVERSIONINFO*)ver);
	return 0;
}

//LPOSVERSIONINFOEXA *os_version_0(void)
//{
//	LPOSVERSIONINFOEXA ver;
//	ZeroMemory(&ver, sizeof(LPOSVERSIONINFOEXA));
//	VerifyVersionInfoA(ver, VER_MAJORVERSION, https://docs.microsoft.com/ru-ru/windows/win32/api/winnt/nf-winnt-versetconditionmask);
//	return &ver;
//}