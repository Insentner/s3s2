#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <Windows.h>
#include <Lmcons.h>
#include <conio.h>

string pc_name();
string user_name();

string sys_dir();
string win_dir();
string temp_path();

unsigned long os_version();