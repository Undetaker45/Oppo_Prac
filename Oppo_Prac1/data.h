// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
using namespace std;
class Data{
private:
	int day_;
	int mounf_;
	int year_;
public:
	friend class Test1;
	explicit Data(static int day_ = 0, static int mounf_ = 0, static int year_ = 0);
	void ReadDate(istream& ist);
	void PrintDate(ostream& ost) const;
	void SetDate(int year, int mounf, int day)
	{
		year_ = year; mounf_ = mounf; day_ = day;
	}
	bool CheckDate();
};