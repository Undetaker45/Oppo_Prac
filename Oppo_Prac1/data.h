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
	Data(int day_ = 0, int mounf_ = 0, int year_ = 0);
	void ReadDate(istream& ist);
	void PrintDate(ostream& ost) const;
};