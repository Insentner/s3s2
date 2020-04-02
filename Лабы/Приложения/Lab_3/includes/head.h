#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
//#include <iomanip>
#include <Windows.h>
#include <Lmcons.h>
//#include <TlHelp32.h>
#include <Psapi.h>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <fstream>

using namespace std;

void chess_crit(CRITICAL_SECTION &crit, stringstream &out);
void chess_mtx(mutex &mtx, stringstream &out);

//void rnd_fill(HANDLE evnt, stringstream &out);
//void rnd_sort(HANDLE evnt, stringstream &out);
void txt_write(HANDLE evnt, string &out);
void txt_sort(HANDLE evnt0, HANDLE evnt1);
void txt_read(HANDLE evnt, string &out);