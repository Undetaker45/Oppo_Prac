#include "data.h"

Data::Data( int day, int mounf, int year) {
	this->day_ = day;
	this->mounf_ = mounf;
	this->year_ = year;
}

void Data::ReadDate(istream& ist) {
	string buf, buf_day, buf_mounf, buf_year;
	ist >> buf;
	int i = 0;
	while (buf[i] != '.') {
		buf_year += buf[i];
		i++;
	}
	i++;
	while (buf[i] != '.') {
		buf_mounf += buf[i];
		i++;
	}
	i++;
	while (i < buf.size()) {
		buf_day += buf[i];
		i++;
	}
	day_ = stoi(buf_day);
	mounf_ = stoi(buf_mounf);
	year_ = stoi(buf_year);
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