// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , FILE , LINE )
#endif

#include "zanyatia.h"
#include "data.h"

size_t LoadTxt(vector<Zanyatia>& spisoc, istream& ist)
{
	int cnt = 0;
	while (!ist.eof() && ist.good()) {
		Zanyatia den;
		den.LoadTxt(ist);
		spisoc.push_back(den);
		cnt++;
	}
	return cnt;
}

size_t PrintTable(const vector<Zanyatia>& spisoc, ostream& ost) {
	int len = size(spisoc);
	if (len != 0) {
		spisoc[0].PrintTableHead(ost);
	}
	for (int i = 0; i < size(spisoc); i++) {
		spisoc[i].PrintTableRow(ost);
	}
	return len;
}

void CheckMemoryLeaks() {
	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	//_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}

int main() {
	atexit(CheckMemoryLeaks);
	setlocale(LC_ALL, "Rus");
	vector< Zanyatia > spisoc;
	ifstream ist;
	int cnt = 1;
	ist.open("in.txt");
	if (ist.is_open() == false)
	{
		cout << "Файл не найден\n";
		return 1;
	}
	try {
		cnt = LoadTxt(spisoc, ist);
	}
	catch (const std::invalid_argument& e)
	{
		cout << "Ошибка на " << cnt << " сточке";

	}
	catch (const std::runtime_error& f)
	{
		cout << "Ошибка на " << cnt << " сточке";
	}
	ist.close();
	PrintTable(spisoc, cout);
	spisoc.clear();
	return 0;
}

//Учебные занятия: дата, название аудитории (строка в характерном формате),имя преподавателя(строка)