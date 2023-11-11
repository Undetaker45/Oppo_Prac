#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "data.h"
using namespace std;

class Zanyatia{
private:
	string aud_;
	string name_;
	Data date_;
	static constexpr char allowedCharacters[] = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890 ";
	static constexpr char allowedCharactersFamily[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm ";
	bool FindAllowedSourceChar(char ch);
	bool FindAllowedSourceCharFamily(char ch);
	bool CheckingValidNameAud();
	bool CheckingValidNameName();
public:
	friend class Test1;
	Zanyatia(string aud_ = "", string name_ = "");
	void LoadTxt(istream& ist);
	static void PrintTableHead(ostream& ost);
	void PrintTableRow(ostream& ost) const;
};