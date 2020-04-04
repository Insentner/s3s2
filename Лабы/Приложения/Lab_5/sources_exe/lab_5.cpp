#include <head.h>

stringstream dgrm(float prcnt)
{
	stringstream output;
	output << "[";
	int i = 0;
	do
	{
		output << "|";
		//++i;
	} while (++i <= prcnt);
	while (100 > i++)
	{
		output << "-";
		//++i;
	}
	output << "]  " << prcnt << "%";
	return output;
}

void main(void)
{
	do
	{
		cout << "Select one of the following tasks:\n1 - Total memory status\n2 - Process memory map by name\n3 - Exit" << endl;
		
		switch (_getch())
		{
		case'1':
		{
			system("cls");
			MEMORYSTATUSEX t_mem_stat;
			t_mem_stat.dwLength = sizeof(MEMORYSTATUSEX);
			do
			{
				system("cls");
				cout << "Total memory status:" << endl;
				GlobalMemoryStatusEx(&t_mem_stat);

				cout << "Physical memory:\t" << t_mem_stat.ullAvailPhys / 1048576 << "MB / " << t_mem_stat.ullTotalPhys / 1048576 << "MB\tis free" << endl;
				cout << "USED:" << dgrm((float)100 * (1 - ((t_mem_stat.ullAvailPhys) / ((float)t_mem_stat.ullTotalPhys)))).rdbuf() << endl;

				cout << "Virtual memory:\t" << t_mem_stat.ullAvailVirtual / 1048576 << "MB / " << t_mem_stat.ullTotalVirtual / 1048576 << "MB\tis free" << endl;
				cout << "USED:" << dgrm((float)100 * (1 - ((t_mem_stat.ullAvailVirtual) / ((float)t_mem_stat.ullTotalVirtual)))).rdbuf() << endl;

				cout << "Virtual memory:\t" << t_mem_stat.ullAvailPageFile / 1048576 << "MB / " << t_mem_stat.ullTotalPageFile / 1048576 << "MB\tis free" << endl;
				cout << "USED:" << dgrm((float)100 * (1 - ((t_mem_stat.ullAvailPageFile) / ((float)t_mem_stat.ullTotalPageFile)))).rdbuf() << endl;

				cout << "USED:" << t_mem_stat.dwMemoryLoad << "%" << endl;

				cout << "Press 'r' to refresh" << endl;
				
			} while (_getch() == 'r');
			break;
		}
		case'2':
		{
			system("cls");
			cout << "Enter process name:" << endl;
			SYSTEM_INFO sys_info;
			MEMORY_BASIC_INFORMATION mem_info;
			PROCESSENTRY32 prcs_info;
			LPVOID adr;
			size_t pg_size;
			HANDLE prcs_hndl = NULL;//надо узнать handle //вроде узнал
			HANDLE snp_all = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
			string mem_state;
			string mem_protect;
			string mem_type;
			string prcs_name;

			bool res;

			cin >> prcs_name;

			GetSystemInfo(&sys_info);
			adr = sys_info.lpMinimumApplicationAddress;
			prcs_info.dwSize = sizeof(PROCESSENTRY32);

			if (Process32First(snp_all, &prcs_info))
			{

				do
				{
					if (!_stricmp(prcs_name.c_str(), prcs_info.szExeFile)) break;
					//if (prcs_name.c_str() == prcs_info.szExeFile) break;
				} while (Process32Next(snp_all, &prcs_info));
				//prcs_hndl = OpenProcess(PROCESS_ALL_ACCESS, TRUE, prcs_info.th32ProcessID);
				cout << prcs_info.th32ProcessID << endl;
			}
			
			
			
			CloseHandle(snp_all);
			do
			{
				prcs_hndl = OpenProcess(PROCESS_ALL_ACCESS, FALSE, prcs_info.th32ProcessID);
				res = VirtualQueryEx(prcs_hndl, adr, &mem_info, sizeof(MEMORY_BASIC_INFORMATION));
			    pg_size = mem_info.RegionSize;

				if (res)
				{
					if (mem_info.State == MEM_COMMIT)
					{
						mem_state += "MEM_COMMIT ";
					}
					else if (mem_info.State == MEM_FREE)
					{
						mem_state += "MEM_FREE   ";
					}
					else if (mem_info.State == MEM_RESERVE)
					{
						mem_state += "MEM_RESERVE";
					}
					else mem_state += "UNKNOWN    ";
					if (mem_info.Type == MEM_IMAGE)
					{
						mem_type += "MEM_IMAGE  ";
					}
					else if(mem_info.Type == MEM_MAPPED)
					{
						mem_type += "MEM_MAPPED ";
					}
					else if(mem_info.Type == MEM_PRIVATE)
					{
						mem_type += "MEM_PRIVATE";
					}
					else mem_type += "UNKNOWN    ";
					if (mem_info.AllocationProtect == PAGE_EXECUTE_WRITECOPY)
					{
						mem_protect += "PAGE_EXECUTE_WRITECOPY";
					}
					else if (mem_info.AllocationProtect == PAGE_EXECUTE_READWRITE)
					{
						mem_protect += "PAGE_EXECUTE_READWRITE";
					}
					else if (mem_info.AllocationProtect == PAGE_EXECUTE)
					{
						mem_protect += "PAGE_EXECUTE          ";
					}
					else if (mem_info.AllocationProtect == PAGE_EXECUTE_READ)
					{
						mem_protect += "PAGE_EXECUTE_READ     ";
					}
					else if (mem_info.AllocationProtect == PAGE_NOACCESS)
					{
						mem_protect += "PAGE_NOACCESS         ";
					}
					else if (mem_info.AllocationProtect == PAGE_READONLY)
					{
						mem_protect += "PAGE_READONLY         ";
					}
					else if (mem_info.AllocationProtect == PAGE_READWRITE)
					{
						mem_protect += "PAGE_READWRITE        ";
					}
					else if (mem_info.AllocationProtect == PAGE_WRITECOPY)
					{
						mem_protect += "PAGE_WRITECOPY        ";
					}
					else mem_protect += "UNKNOWN               ";
				}
				cout << (unsigned int)mem_info.BaseAddress << " - " << (unsigned int)mem_info.BaseAddress + (unsigned int)pg_size - 1 << "\t\tState: " << mem_state << "\tProtect: " << mem_protect << "\t\tType: " << mem_type << endl;
				mem_state.clear();
				mem_protect.clear();
				mem_type.clear();
				adr = reinterpret_cast<char*>(adr) + pg_size;
			} while (adr <= sys_info.lpMaximumApplicationAddress && res);
			CloseHandle(prcs_hndl);
			cout << "Done." << endl;
			break;
		}
		case'3':
		{
			exit(0);
		}
		}
		system("pause");
		system("cls");
	} while (1);
}