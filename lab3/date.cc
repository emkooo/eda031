#include <ctime>  // time and localtime
#include "date.h"
#include <string>
#include <sstream>


#include <iostream>

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    // write obj to stream

    //cout << date på detta objekt skall:
    //outputta innehållet, "dates"
    //på formatet yyyy-mm-dd '\n'
	
		os << d.getYear() << "-";

		if(d.getMonth() < 10)
		{
			os << 0 << d.getMonth() << "-";
		}
		else
		{
			os << d.getMonth();
		}

		if(d.getDay() < 10)
		{
			os << 0 << d.getDay();
		}
		else
		{
			os << d.getDay();
		}
	
    return os;
}

std::istream& operator>>(std::istream& is, Date& d)
{
    std::string in;
	is >> in;
	
	std::stringstream ss;
	ss << in;
	int year;
	int month;
	int day;
	char c1;
	char c2;
	
	ss >> year >> c1 >> month >> c2 >> day;
	
	if (c1 == '-' && c2 == '-'){
		d.year = year;
		d.month = month;
		d.day = day;
	}
	else {
		is.setstate(std::ios::failbit);
	}
	return is;
}

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d; 
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day = day + 1;
	switch(month)
	{
		case 1:
		if (day > 31){
			day = 1;
			month = month + 1;
		}
		break;
		
		case 2:
		if(day > 28){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 3:
		if(day > 31){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 4:
		if(day > 30){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 5:
		if(day > 31){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 6:
		if(day > 30){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 7:
		if(day > 31){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 8:
		if(day > 31){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 9:
		if(day > 30){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 10:
		if(day > 31){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 11:
		if(day > 30){
			day = 1;
			month = month + 1;
		} 
		break;
		
		case 12:
		if(day > 31){
			day = 1;
			month = 1;
			year = year + 1;
		} 
		break;	
	}
}
