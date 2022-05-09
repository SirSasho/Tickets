#include "Event.h"

void Event::copyFrom(const Event& other)
{
    date = other.date;
    hall = other.hall;
    name = other.name;

    size_t rows = hall.getRows();
    size_t cols = hall.getSeatsByRow();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            seats[i][j] = other.seats[i][j];
        }
    }
}

void Event::free()
{
    size_t rows = hall.getRows();
    for (size_t i = 0; i < rows; ++i)
    {
        delete seats[i];
    }
    delete[] seats;
    
    name.clear();            //delete[] name;
}

Event::Event(const std::string name, Date& date, Hall& hall)
    :name(""), date(date), hall(hall), seats(nullptr)
{
    size_t rows = hall.getRows();
    size_t cols = hall.getSeatsByRow();
    this->name = name;//setName(name)
    seats = new Seats * [rows];
    for (size_t i = 0; i < rows; i++)
    {
        seats[i] = new Seats[cols];
    }
}

/*Event::Event(const char* name, size_t day, size_t month, size_t year, unsigned id, size_t cows, size_t seatsByCows) 
    :name(nullptr), date(day, month, year), hall(id, cows, seatsByCows)
{
    setName(name);
}*/

Event& Event::operator=(const Event& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Event::~Event()
{
    free();
}
/*
void Event::setName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
*/
const Date& Event::getDate() const
{
    return date;
}

unsigned Event::getHallId() const
{
    return hall.getId();
}

Hall& Event::getHall()
{
    return hall;
}

const std::string Event::getName()
{
    return name;
}

size_t Event::getFreeSeats() const
{
    size_t cnt = 0;
    size_t rows = hall.getRows();
    size_t cols = hall.getSeatsByRow();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (seats[i][j].seatType == seatTypes::empty)
                ++cnt;
        }
    }
    return cnt;
}

Seats Event::getSeat(size_t row, size_t col)
{
    return seats[row][col];
}

seatTypes Event::getSeatType(size_t row, size_t col)
{
    return seats[row][col].seatType;
}

void Event::updateSeat(size_t row, size_t col, std::string password, seatTypes seatType)
{
    this->seats[row][col].password = password;
    this->seats[row][col].seatType = seatType;
}

void Event::print() const
{
    std::cout << "Event: " << name << std::endl
        << "Date:" << date << std::endl
        << "Hall: " << hall << std::endl;
}
