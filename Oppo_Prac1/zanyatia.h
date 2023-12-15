// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
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
public:
	friend class Test1;
	Zanyatia(string aud_ = "", string name_ = "");
	void LoadTxt(istream& ist);
	static void PrintTableHead(ostream& ost);
	void PrintTableRow(ostream& ost) const;
	bool FindAllowedSourceChar(char ch);
	bool FindAllowedSourceCharFamily(char ch);
	bool CheckingValidNameAud();
	bool CheckingValidNameName();
};