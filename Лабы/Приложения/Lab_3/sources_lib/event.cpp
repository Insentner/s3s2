#include <head.h>

void txt_write(HANDLE evnt0, string &out)
{
	ofstream file_out("E:\\file.txt");
	file_out << "\nthread ID: " << this_thread::get_id() << endl;
	file_out << "Before:" << endl;
	file_out << out << endl;
	file_out.close();
	out.clear();
	SetEvent(evnt0);
}

void txt_sort(HANDLE evnt0, HANDLE evnt1)
{
	WaitForSingleObject(evnt0, INFINITE);
	fstream file_input;
	string line;
	file_input.open("E:\\file.txt", ios::in);
	int i = 0;
	while (getline(file_input, line, '\n'))
	{
		if (i == 3)
		{
			sort(line.begin(), line.end());
			break;
		}
		line.clear();
		++i;
	}
	file_input.close();
	ofstream file_out;
	file_out.open("E:\\file.txt", ios::app);
	file_out << "\nthread ID: " << this_thread::get_id() << endl;
	file_out << "After:" << endl;
	file_out << line << endl;
	file_out.close();
	SetEvent(evnt1);
}

void txt_read(HANDLE evnt1, string &out)
{
	WaitForSingleObject(evnt1, INFINITE);
	fstream file_input;
	stringstream id;
	string line;
	file_input.open("E:\\file.txt", ios::in);
	while (getline(file_input, line, '\n'))
	{
		out += line + "\n";
		line.clear();
	}
	file_input.close();
	id << "\nthread ID: " << this_thread::get_id() << endl;
	out += id.str() + "Success\n";
}