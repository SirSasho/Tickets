#include "Date.h"

Date::Date(size_t day, size_t month, size_t year) 
	:day(day), month(month), year(year)
{}

size_t Date::getYear() const
{
	return year;
}

size_t Date::getMonth() const
{
	return month;
}

size_t Date::getDay() const
{
	return day;
}

void Date::print() const
{
	std::cout << day << "." << month << "." << year << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	return out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.getDay() == rhs.getDay() &&
		lhs.getMonth() == rhs.getMonth() &&
		lhs.getYear() == rhs.getYear();
}

bool operator>(const Date& lhs, const Date& rhs)
{
	if (lhs.getYear() > rhs.getYear())
		return true;
	else if(lhs.getYear() == rhs.getYear())
	{
		if (lhs.getMonth() > rhs.getMonth())
		{
			return true;
		}
		else if (lhs.getMonth() == rhs.getMonth())
		{
			if (lhs.getDay() > rhs.getDay())
			{
				return true;
			}			
		}
	}
	else
	{
		return false;
	}	
}
