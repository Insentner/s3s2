#include <head.h>
void main(void)
{
	do
	{
		cout << "Select one of the following tasks:\n1 - system names\n2 - system directories\n3 - OS version\n4 - screen resolution\n5 - mouse somethings\n6 - system color\n7 - system times\n8 - custom\n9 - exit" << endl;
		switch (_getch())
		{
		case'1':
			system("cls");
			cout << "My name is " << pc_name() << endl;
			cout << "Your name is " << user_name() << endl;
			break;
		case'2':
			system("cls");
			cout << "My System32 directory is " << sys_dir() << endl;
			cout << "My Windows directory is " << win_dir() << endl;
			cout << "My Temp directory is " << temp_path() << endl;
			break;
		case'3':
		{
			system("cls");
			OSVERSIONINFO ver;
			cout << "My Windows under " << os_version_1() << endl;
			os_version_0(&ver);
			cout << "My Windows version is " << ver.dwMajorVersion << "." << ver.dwMinorVersion << "." << ver.dwBuildNumber << endl;
			break;
		}
		case'4':
		{
			system("cls");
			int out[3];
			display_metrics(out);
			cout << "My screen is " << out[0] << "x" << out[1] << endl;
			break;
		}
		case'5':
		{
			system("cls");
			int out[3];
			mouse_parameters(out);
			cout << "My mouse X is " << out[0] << endl;
			cout << "My mouse Y is " << out[1] << endl;
			cout << "My mouse acceleration is " << out[2] << endl;
			break;
		}
		case'6':
			system("cls");
			cout << "My background color is " << sys_colors() << endl;
			break;
		case'7':
		{	
			system("cls");
			SYSTEMTIME sys_time;
			local_time(&sys_time);
			cout << "My date is " << setfill('0') << setw(2) << sys_time.wDay << "." << setfill('0') << setw(2) << sys_time.wMonth << "." << sys_time.wYear << endl;
			cout << "My time is " << setfill('0') << setw(2) << sys_time.wHour << ":" << setfill('0') << setw(2) << sys_time.wMinute << ":" << setfill('0') << setw(2) << sys_time.wSecond << endl;
			break;
		}
		case'8':
		{
			system("cls");
			SYSTEM_INFO sys_info;
			_MEMORYSTATUSEX mem_info;
			GetSystemInfo(&sys_info);
			mem_info.dwLength = sizeof(_MEMORYSTATUSEX);
			GlobalMemoryStatusEx(&mem_info);

			cout << "Processor and some system information:" << endl;
			cout << "processor type: \t" << sys_info.dwProcessorType << endl;
			cout << "number of processors (logic cores): \t\t" << sys_info.dwNumberOfProcessors << endl;
			cout << "processor level: \t" << sys_info.wProcessorLevel << endl;
			cout << "active processor mask: \t" << sys_info.dwActiveProcessorMask << endl;
			cout << "minimum application address: \t" << sys_info.lpMinimumApplicationAddress << endl;
			cout << "maximum application address: \t" << sys_info.lpMaximumApplicationAddress << endl;
			cout << "page size: \t" << sys_info.dwPageSize << endl;

			cout << "\nMemory information:" << endl;
			cout << "memory load: \t\t" << mem_info.dwMemoryLoad << "%" << endl;
			cout << "available memory: \t" << mem_info.ullAvailPhys / 1048576 << " MB" << endl;
			cout << "total memory: \t\t" << mem_info.ullTotalPhys / 1048576 << " MB" << endl;
			cout << "available virtual memory: \t" << mem_info.ullAvailVirtual / 1048576 << " MB" << endl;
			cout << "total virtual memory: \t\t" << mem_info.ullTotalVirtual / 1048576 << " MB" << endl;

			cout << "My system works " << works_time() << " hours" << endl;
			cout << "My boot disk is " << drive_type() << endl;

			break;
		}
		case'9':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (1);
}