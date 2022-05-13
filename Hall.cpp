#include "Hall.h"

Hall::Hall(const unsigned id, const size_t rows, const size_t seatsByRow) 
	:id(id), rows(rows), seatsByRow(seatsByRow)
{}

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

void Hall::print(std::ostream& os) const
{
	os << "Id= " << id << std::endl
		<< "Rows= " << rows << std::endl
		<< "seatsByRow= " << seatsByRow << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Hall& hall)
{
	return out << "Id= " << hall.getId() << std::endl
		<< "Rows= " << hall.getRows() << std::endl
		<< "seatsByRow= " << hall.getSeatsByRow() << std::endl;
}
