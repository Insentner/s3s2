#include <head.h>

void chess_crit(CRITICAL_SECTION &crit, stringstream &out)
{
	EnterCriticalSection(&crit);
	out << "\nthread ID: " << this_thread::get_id() << "\n";
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			if (j % 2 == i % 2)
			{
				out << "#";
				this_thread::sleep_for(chrono::milliseconds(5));
			}
				
			else
			{
				out << "_";
				this_thread::sleep_for(chrono::milliseconds(5));
			}	
		}
		out << "\n";
	}
	LeaveCriticalSection(&crit);
}