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

double works_time(void);
string drive_type(void);

