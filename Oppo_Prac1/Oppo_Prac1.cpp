// Boldyrev1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class zanyatia
{
private:
	string data;
	string aud;
	string name;
public:
	zanyatia(string data = "", string aud = "", string name = "");
	~zanyatia();
	void load_txt(istream& ist);
	static void print_table_head(ostream& ost);
	void print_table_row(ostream& ost) const;
};
zanyatia::zanyatia(string data, string aud, string name) 
{
	this->data = data;
	this->aud = aud;
	this->name = name;
}
zanyatia::~zanyatia()
{
}

void zanyatia::load_txt(istream& ist)
{
	string buf_data;
	string buf_aud;
	string buf_name;
	ist >> buf_data;
	ist >> buf_aud;
	ist >> buf_name;
	data = buf_data;
	aud = buf_aud;
	name = buf_name;
}

void zanyatia::print_table_head(ostream& ost)
{
	cout << setw(20) << left << "Дата" << setw(20) << "|Аудитория" << setw(30) << "|Фамилия"<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}

void zanyatia::print_table_row(ostream& ost) const
{
	cout << setw(20) << data;
	cout << setw(20) << aud;
	cout << setw(30) << name << endl;
}

size_t load_txt(vector<zanyatia*>& spisoc, istream& ist)
{
	int cnt = 0;
	while (!ist.eof())
	{
		zanyatia* den = new zanyatia;
		den->load_txt(ist);
		spisoc.push_back(den);
		cnt++;
	}
	return cnt;
}

size_t print_table(const vector<zanyatia*>& spisoc, ostream& ost)
{
	spisoc[0]->print_table_head(ost);
	int len = size(spisoc);
	for (int i = 0; i < size(spisoc); i++)
	{
		spisoc[i]->print_table_row(ost);
	}
	return len;
}

void clear_memory(vector<zanyatia*>& data)
{
	for (int i = 0; i < size(data); i++)
	{
		delete data[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	vector< zanyatia* > spisoc;
	ifstream ist;
	ist.open("in.txt");
	if (ist.is_open() == false)
	{
		cout << "Файл не найден\n";
		return 1;
	}
	load_txt(spisoc, ist);
	ist.close();
	print_table(spisoc, cout);
	clear_memory(spisoc);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
