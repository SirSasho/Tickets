#pragma once
#include "Hall.h"
#include "Date.h"
class Event
{
private:
	Date& date;
	char* name;
	Hall& hall;
	char** seats; /// 2-free, 1-reserve, 0-sold //

	void copyFrom(const Event& other);
	void free();

public:
	Event(const char* name, Date& date, Hall& hall);
	//Event(const char* name, size_t day, size_t month, size_t year, unsigned id, size_t rows, size_t seatsByRows);
	Event& operator=(const Event& other);
	~Event();


	void setName(const  char* name);
	const Date& getDate() const;
	unsigned getHall() const;
	const char* getName();
	size_t getFreeSeats() const;
	char  getSeat(size_t row, size_t col);


	void print() const;
};

