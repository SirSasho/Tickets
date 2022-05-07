#include "Hall.h"

Hall::Hall(const unsigned id, const size_t rows, const size_t seatsByRow) 
	:id(id), rows(rows), seatsByRow(seatsByRow)
{}

Hall& Hall::operator=(const Hall & other)
{
	if (this != &other)
	{
		id = other.id;
		rows = other.rows;
		seatsByRow = other.seatsByRow;
	}

	return *this;
}

unsigned Hall::getId() const
{
	return id;
}

size_t Hall::getRows() const
{
	return rows;
}

size_t Hall::getSeatsByRow() const
{
	return seatsByRow;
}

size_t Hall::getSeats() const
{
	return rows * seatsByRow;
}

void Hall::print() const
{
	std::cout << "Id= " << id << std::endl
		<< "Rows= " << rows << std::endl
		<< "seatsByRow= " << seatsByRow << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Hall& hall)
{
	return out << hall.getId() << " " << hall.getRows() << " " << hall.getSeatsByRow() << std::endl;
}
