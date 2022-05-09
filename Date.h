#pragma once
#include <iostream>
class Date
{
private:
	size_t year;
	size_t month;
	size_t day;
	
public:
	Date(size_t day, size_t month, size_t year);
	

	size_t getYear() const;
	size_t getMonth() const;
	size_t getDay() const;

	void print() const;
};

std::ostream& operator<<(std::ostream&, const Date&);
bool operator==(const Date& lhs, const Date& rhs);
