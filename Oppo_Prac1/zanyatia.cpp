#include "zanyatia.h"
#include "data.h"

Zanyatia::Zanyatia(string aud, string name) {
	this->aud_ = aud;
	this->name_ = name;
}

void Zanyatia::load_txt(istream& ist) {
	date_.ReadDate(ist);
	string buf_aud;
	string buf_name;
	ist >> buf_aud;
	ist >> buf_name;
	aud_ = buf_aud;
	name_ = buf_name;
}

void Zanyatia::PrintTableHead(ostream& ost) {
	ost << setw(20) << left << "Дата" << setw(20) << "|Аудитория" << setw(30) << "|Фамилия" << endl;
	ost << "---------------------------------------------------------------------------------------------------------------" << endl;
	ost << endl;
}

void Zanyatia::PrintTableRow(ostream& ost) const {
	date_.PrintDate(ost);
	ost << setw(20) << aud_;
	ost << setw(30) << name_ << endl;
}