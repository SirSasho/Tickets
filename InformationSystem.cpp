#include "InformationSystem.h"


void InformationSystem::copyFrom(const InformationSystem& other)
{
    capacity = other.capacity;
    cnt = other.cnt;

    events = new Event * [capacity];

    for (size_t i = 0; i < capacity; i++)
    {
        events[i] = new Event(*(other.events[i]));
    }
}

void InformationSystem::free()
{
    for (size_t i = 0; i < cnt; ++i)
    {
        events[i]->Event::~Event();
    }

    delete[] events;
}

void InformationSystem::reallocate()
{
    capacity = cnt * 2;
    Event** newEvents = new Event * [capacity];
    for (size_t i = 0; i < cnt; ++i)
    {
        newEvents[i] = new Event(*(events[i]));
    }
    free();
    events = newEvents;    
}

InformationSystem::InformationSystem()
{
	capacity = 1;
	cnt = 0;
	events = new Event * [capacity];
}

InformationSystem::InformationSystem(const InformationSystem& other)
{
    copyFrom(other);
}

InformationSystem& InformationSystem::operator=(const InformationSystem& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

InformationSystem::~InformationSystem()
{
    free();
}

size_t InformationSystem::getCnt() const
{
    return cnt;
}

size_t InformationSystem::getCapacity() const
{
    return capacity;
}

void InformationSystem::pushEvent(Event& event)
{
    if (capacity < 1)
        reallocate();
    for (size_t i = 0; i < cnt; ++i)
    {
        if (events[i]->getHallId() == event.getHallId() && events[i]->getDate() == event.getDate())
            throw;
    }
    events[cnt++] = &event;
    capacity--;
}

void InformationSystem::freeSeats(const std::string name, Date& date)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if (events[i]->getName() == name && events[i]->getDate() == date)
            std::cout << "Free seats for " << name << " are: " << events[i]->getFreeSeats() << std::endl;
    }   
}

void InformationSystem::reserveTickets(const std::string name, Date& date, size_t row, size_t col, std::string password)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if (events[i]->getName() == name && events[i]->getDate() == date)
        {
            events[i]->updateSeat(row, col, password, seatTypes::reserve);
            std::cout << "Ticket for " << name << " with seat " << row << col << " and password " << password
                << " is successfully reserved!" << std::endl;
        }
    }
}

void InformationSystem::unReserveTickets(const std::string name, Date& date, size_t row, size_t col, std::string password)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if (events[i]->getName() == name && events[i]->getDate() == date
            && events[i]->getSeat(row, col).password == password && events[i]->getSeatType(row, col) == seatTypes::reserve)
        {
            events[i]->updateSeat(row, col, "", seatTypes::empty);
            std::cout << "Ticket for " << name << " with seat " << row << col << " and password " << password
                << " is successfully unreserved!" << std::endl;
        }
        else
        {
            std::cout << "Ticket for " << name << " with seat " << row << col << " is did not reserve!";
        }
            
    }
}

void InformationSystem::buyTickets(const std::string name, Date& date, size_t row, size_t col)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if (events[i]->getName() == name && events[i]->getDate() == date)
        {
            if (events[i]->getSeatType(row, col) != seatTypes::sold)
            {
                if (events[i]->getSeatType(row, col) == seatTypes::empty)
                {
                    events[i]->updateSeat(row, col, "", seatTypes::sold);
                    std::cout << "Ticket for " << name << " with seat " << row << col
                        << " is successfully purchased!" << std::endl;
                }
                else
                {
                    std::string password = "";
                    std::cout << "Enter a password for seat " << row << col << ": ";
                    std::cin >> password;
                    if (events[i]->getSeat(row, col).password == password)
                    {
                        std::cout << "Correct password!" << std::endl;
                        events[i]->updateSeat(row, col, "", seatTypes::sold);
                        std::cout << "Ticket for " << name << " with seat " << row << col
                            << " is successfully purchased!" << std::endl;
                        password.clear();
                    }
                    else
                        std::cout << "Incorrect password!" << std::endl;
                }
            }
            else
            {
                std::cout << "Ticket for " << name << " with seat " << row << col << " is sold!" << std::endl;
            }
        }
        else
        {
            std::cout << "Event with this name or date does not exist!" << std::endl;
        }
                          
    }
}

std::ostream& InformationSystem::listWithReservetion(std::string name, Date& date)
{
    std::ofstream file("name");

    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        
    }
    if (name == "ALL")
    {
        for (size_t i = 0; i < cnt; ++i)
        {
            if (events[i]->getDate() == date)
            {
                size_t rows = events[i]->getHall().getRows();
                size_t cols = events[i]->getHall().getSeatsByRow();
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < cols; j++)
                    {
                        if (events[i]->getSeatType(i, j) == seatTypes::reserve)
                            file << i << j << " ";
                    }
                    file << std::endl;
                }
            }
        }
    }
    else
    {
        for (size_t i = 0; i < cnt; i++)
        {
            if (events[i]->getName() == name && events[i]->getDate() == date)
            {
                size_t rows = events[i]->getHall().getRows();
                size_t cols = events[i]->getHall().getSeatsByRow();
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < cols; j++)
                    {
                        if (events[i]->getSeatType(i, j) == seatTypes::reserve)
                            file << i << j << " ";
                    }
                    file << std::endl;
                }
            }
        }        
    }
    return file;
    file.close();
}


/*
std::ostream& operator<<(std::ostream& out, const InformationSystem& system)
{
}
*/
