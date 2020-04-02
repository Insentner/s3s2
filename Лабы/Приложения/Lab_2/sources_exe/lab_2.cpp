#include <head.h>

void main(void)
{
	do
	{
		cout << "Select one of the following tasks:\n1 - Output process/library full name, handle and id by name\n2 - Output id, pseudo handle and handle of current process\n3 - Output all processes/modules and their properties\n4 - exit" << endl;
		switch (_getch())
		{
			case'1':
			{
				bool exit = 0;
				do
				{
					system("cls");
					cout << "Select task option:\n1 - of process\n2 - of module\n3 - back" << endl;
					switch (_getch())
					{
					case'1':
					{
						system("cls");
						char prcs_fullname[MAX_PATH];
						DWORD prcs_id;
						string prsc_name;
						HWND hndl_wndw;
						HANDLE hndl_prcs;

						cout << "Enter process name:" << endl;
						cin >> prsc_name;
						hndl_wndw = FindWindowA(NULL, prsc_name.c_str());
						GetWindowThreadProcessId(hndl_wndw, &prcs_id);
						if (hndl_wndw)
						{
							cout << "process id:" << prcs_id << endl;
							hndl_prcs = OpenProcess(PROCESS_ALL_ACCESS, FALSE, prcs_id);
							cout << "process handle:" << hndl_prcs << endl;
							GetModuleFileNameEx(hndl_prcs, NULL, prcs_fullname, MAX_PATH);
							cout << "process full name:" << prcs_fullname << endl;
							CloseHandle(hndl_prcs);
						}
						else
						{
							cout << "Process not found" << endl;
						}
						system("pause");
						break;
					}
					case'2':
					{
						system("cls");
						cout << "Enter library name:" << endl;
						char mdl_fullname[MAX_PATH];
						string mdl_name;
						HMODULE hndl_mdl;
						cin >> mdl_name;
						hndl_mdl = GetModuleHandleA(mdl_name.c_str());
						if (hndl_mdl)
						{
							cout << hndl_mdl << endl;
							GetModuleFileName(GetModuleHandleA(mdl_name.c_str()), mdl_fullname, MAX_PATH);
							cout << mdl_fullname << endl;					
						}
						else
						{
							cout << "Module not found" << endl;
						}
						system("pause");
						break;
					}
					case'3':
					{
						exit = 1;
						break;
					}
					}
					if(exit)break;
				} while (1);
				break;
				
			}
		    case'2':
		    {
			    system("cls");
				HANDLE hndl_psd = GetCurrentProcess();
				DWORD prcs_id = GetCurrentProcessId();
				HANDLE hndl_DH;
				HANDLE hndl_OP;
				
			    cout << "current process id: " << prcs_id << endl;

				cout << "current process thread: "<< this_thread::get_id << endl;

			    cout << "current process pseudo handle: " << hndl_psd << endl;

				DuplicateHandle(hndl_psd, hndl_psd, hndl_psd, &hndl_DH, NULL, FALSE, DUPLICATE_SAME_ACCESS);
				cout << "current process handle by DuplicateHandle: " << hndl_DH << endl;

				hndl_OP = OpenProcess(PROCESS_DUP_HANDLE, FALSE, prcs_id);
			    cout << "current process handle by OpenProcess: " << hndl_OP << endl;

			    CloseHandle(hndl_DH);
			    CloseHandle(hndl_OP);

			    break;
		    }
			
			case'3':
			{
				bool exit = 0;
				do
				{
					system("cls");
					cout << "Select task option:\n1 - show all processes\n2 - show all modules\n3 - back" << endl;
					switch (_getch())
					{
					case'1':
					{
						system("cls");
						HANDLE hndl_snp;
						hndl_snp = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
						if (hndl_snp == NULL) break;
						PROCESSENTRY32 strc_prcs;
						strc_prcs.dwSize = sizeof(strc_prcs);

						if (Process32First(hndl_snp, &strc_prcs))
						{
							do
							{
								wcout << strc_prcs.szExeFile << L" \t\tprocess id: " << strc_prcs.th32ProcessID << L" \tnumber of threads: " << strc_prcs.cntThreads << endl;
							} while (Process32Next(hndl_snp, &strc_prcs));
						}
						system("pause");
						break;
					}
					case'2':
					{
						system("cls");
						HANDLE hndl_snp;
						hndl_snp = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
						if (hndl_snp == NULL) break;
						MODULEENTRY32 strc_mdl;
						strc_mdl.dwSize = sizeof(strc_mdl);
						if (Module32First(hndl_snp, &strc_mdl))
						{
							do
							{
								wcout << strc_mdl.szModule << left << L" \t\tprocess id:\t " << strc_mdl.th32ProcessID << L" \tsize:\t " << strc_mdl.modBaseSize << L" bytes " << endl;
							} while (Module32Next(hndl_snp, &strc_mdl));
						}
						system("pause");
						break;
					}
					case'3':
					{
						exit = 1;
						break;
					}
					}
					if (exit) break;
				} while (1);
				break;
			}
		    case'4':
		    {
			    exit(0);
		    }	
		}
		system("pause");
		system("cls");
	} while (1);
}
