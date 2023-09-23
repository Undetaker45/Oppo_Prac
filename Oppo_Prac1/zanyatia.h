#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "data.h"
using namespace std;

class Zanyatia {
private:
	string aud_;
	string name_;
	Data date_;
public:
	Zanyatia(string aud_ = "", string name_ = "");
	void load_txt(istream& ist);
	static void PrintTableHead(ostream& ost);
	void PrintTableRow(ostream& ost) const;
};