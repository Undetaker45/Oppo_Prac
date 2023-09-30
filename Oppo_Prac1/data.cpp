#include "data.h"

Data::Data(int day, int mounf, int year){
	this->day_ = day;
	this->mounf_ = mounf;
	this->year_ = year;
}
void CheckDate(int in_buf_year, int in_buf_mounf, int in_buf_day){
	if ((in_buf_mounf == 1 || in_buf_mounf == 3 || in_buf_mounf == 5 || in_buf_mounf == 7 || in_buf_mounf == 8 || in_buf_mounf == 10 || in_buf_mounf == 12) && in_buf_day > 31 && in_buf_day < 1) {
		throw (std::runtime_error("ќшибка в поле день"));
	}
	if ((in_buf_mounf == 4 || in_buf_mounf == 6 || in_buf_mounf == 9 || in_buf_mounf == 11) && in_buf_day > 30 && in_buf_day < 1) {
		throw (std::runtime_error("ќшибка в поле день"));
	}
	if (in_buf_mounf == 2) {
		if ((in_buf_year % 4 == 0 && in_buf_year % 100 != 0 && in_buf_year % 400 == 0) && in_buf_day > 29 && in_buf_day < 1) {
			throw (std::runtime_error("ќшибка в дате весокосного года"));
		}
		else if (in_buf_day > 28) {
			throw (std::runtime_error("ќшибка в поле день"));
		}
	}
	if (in_buf_mounf > 12 || in_buf_mounf < 1) {
		throw (std::runtime_error("ќшибка в поле мес€ц"));
	}
	if (in_buf_year < 1951 && in_buf_year > 2123) {
		throw (std::runtime_error("ќшибка в поле год"));
	}
}

void Data::ReadDate(istream& ist){
	string buf, bez_tohek;
	ist >> buf;
	bez_tohek = buf.substr(0, 4) + buf.substr(5, 7) + buf.substr(8, 9);
	int in_buf_day, in_buf_mounf, in_buf_year;
	try {
		in_buf_year = stoi(buf.substr(0, 4));
		in_buf_mounf = stoi(buf.substr(5, 7));
		in_buf_day = stoi(buf.substr(8, 9));
	}
	catch (const std::invalid_argument& e) {
		cout << "ќшибка в формате даты" << endl;
		throw e;
	}
	CheckDate(in_buf_year, in_buf_mounf, in_buf_day);
	day_ = in_buf_day;
	mounf_ = in_buf_mounf;
	year_ = in_buf_year;
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