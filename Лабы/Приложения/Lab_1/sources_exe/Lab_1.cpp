#include <head.h>

void main(void)
{
	do
	{

		int out[3];
		OSVERSIONINFO ver;
		SYSTEMTIME sys_time;
	
		cout << "Select or not select" << endl;
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
			system("cls");
			cout << "My Windows under " << os_version_1() << endl;
			os_version_0(&ver);
			cout << "My Windows version is " << ver.dwMajorVersion << "." << ver.dwMinorVersion << "." << ver.dwBuildNumber << endl;
			break;
		case'4':
			system("cls");
			display_metrics(out);
			cout << "My screen is " << out[0] << "x" << out[1] << endl;
			break;
		case'5':
			system("cls");
			mouse_parameters(out);
			cout << "My mouse X is " << out[0] << endl;
			cout << "My mouse Y is " << out[1] << endl;
			cout << "My mouse acceleration is " << out[2] << endl;
			break;
		case'6':
			system("cls");
			cout << "My background color is " << sys_colors() << endl;
			break;
		case'7':
			system("cls");
			local_time(&sys_time);
			cout << "My date is " << setfill('0') << setw(2) << sys_time.wDay << "." << setfill('0') << setw(2) << sys_time.wMonth << "." << sys_time.wYear << endl;
			cout << "My time is " << setfill('0') << setw(2) << sys_time.wHour << ":" << setfill('0') << setw(2) << sys_time.wMinute << ":" << setfill('0') << setw(2) << sys_time.wSecond << endl;
			break;
		case'8':
			system("cls");
			cout << "My system works " << works_time() << " hours" << endl;
			cout << "My disk C is " << drive_type() << endl;
			/*SYSTEM_INFO siSysInfo;
			GetSystemInfo(&siSysInfo);
			cout << "Тип процессора : " << siSysInfo.dwProcessorType << endl;
			cout << "Кол-во ядер : " << siSysInfo.dwNumberOfProcessors << endl;

			   GetSystemInfo(&siSysInfo);

   // Display the contents of the SYSTEM_INFO structure.

   printf("Hardware information: \n");
   printf("  OEM ID: %u\n", siSysInfo.dwOemId);
   printf("  Number of processors: %u\n",
	  siSysInfo.dwNumberOfProcessors);
   printf("  Page size: %u\n", siSysInfo.dwPageSize);
   printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
   printf("  Minimum application address: %lx\n",
	  siSysInfo.lpMinimumApplicationAddress);
   printf("  Maximum application address: %lx\n",
	  siSysInfo.lpMaximumApplicationAddress);
   printf("  Active processor mask: %u\n",
	  siSysInfo.dwActiveProcessorMask);
*/
			break;
		case'9':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (1);
}
