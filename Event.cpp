#include "Event.h"

void Event::copyFrom(const Event& other)
{
    date = other.date;
    hall = other.hall;
    strcpy(this->name, other.name);

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
    delete[] name;
}

Event::Event(const char* name, Date& date, Hall& hall)
    :name(nullptr), date(date), hall(hall), seats(nullptr)
{
    size_t rows = hall.getRows();
    size_t cols = hall.getSeatsByRow();
    setName(name);
    seats = new char* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        seats[i] = new char[cols];
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            seats[i][j] = '2';
        }
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
        //delete[] name;
        copyFrom(other);
    }
    return *this;
}

Event::~Event()
{
    free();
}

void Event::setName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const Date& Event::getDate() const
{
    return date;
}

unsigned Event::getHall() const
{
    return hall.getId();
}

const char* Event::getName()
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
            if (seats[i][j] == '2')
                ++cnt;
        }
    }
    return cnt;
}

char Event::getSeat(size_t row, size_t col)
{
    //правя нов чар* и го присвоявам и връщам него
    //char *temp = &seats[row][col];
    return &seats[row][col];
}

void Event::print() const
{
    std::cout << "Event: " << name << std::endl
        << "Date:" << date << std::endl
        << "Hall: " << hall << std::endl;
}
