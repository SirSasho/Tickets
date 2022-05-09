#pragma once
#include "Hall.h"
#include "Date.h"
#include "Seats.h"
#include <cstring>
class Event
{
private:
	Date& date;
	std::string name;
	Hall& hall;
	Seats** seats;/// 0-free, 1-reserve, 2-sold //

	void copyFrom(const Event& other);
	void free();

public:
	
	Event(const std::string name, Date& date, Hall& hall);
	//Event(const char* name, size_t day, size_t month, size_t year, unsigned id, size_t rows, size_t seatsByRows);
	Event& operator=(const Event& other);
	~Event();


	//void setName(const char* name);
	const Date& getDate() const;
	unsigned getHallId() const;
	Hall& getHall();
	const std::string getName();
	size_t getFreeSeats() const;
	Seats getSeat(size_t row, size_t col);
	seatTypes getSeatType(size_t row, size_t col);

	void updateSeat(size_t row, size_t col, std::string password, seatTypes seatType);


	void print() const;
};

