#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <VersionHelpers.h>
#include <string>
#include <TlHelp32.h>
#include <Psapi.h>
#include <processthreadsapi.h>
#include <handleapi.h>
#include <locale.h>

using namespace std;

int main()
{
	do
	{
		setlocale(LC_ALL, "Russian");
		char filename[MAX_PATH];
		DWORD Process_ID;
		system("cls");
		printf("Выберите один из:\n\r"
			"1. Вывод идентификатора и дескриптора процесса;\r\n"
			"2. Вывод дескриптора и полного имени известной библиотеки;\r\n"
			"3. Идентификатор, псевдодескриптор текущего процесса и т.д. (2 часть лабы);\r\n"
			"4. Список всех процессов;\r\n"
			"5. Список всех модулей;\n\r"
			"6. Выход.\r\n");
		int a = _getch();
		switch (a)
		{
		case '1':
		{
			system("cls");
			printf("Введите имя процесса\r\n");
			string name;
			cin >> name; //Ввод названия приложения
			HWND hwnd = FindWindowA(0, name.c_str()); //Поиск окна
			GetWindowThreadProcessId(hwnd, &Process_ID); //Получение идентификатора процесса
			if (hwnd)
			{
				cout << Process_ID << endl; //Вывод идентификатора
				HANDLE Handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Process_ID);
				cout << Handle << endl; //Вывод дескриптора
				GetModuleFileNameEx(Handle, NULL, filename, MAX_PATH);
				cout << filename << endl;
				CloseHandle(Handle);
			}
			else
			{
				cout << "Окно не найдено" << endl;
			}
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			printf("Введите название библиотеки\r\n");
			char file_name2[MAX_PATH];
			string ModuleName;
			cin >> ModuleName;
			cout << GetModuleHandleA(ModuleName.c_str()) << endl;
			GetModuleFileName(GetModuleHandleA(ModuleName.c_str()), file_name2, MAX_PATH);
			cout << file_name2 << endl;
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			HANDLE TemHandle;
			HANDLE RealHandle = OpenProcess(PROCESS_DUP_HANDLE, FALSE, GetCurrentProcessId());
			HANDLE hPseudoProc = GetCurrentProcess();
			printf("Идентификатор текущего процесса:\r\n");
			cout << GetCurrentProcessId() << endl;
			printf("Псевдодескриптор текущего процесса:\r\n");
			cout << GetCurrentProcess() << endl;
			printf("Дескриптор текущего процесса (OpenProcess()):\r\n");
			cout << RealHandle << endl;
			DuplicateHandle(RealHandle, hPseudoProc, hPseudoProc, &TemHandle, 0, FALSE, DUPLICATE_SAME_ACCESS);
			printf("Дескриптор текущего процесса (DuplicateHandle()):\r\n");
			cout << TemHandle << endl;
			CloseHandle(RealHandle);
			CloseHandle(TemHandle);
			printf("Дескрипторы закрыты.\r\n");
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			HANDLE hSnap;
			hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
			if (hSnap == NULL)
			{
				return 0;
			}
			PROCESSENTRY32 proc;
			proc.dwSize = sizeof(proc);

			if (Process32First(hSnap, &proc))
			{
				do {
					wcout << proc.szExeFile << L" Поток: " << proc.th32ProcessID << endl;
				} while (Process32Next(hSnap, &proc));
			}
			system("pause");
			break;
		}
		case '5':
		{
			system("cls");
			HANDLE hSnap;
			hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
			if (hSnap == NULL)
			{
				return 0;
			}
			MODULEENTRY32 proc1;
			proc1.dwSize = sizeof(proc1);
			if (Module32First(hSnap, &proc1))
			{
				do {
					wcout << proc1.szModule << L" Поток: " << proc1.th32ProcessID << endl;
				} while (Module32Next(hSnap, &proc1));
			}
			system("pause");
			break;
		}
		case '6':
		{
			exit(0);
		}
		default:
		{
			system("pause");
			break;
		}
		}


	} while (1);
}