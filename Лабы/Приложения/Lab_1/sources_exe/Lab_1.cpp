#include <head.h>


void main(void)
{
	do
	{
			//const char *osVersionName = os_version();

			//std::printf("Running under Windows %s\n", osVersionName);
		
		cout << "Select penis or no" << endl;
		switch (_getch())
		{
		case'1':
			system("cls");
			cout << "My pipiska is " << pc_name() << endl;
			cout << "My pipiska is " << user_name() << endl;
			break;
		case'2':
			system("cls");
			cout << "My pipiska is " << sys_dir() << endl;
			cout << "My pipiska is " << win_dir() << endl;
			cout << "My pipiska is " << temp_path() << endl;
			break;
		case'3':
			system("cls");

			cout << "My pipiska is " << os_version().dwMajorVersion << "." << os_version().dwMinorVersion << "." << os_version().dwBuildNumber << endl;
			break;
		case'4':
			system("cls");
			cout << "My pipiska is " << sys_dir() << endl;
			cout << "My pipiska is " << win_dir() << endl;
			cout << "My pipiska is " << temp_path() << endl;
			break;
		case'5':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (1);
}
