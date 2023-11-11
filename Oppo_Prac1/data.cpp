#include "data.h"

Data::Data(int day, int mounf, int year){
	this->day_ = day;
	this->mounf_ = mounf;
	this->year_ = year;
}
bool Data::CheckDate(){
	if ((mounf_ == 1 || mounf_ == 3 || mounf_ == 5 || mounf_ == 7 || mounf_ == 8 || mounf_ == 10 || mounf_ == 12) && day_ > 31 && day_ < 1) {
		return false;
	}
	if ((mounf_ == 4 || mounf_ == 6 || mounf_ == 9 || mounf_ == 11) && day_ > 30 && day_ < 1) {
		return false;
	}
	if (mounf_ == 2) {
		if ((year_ % 4 == 0 && year_ % 100 != 0 && year_ % 400 == 0) && day_ > 29 && day_ < 1) {
			return false;
		}
		else if (day_ > 28) {
			return false;
		}
	}
	if (mounf_ > 12 || mounf_ < 1) {
		return false;
	}

	return true;
}

void Data::ReadDate(istream& ist){
	string buf;
	ist >> buf; 
	try {
		int PositionMonth = buf.find_first_of('.');
		int PositionDay = buf.find_first_of('.', PositionMonth + 1);
		year_ = stoi(buf.substr(0, PositionMonth));
		mounf_ = stoi(buf.substr(PositionMonth+1, (PositionDay - PositionMonth -1)));
		day_ = stoi(buf.substr(PositionDay+1));
	}
	catch (const std::invalid_argument& e) {
		cout << "Ошибка в формате даты" << endl;
		throw e;
		return;
	}
	if (year_ < 1951 || year_ > 2123) {
		throw (std::runtime_error("Указанный год находиться за границами допустимых."));
	}
	if (!CheckDate()) {
		throw (std::runtime_error("Неправильный формат даты."));
		return;
	}
}

void Data::PrintDate(ostream& ost) const{
	string buf_mounf, buf_day, buf_data;
	if (day_ < 10)
		buf_day = "0" + to_string(day_);
	else
		buf_day = to_string(day_);
	if (mounf_ < 10)
		buf_mounf = "0" + to_string(mounf_);
	else
		buf_mounf = to_string(mounf_);
	buf_data = to_string(year_) + "." + buf_mounf + "." + buf_day;
	ost << setw(20) << buf_data;
}