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

//const char *os_version();

OSVERSIONINFO os_version();