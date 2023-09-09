// Boldyrev1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct	zanyatia
{
	string data;
	string aud;
	string name;
};

int main()
{
	ifstream in;
	in.open("test.txt.txt");
	if (!in.is_open())
	{
		cout << "file no open";
		return 1;
	}
	vector< zanyatia > spisoc;
	while (!in.eof())
	{
		zanyatia bank;
		in >> bank.data;
		in >> bank.aud;
		in >> bank.name;
		spisoc.push_back(bank);
	}
	for (int i = 0; i < spisoc.size(); i++)
	{
		cout << spisoc[i].data << " ";
		cout << spisoc[i].aud << " ";
		cout << spisoc[i].name << endl;
	}
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
