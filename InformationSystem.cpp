#include "InformationSystem.h"

/*
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
*/
void InformationSystem::free()
{
    for (size_t i = 0; i < cnt; ++i)
    {
        events[i]->~Event();
        //delete events[i];
    }

    events.clear();
}
/*
void InformationSystem::reallocate()
{
    capacity = cnt * 2;
    Event** newEvents = new Event * [capacity];
    for (size_t i = 0; i < cnt; ++i)
    {
        newEvents[i] = events[i];
    }
    free();
    events = newEvents;        
}
*/
InformationSystem::InformationSystem()
{
	//capacity = 1;
	cnt = 0;
    events = {};
}
/*
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
*/
InformationSystem::~InformationSystem()
{
    free();
}

size_t InformationSystem::getCnt() const
{
    return cnt;
}
/*
size_t InformationSystem::getCapacity() const
{
    return capacity;
}
*/
void InformationSystem::pushEvent(Event* event)
{
  //  if (events.size() == cnt)
     //   events.resize(cnt * 2);
        //reallocate();
    for (size_t i = 0; i < cnt; ++i)
    {
        if (events[i]->getHallId() == event->getHallId() && events[i]->getDate() == event->getDate())
            throw;
    }
    events.push_back(event);
    ++cnt;
    //events[cnt++] = new Event(event);
    std::cout << "Pushed event!" << std::endl;
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
    }
}

std::ostream& InformationSystem::listWithReservetion(std::string name, Date& date)
{
    std::ofstream file(name);
    
   
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        throw;
        
    }
    if (name == "ALL")
    {
        for (size_t k = 0; k < cnt; ++k)
        {
            if (events[k]->getDate() == date)
            {
                helperList(file, k);
            }
        }
    }
    else
    {
        for (size_t k = 0; k < cnt; k++)
        {
            if (events[k]->getName() == name && events[k]->getDate() == date)
            {
                helperList(file, k);
            }
        }        
    }
    return file;
    file.close();
}

void InformationSystem::helperList(std::ostream& file, size_t k)
{
    size_t rows = events[k]->getHall().getRows();
    size_t cols = events[k]->getHall().getSeatsByRow();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (events[k]->getSeatType(i, j) == seatTypes::reserve)
            {
                file << "|" << i << j << "|";
            }
            else
            {
                file << "|  |";
            }
        }
        file << std::endl;
    }
    file << std::endl;
}

std::ostream& InformationSystem::reportForSoldTickets(Hall& hall, Date& date, Date& date1)
{
    
    //if (date > date1)
      //  throw std::exception("Incorrect period!\n");

    std::ofstream file("report for sold tickets.txt");
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
    }
    for (size_t e = 0; e < cnt; e++)
    {
        if (events[e]->getHallId() == hall.getId())
        {
            size_t rows = events[e]->getHall().getRows();
            size_t cols = events[e]->getHall().getSeatsByRow();
            for (size_t i = date.getYear(); i <= date1.getYear(); i++)
            {
                if (events[e]->getDate().getYear() == i)
                {
                    if (date.getYear() == date1.getYear())
                    {
                        file << "year: " << i;
                        for (size_t j = date.getMonth(); j <= date1.getMonth(); j++)
                        {
                            helperReport(file, date, date1, rows, cols, e, j);
                        }
                    }  
                    else if (i < date1.getYear())
                    {
                        file << "year: " << i;
                        for (size_t j = 1; j <= 12; j++)
                        {
                            helperReport(file, date, date1, rows, cols, e, j);
                        }
                    }
                    else
                    {
                        file << "year: " << i;
                        for (size_t j = 1; j <= date1.getMonth(); j++)
                        {
                            helperReport(file, date, date1, rows, cols, e, j);
                        }
                    }
                }                
            }
        }
    }
    return file;
    file.close();
}

void InformationSystem::helperReport(std::ostream& file, Date& date, Date& date1, size_t rows, size_t cols, size_t e, size_t j)
{
    if (events[e]->getDate().getMonth() == j)
    {
        file << " month: " << j;
        if (date.getMonth() == date1.getMonth())
        {
            for (size_t k = date.getDay(); k <= date1.getDay(); k++)
            {
                if (events[e]->getDate().getDay() == k)
                {
                    file << " day: " << k << std::endl;
                    helperReport1(file, rows, cols, e);
                }
            }
        }
        else if (j < date1.getMonth())
        {
            for (size_t k = 1; k <= 31; k++)
            {
                if (events[e]->getDate().getDay() == k)
                {
                    file << " day: " << k << std::endl;
                    helperReport1(file, rows, cols, e);
                }
            }
        }
        else
        {
            for (size_t k = 1; k <= date1.getDay(); k++)
            {
                if (events[e]->getDate().getDay() == k)
                {
                    file << " day: " << k << std::endl;
                    helperReport1(file, rows, cols, e);
                }
            }
        }
    }
}

void InformationSystem::printStatisticsForTheMostWatchedEvents(std::ostream& os)
{
    for (size_t i = 0; i < cnt - 1; ++i)
    {
        size_t min = i;
        for (size_t j = i + 1; j < cnt; ++j)
        {
            if (events[j]->soldSeats() > events[min]->soldSeats())
                std::swap(events[min], events[j]);
        }               
    }
    for (size_t i = 0; i < cnt; i++)
    {
        os << "Event: " << events[i]->getName() << " is with " << events[i]->soldSeats() << " sold seats" << std::endl;;
    }
}

void InformationSystem::helperReport1(std::ostream& file, size_t rows, size_t cols, size_t e)
{
    size_t sold = 0;
    
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            if (events[e]->getSeatType(r, c) == seatTypes::sold)
            {
                file << "|" << r << c << "|";
                ++sold;
            }
            else
            {
                file << "|  |";
            }
        }
        file << std::endl;
    }
    file << "Event: " << events[e]->getName() << " with sold tickets: " << sold << std::endl;
}

void InformationSystem::print(std::ostream& os) const
{
    for (size_t i = 0; i < cnt; i++)
    {
        os << "Event: " << events[i]->getName() <<" Date: " << events[i]->getDate().getDay() << "." << events[i]->getDate().getMonth() << "."
            << events[i]->getDate().getYear() << std::endl;
    }
}
