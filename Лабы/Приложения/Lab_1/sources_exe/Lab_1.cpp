#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <mutex>
#include <fstream>

using namespace std;

//void critic(PCRITICAL_SECTION critical)
//{
//	EnterCriticalSection(critical);
//	for (size_t i = 0; i < 5; i++)
//	{
//		cout << "ID потока: " << this_thread::get_id() << " - critic  " << i << endl;
//		this_thread::sleep_for(chrono::milliseconds(250));
//	}
//	LeaveCriticalSection(critical);
//}
//
//
//void mutx(mutex mx)
//{
//	mx.lock();
//	for (size_t i = 0; i < 5; i++)
//	{
//		cout << "ID потока: " << this_thread::get_id() << " - mutex  " << i << endl;
//		this_thread::sleep_for(chrono::milliseconds(250));
//	}
//	mx.unlock();
//}


void write(HANDLE* hndl)
{
	WaitForSingleObject(*hndl, INFINITE);
	ofstream fout("E:\\Desktop\\СПОЗИС\\s3s2\\Лабы\\Примеры\\test1\\cppstudio.txt");
	cout << "Я пидарас" << endl;
	fout << "Я люблю МТУСИ и анальный секс!!!";
	Sleep(2500);
	fout.close();
	SetEvent(*hndl);
}

void read(HANDLE* hndl)
{
	WaitForSingleObject(*hndl, INFINITE);
	char buff[50];
	ifstream fin("E:\\Desktop\\СПОЗИС\\s3s2\\Лабы\\Примеры\\test1\\cppstudio.txt");
	cout << "Я пидарас" << endl;
	fin.getline(buff, 50);
	fin.close();
	cout << buff << endl;
	SetEvent(*hndl);
}



int main()
{
	setlocale(LC_ALL, "ru");

	HANDLE event1, event2;
	//PCRITICAL_SECTION critical;
	//mutex mx;


	//InitializeCriticalSection(critical);
	//thread th1(critic, critical);
	//thread th2(critic, critical);
	//th1.join();
	//th2.join();
	//DeleteCriticalSection(critical);

	//thread th3(mutx, mx);
	//thread th4(mutx, mx);
	//th3.join();
	//th4.join();
	
	event1 = CreateEvent(NULL, FALSE, TRUE, NULL);
	event2 = CreateEvent(NULL, FALSE, FALSE, NULL);
	thread th5(write, &event1);
	thread th6(read, &event2);
	th5.join();
	th6.join();

	system("pause");
	return 0;
}