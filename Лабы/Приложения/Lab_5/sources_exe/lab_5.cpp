#include <head.h>

void main(void)
{
	do
	{
		cout << "Select one of the following tasks:\n1 - \n2 - \n3 - \n4 - exit" << endl;
		
		switch (_getch())
		{
		case'1':
		{
			system("cls");
			cout << "" << endl;
			
			cout << "" << endl;
			break;
		}
		case'2':
		{
			system("cls");
			cout << "" << endl;
			
			cout << "" << endl;
			break;
		}

		case'3':
		{
			system("cls");
			cout << "" << endl;
			
			cout << "" << endl;
			break;
		}
		case'4':
		{
			exit(0);
		}
		}
		system("pause");
		system("cls");
	} while (1);
}