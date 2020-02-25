#include <head.h>

void main(void)
{
	do
	{

		int out[3];
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
			//cout << "My Windows version is " << os_version_0().dwMajorVersion << "." << os_version_0()->dwMinorVersion << "." << os_version_0()->dwBuildNumber << endl;
			break;
		case'4':
			system("cls");
			sys_metrics(out);
			cout << "My screen is " << out[0] << "x" << out[1] << endl;
			break;
		case'5':
			system("cls");
			sys_parameters(out);
			cout << "My mouse is " << out[1] << endl;
			break;
		case'6':
			system("cls");

			cout << "My is " << endl;
			break;
		case'7':
			system("cls");

			cout << "My is " << endl;
			break;


		case'9':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (1);
}
