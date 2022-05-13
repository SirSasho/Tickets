#pragma once
#include "Event.h"
#include <iostream>
#include <fstream>
#include <vector>
class InformationSystem
{
private:
	std::vector<Event*> events;
	//Event** events;
	//size_t capacity;
	size_t cnt;

	//void copyFrom(const InformationSystem& other);
	void free();
	//void reallocate();

public:
	InformationSystem();
	//InformationSystem(const InformationSystem& other);
	//InformationSystem& operator=(const InformationSystem& other);
	~InformationSystem();

	size_t getCnt() const;
	//size_t getCapacity() const;
	void pushEvent(Event* event);
	void freeSeats(const std::string name, Date& date);
	void reserveTickets(const std::string, Date& date, size_t row, size_t col, std::string password);
	void unReserveTickets(const std::string, Date& date, size_t row, size_t col, std::string password);
	void buyTickets(const std::string, Date& date, size_t row, size_t col);
	std::ostream& listWithReservetion(std::string name, Date& date);
	void helperList(std::ostream& file, size_t k);
	std::ostream& reportForSoldTickets(Hall& hall, Date& date, Date& date1);
	void helperReport1(std::ostream& file, size_t rows, size_t cols, size_t e);
	void helperReport(std::ostream& file, Date& date, Date& date1, size_t rows, size_t cols, size_t e, size_t j);
	
	void print(std::ostream& os = std::cout) const;	
};
