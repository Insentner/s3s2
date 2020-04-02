#include <head.h>

//void rnd_fill(HANDLE evnt, stringstream &out)
//{
//	out << "\nthread ID: " << this_thread::get_id() << "\n";
//	srand(time(NULL));
//	for (int i = 0; i <= 15; i++)
//	{
//		out << rand() % 10;
//	}
//	SetEvent(evnt);
//}
//
//void rnd_sort(HANDLE evnt, stringstream &out)
//{
//	WaitForSingleObject(evnt, INFINITE);
//	string lox;
//	
//	out >> lox;
//	lox += "sasat";
//	cout << lox << endl;
//
//
//	sort(lox.begin(), lox.end());
//	out << "\nthread ID: " << this_thread::get_id() << "\n";
//	//out << lox;
//}

void txt_write(HANDLE evnt0, string &out)
{
	ofstream f_out("E:\\file.txt");
	f_out << "\nthread ID: " << this_thread::get_id() << endl;
	f_out << "Before:" << endl;
	f_out << out << endl;
	f_out.close();
	out.clear();
	SetEvent(evnt0);
}

void txt_sort(HANDLE evnt0, HANDLE evnt1)
{
	WaitForSingleObject(evnt0, INFINITE);
	fstream f_in;
	string line;
	f_in.open("E:\\file.txt", ios::in);
	int i = 0;
	while (getline(f_in, line, '\n'))
	{
		if (i == 3)
		{
			sort(line.begin(), line.end());
			break;
		}
		line.clear();
		++i;
	}
	f_in.close();
	ofstream f_out;
	f_out.open("E:\\file.txt", ios::app);
	f_out << "\nthread ID: " << this_thread::get_id() << endl;
	f_out << "After:" << endl;
	f_out << line << endl;
	f_out.close();
	SetEvent(evnt1);
}

void txt_read(HANDLE evnt1, string &out)
{
	WaitForSingleObject(evnt1, INFINITE);
	fstream f_in;
	stringstream id;
	string line;
	f_in.open("E:\\file.txt", ios::in);
	//out += +  + ;
	/*i <= 6*/
	while (getline(f_in, line, '\n'))
	{
		out += line + "\n";
		line.clear();
	}
	f_in.close();
	id << "\nthread ID: " << this_thread::get_id() << endl;
	out += id.str() + "Success\n";
}