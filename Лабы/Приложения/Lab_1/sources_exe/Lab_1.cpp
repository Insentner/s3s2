﻿#include <head.h>

void main(void)
{
	do
	{

		int out[3];
		OSVERSIONINFO ver;
		SYSTEMTIME sys_time;
		//int a[3];
		
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

			cout << "My color is " << sys_colors() << endl;
			break;
		case'7':
			system("cls");
			local_time(&sys_time);
			cout << "My date is " << setfill('0') << setw(2) << sys_time.wDay << "." << setfill('0') << setw(2) << sys_time.wMonth << "." << sys_time.wYear << endl;
			cout << "My time is " << setfill('0') << setw(2) << sys_time.wHour << ":" << setfill('0') << setw(2) << sys_time.wMinute << ":" << setfill('0') << setw(2) << sys_time.wSecond << endl;
			break;
		case'8':
			system("cls");

			cout << "My is " << "" << endl;
			break;
		case'9':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (1);
}
