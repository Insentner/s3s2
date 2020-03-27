#include <head.h>

void main(void)
{
	do
	{
		cout << "Select or not select" << endl;
		switch (_getch())
		{
		case'1':
			system("cls");
			cout << "My name is " << endl;
			cout << "Your name is " << endl;
			break;

			break;
		case'9':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (1);
}
