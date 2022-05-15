#pragma once
#pragma warning (disable : 4996)
#include <iostream>
class Hall
{
private:
	unsigned id;
	size_t rows;
	size_t seatsByRow;
	
public:
	Hall(const unsigned, const size_t, const size_t);
	
	unsigned getId() const;
	size_t getRows() const;
	size_t getSeatsByRow() const;
	size_t getSeats() const;

	void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream&, const Hall&);
