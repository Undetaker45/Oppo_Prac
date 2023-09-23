#include "data.h"

Data::Data(int day, int mounf, int year){
	this->day_ = day;
	this->mounf_ = mounf;
	this->year_ = year;
}

void Data::ReadDate(istream& ist){
	string buf, buf_day, buf_mounf, buf_year;
	ist >> buf;
	int i = 0;
	while (buf[i] != '.'){
		buf_year += buf[i];
		i++;
	}
	i++;
	while (buf[i] != '.'){
		buf_mounf += buf[i];
		i++;
	}
	i++;
	while (i < buf.size()){
		buf_day += buf[i];
		i++;
	}
	int in_buf_day = stoi(buf_day), in_buf_mounf = stoi(buf_mounf), in_buf_year = stoi(buf_year);
	if ((in_buf_mounf == 1 || in_buf_mounf == 3 || in_buf_mounf == 5 || in_buf_mounf == 7 || in_buf_mounf == 8 || in_buf_mounf == 10 || in_buf_mounf == 12) && in_buf_day > 31 && in_buf_day < 1){
		cout << "ќшибка в поле день" << endl;
		exit(03);
	}
	if ((in_buf_mounf == 4 || in_buf_mounf == 6 || in_buf_mounf == 9 || in_buf_mounf == 11) && in_buf_day > 30 && in_buf_day < 1){
		cout << "ќшибка в поле день" << endl;
		exit(03);

	}
	if (in_buf_mounf == 2){
		if ((in_buf_year % 4 == 0 && in_buf_year % 100 != 0 && in_buf_year % 400 == 0) && in_buf_day > 29 && in_buf_day < 1){
			cout << "ќшибка в дате весокосного года" << endl;
			exit(031);
		}
		else if(in_buf_day > 28){
			cout << "ќшибка в поле день" << endl;
			exit(03);
		}
	}
	if (in_buf_mounf > 12 || in_buf_mounf < 1){
		cout << "ќшибка в поле мес€ц" << endl;
		exit(02);
	}
	if (in_buf_year < 1951 && in_buf_year > 2123){
		cout << "ќшибка в поле год" << endl;
		exit(01);
	}
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