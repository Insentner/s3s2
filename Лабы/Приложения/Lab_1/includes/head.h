#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <Windows.h>
#include <Lmcons.h>
#include <conio.h>
#include <VersionHelpers.h>

string pc_name(void);
string user_name(void);

string sys_dir(void);
string win_dir(void);
string temp_path(void);

OSVERSIONINFO os_version_0(void);
const char *os_version_1(void);

int *sys_metrics(int out[]);

string sys_parameters(void);

int *sys_parameters(int aMouseInfo[]);

int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
	HINSTANCE hPrevInstance, // в Win32 не используется
	LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
	int nCmdShow);