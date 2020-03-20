#include <head.h>

double works_time(void)
{
	return GetTickCount()/(double)3600000;
}

string drive_type(void)
{
	int d = GetDriveTypeA("C:\\");
	if (d == DRIVE_UNKNOWN) return "UNKNOWN";
	if (d == DRIVE_NO_ROOT_DIR) return "DRIVE NO ROOT DIR";
	if (d == DRIVE_REMOVABLE) return "REMOVABLE";
	if (d == DRIVE_FIXED) return " FIXED";
	if (d == DRIVE_REMOTE) return "REMOTE";
	if (d == DRIVE_CDROM) return "CDROM";
	if (d == DRIVE_RAMDISK) return "RAMDISK";
	return 0;
}
