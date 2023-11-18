#include "zanyatia.h"
#include "data.h"

size_t LoadTxt(vector<Zanyatia*>& spisoc, istream& ist)
{
	int cnt = 0;
	while (!ist.eof()){
		Zanyatia* den = new Zanyatia;
		den->LoadTxt(ist);
		spisoc.push_back(den);
		cnt++;
	}
	return cnt;
}

size_t PrintTable(const vector<Zanyatia*>& spisoc, ostream& ost){
	int len = size(spisoc);
	if (len != 0) {
		spisoc[0]->PrintTableHead(ost);
	}
	for (int i = 0; i < size(spisoc); i++){
		spisoc[i]->PrintTableRow(ost);
	}
	return len;
}

int main(){
	setlocale(LC_ALL, "Rus");
	vector< Zanyatia* > spisoc;
	ifstream ist;
	ist.open("in.txt");
	if (ist.is_open() == false)
	{
		cout << "Файл не найден\n";
		return 1;
	}
	int cnt;
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
	return 0;
}

//Учебные занятия: дата, название аудитории (строка в характерном формате),имя преподавателя(строка)