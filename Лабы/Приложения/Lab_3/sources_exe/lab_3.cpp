#include <head.h>

void main(void)
{
	do
	{
		cout << "Select one of the following tasks:\n1 - CriticalSection\n2 - Mutex\n3 - Event\n4 - exit" << endl;
		
		switch (_getch())
		{
		case'1':
		{
			system("cls");
			cout << "CriticalSection selected:\nsync parallel write to a variable." << endl;
			CRITICAL_SECTION crit;
			stringstream out;
			InitializeCriticalSection(&crit);
			thread thrd0(chess_crit, ref(crit), ref(out));
			thread thrd1(chess_crit, ref(crit), ref(out));
			thrd0.join();
			thrd1.join();
			DeleteCriticalSection(&crit);
			cout << out.rdbuf() << endl;
			break;
		}
		case'2':
		{
			system("cls");
			cout << "Mutex selected:\nsync parallel write to a variable." << endl;
			mutex mtx;
			stringstream out;
			thread thrd0(chess_mtx, ref(mtx), ref(out));
			thread thrd1(chess_mtx, ref(mtx), ref(out));
			thrd0.join();
			thrd1.join();
			cout << out.rdbuf() << endl;
			break;
		}

		case'3':
		{
			system("cls");
			cout << "Event selected:\nsync parallel write, modify and read\na text from .txt file." << endl;
			HANDLE evnt0 = CreateEvent(NULL, FALSE, FALSE, NULL);
			HANDLE evnt1 = CreateEvent(NULL, FALSE, FALSE, NULL);
			string out;
			cin >> out;
			thread thrd0(txt_write, evnt0, ref(out));
			thread thrd1(txt_sort, evnt0, evnt1);
			thread thrd2(txt_read, evnt1, ref(out));
			thrd0.join();
			thrd1.join();
			thrd2.join();
			ResetEvent(evnt0);
			ResetEvent(evnt1);
			CloseHandle(evnt0);
			CloseHandle(evnt1);
			cout << out << endl;
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