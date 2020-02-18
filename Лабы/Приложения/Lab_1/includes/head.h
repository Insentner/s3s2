#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <Windows.h>
#include <Lmcons.h>
#include <conio.h>
#include <VersionHelpers.h>

string pc_name();
string user_name();

string sys_dir();
string win_dir();
string temp_path();

OSVERSIONINFO os_version_0();
const char *os_version_1();

string sys_metrics(void);