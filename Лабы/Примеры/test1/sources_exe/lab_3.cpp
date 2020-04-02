#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <mutex>
#include <fstream>

using namespace std;

void critic(CRITICAL_SECTION &critical)
{
	EnterCriticalSection(&critical);
	for (size_t i = 0; i < 5; i++)
	{
		cout << "ID потока: " << this_thread::get_id() << " - critic  " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(250));
	}
	LeaveCriticalSection(&critical);
}

void mutx(mutex &mx)
{
	mx.lock();
	for (size_t i = 0; i < 5; i++)
	{
		cout << "ID потока: " << this_thread::get_id() << " - mutex  " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(250));
	}
	mx.unlock();
}

void write(HANDLE hndl)
{
	ofstream fout("E:\\Desktop\\СПОЗИС\\s3s2\\Лабы\\Примеры\\test1\\cppstudio.txt");
	fout << "Работа с говном в штанах";
	Sleep(250);
	fout.close();
	cout << "Я записаль" << endl;
	SetEvent(hndl);
}

void read(HANDLE hndl)
{
	WaitForSingleObject(hndl, INFINITE);
	char buff[50];
	ifstream fin("E:\\Desktop\\СПОЗИС\\s3s2\\Лабы\\Примеры\\test1\\cppstudio.txt");
	fin.getline(buff, 50);
	fin.close();
	cout << buff << endl;
}



int main()
{
	setlocale(LC_ALL, "ru");

	CRITICAL_SECTION critical;
	mutex mx;
	HANDLE event0;
	
	InitializeCriticalSection(&critical);
	thread th1(critic, ref(critical));
	thread th2(critic, ref(critical));
	th1.join();
	th2.join();
	DeleteCriticalSection(&critical);

	thread th3(mutx, ref(mx));
	thread th4(mutx, ref(mx));
	th3.join();
	th4.join();

	event0 = CreateEvent(NULL, FALSE, FALSE, NULL);
	thread th5(write, event0);
	thread th6(read, event0);
	th5.join();
	th6.join();



	system("pause");
	return 0;
}