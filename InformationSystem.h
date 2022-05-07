#pragma once
#include "Event.h"
class InformationSystem
{
private:
	Event** events;
	size_t capacity;
	size_t cnt;

	void copyFrom(const InformationSystem& other);
	void free();
	void reallocate();

public:
	InformationSystem();
	InformationSystem(const InformationSystem& other);
	InformationSystem& operator=(const InformationSystem& other);
	~InformationSystem();

	size_t getCnt() const;
	size_t getCapacity() const;
	void pushEvent(Event& event);
	size_t freeSeats(const char* name, Date& date);
	void reserveTickets(const char* name, Date& date, size_t row, size_t col, const char* password);
	void unReserveTickets(const char* name, Date& date, size_t row, size_t col, const char* password);
	void buyTickets(const char* name, Date& date, size_t row, size_t col);
	void print() const;

	
};

std::ostream& operator<<(std::ostream&, const InformationSystem&);
