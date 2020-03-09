#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <Lmcons.h>
#include <conio.h>
#include <VersionHelpers.h>

string pc_name(void);
string user_name(void);

string sys_dir(void);
string win_dir(void);
string temp_path(void);

int os_version_0(OSVERSIONINFO *ver);
//LPOSVERSIONINFOEXA *os_version_0(void);
const char *os_version_1(void);

int *display_metrics(int out[]);

int *mouse_parameters(int mouse_info[]);

int local_time(SYSTEMTIME *sys_time);

unsigned long sys_colors(void);

//int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
//	HINSTANCE hPrevInstance, // в Win32 не используется
//	LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
//	int nCmdShow);