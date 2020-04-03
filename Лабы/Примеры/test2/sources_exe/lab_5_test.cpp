#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <string>
#include <conio.h>


// Используется для перевода байтов в мегабайты
#define DIV 1048576
// Ширина поля для вывода чисел
#define WIDTH 8

using namespace std;

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << " Свободно " << endl;
}
 

int main()
{
	setlocale(LC_ALL, "Russian");
	{
		int i = 1;
		while (i == 1)
		{
			system("cls");
			cout << "1. Информация о памяти; " << endl << "2. Карта виртуальной памяти вызывающего процесса; " << endl << "3. Exit; " << endl;
			int a = _getch();
			switch (a)
			{
			case '1':
			{
				system("cls");

				MEMORYSTATUSEX statex;

				statex.dwLength = sizeof(statex);

				GlobalMemoryStatusEx(&statex);

				printf("Всего        %*I64d MB физической памяти.\n", WIDTH, statex.ullTotalPhys / DIV);
				printf("Свободно     %*I64d MB физической памяти.\n", WIDTH, statex.ullAvailPhys / DIV);
				int nphis = 100 * (statex.ullAvailPhys / DIV) / (statex.ullTotalPhys / DIV) / 2;
				cout << "Диаграмма:" << endl;
				cout << "**************************************************" << " Полный объем" << endl;
				print(nphis);
				cout << endl;

				printf("Всего        %*I64d MB в файле подкачки.\n", WIDTH, statex.ullTotalPageFile / DIV);
				printf("Свободно     %*I64d MB в файле подкачки.\n", WIDTH, statex.ullAvailPageFile / DIV);
				int npod = 100 * (statex.ullAvailPageFile / DIV) / (statex.ullTotalPageFile / DIV) / 2;
				cout << "Диаграмма:" << endl;
				cout << "**************************************************" << " Полный объем" << endl;
				print(npod);
				cout << endl;

				printf("Всего        %*I64d MB виртуальной памяти.\n", WIDTH, statex.ullTotalVirtual / DIV);
				printf("Свободно     %*I64d MB виртуальной памяти.\n", WIDTH, statex.ullAvailVirtual / DIV);
				int nvir = 100 * (statex.ullAvailVirtual / DIV) / (statex.ullTotalVirtual / DIV) / 2;
				cout << "Диаграмма:" << endl;
				cout << "**************************************************" << " Полный объем" << endl;
				print(nvir);
				system("pause");
				break;
			}
			case '2':
			{
				system("cls");
				SYSTEM_INFO sysInfo;
				GetSystemInfo(&sysInfo);
				LPVOID address = sysInfo.lpMinimumApplicationAddress;
				do
				{
					HANDLE RealHandle = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, GetCurrentProcessId());
					MEMORY_BASIC_INFORMATION membaseinfo;
					int result = VirtualQueryEx(RealHandle, address, &membaseinfo, sizeof(membaseinfo));
					size_t pageSize = membaseinfo.RegionSize;
					std::string statembi;
					std::string protectmbi;
					if (result != NULL) {
						if (membaseinfo.State == MEM_COMMIT)
						{
							statembi += "MEM_COMMIT";
						}
						else if (membaseinfo.State == MEM_FREE)
						{
							statembi += "MEM_FREE";
						}
						else if (membaseinfo.State == MEM_RESERVE) {
							statembi += "MEM_RESERVE";
						}
						else statembi += "_";
						if (membaseinfo.AllocationProtect == PAGE_EXECUTE_WRITECOPY)
						{
							protectmbi += "PAGE_EXECUTE_WRITECOPY";
						}
						else if (membaseinfo.AllocationProtect == PAGE_EXECUTE_READWRITE) {
							protectmbi += "PAGE_EXECUTE_READWRITE";
						}
						else if (membaseinfo.AllocationProtect == PAGE_EXECUTE) {
							protectmbi += "PAGE_EXECUTE";
						}
						else if (membaseinfo.AllocationProtect == PAGE_EXECUTE_READ) {
							protectmbi += "PAGE_EXECUTE_READ";
						}
						else if (membaseinfo.AllocationProtect == PAGE_NOACCESS) {
							protectmbi += "PAGE_NOACCESS";
						}
						else if (membaseinfo.AllocationProtect == PAGE_READONLY) {
							protectmbi += "PAGE_READONLY";
						}
						else if (membaseinfo.AllocationProtect == PAGE_READWRITE) {
							protectmbi += "PAGE_READWRITE";
						}
						else if (membaseinfo.AllocationProtect == PAGE_WRITECOPY) {
							protectmbi += "PAGE_WRITECOPY";
						}
						else protectmbi += "Unknown flag";
					}
					cout << (unsigned int)membaseinfo.BaseAddress << "-" << (unsigned int)membaseinfo.BaseAddress + (unsigned int)membaseinfo.RegionSize - 1 << " State: " << statembi << " Protect: " << protectmbi << endl;
					address = reinterpret_cast<char*>(address) + pageSize;
				} while (address <= sysInfo.lpMaximumApplicationAddress);
				system("pause");
				break;
			}
			case '3':
			{
				i = 0;
				break;
			}
			default:
			{
				system("cls");
				printf("Try again.\r\n");
				system("pause");
				break;
			}
			}
		}
	}
}
