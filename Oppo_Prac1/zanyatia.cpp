// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "zanyatia.h"
#include "data.h"

Zanyatia::Zanyatia(string aud, string name){
	this->aud_ = aud;
	this->name_ = name;
}

bool Zanyatia::FindAllowedSourceChar(char ch)
{
	int lenghAllowedCharacters = (sizeof(allowedCharacters) / sizeof(char)) - 1;
	for (int i = 0; i < lenghAllowedCharacters; i++)
	{
		if (allowedCharacters[i] == ch) {
			return true;
		}
	}
	return false;
}
bool Zanyatia::FindAllowedSourceCharFamily(char ch)
{
	int lenghAllowedCharacters = (sizeof(allowedCharactersFamily) / sizeof(char)) - 1;
	for (int i = 0; i < lenghAllowedCharacters; i++)
	{
		if (allowedCharactersFamily[i] == ch) {
			return true;
		}
	}
	return false;
}

bool Zanyatia::CheckingValidNameAud()
{
	for (int i = 0; i < aud_.length(); i++)
	{
		if (!FindAllowedSourceChar(aud_[i]))
		{
			return false;
		}
	}
	return true;
}

bool Zanyatia::CheckingValidNameName()
{
	for (int i = 0; i < name_.length(); i++)
	{
		if (!FindAllowedSourceCharFamily(name_[i]))
		{
			return false;
		}
	}
	return true;
}

void Zanyatia::LoadTxt(istream& ist){
	date_.ReadDate(ist);
	string buf_aud;
	string buf_name;
	try {
		ist >> buf_aud;
		ist >> buf_name;
	}
	catch (const std::runtime_error& e) {
		throw std::runtime_error("Ошибка при чтении полей аудитории и фамилии преподавателя");

	}
	aud_ = buf_aud;
	name_ = buf_name;
	if (!CheckingValidNameAud())
	{
		throw std::runtime_error("Ошибка, в названии аудитории используются запрещённые для данного поля символы");
	}
	if (!CheckingValidNameName())
	{
		throw std::runtime_error("Ошибка, в фамилии преподавателя используются запрещённые для данного поля символы");
	}
}

void Zanyatia::PrintTableHead(ostream& ost){
	ost << setw(20) << left << "Дата" << setw(20) << "|Аудитория" << setw(30) << "|Фамилия" << endl;
	ost << "---------------------------------------------------------------------------------------------------------------" << endl;
	ost << endl;
}

void Zanyatia::PrintTableRow(ostream& ost) const{
	date_.PrintDate(ost);
	ost << setw(20) << aud_;
	ost << setw(30) << name_ << endl;
}