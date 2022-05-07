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
    Event** newEvents = new Event * [cnt * 2];
    for (size_t i = 0; i < cnt; ++i)
    {
        newEvents[i] = events[i];
    }
    delete[] events;
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
        if (events[i]->getHall() == event.getHall() && events[i]->getDate() == event.getDate())
            std::cout<<"fail";
    }
    events[cnt++] = &event;
    capacity--;
}

size_t InformationSystem::freeSeats(const char* name, Date& date)
{
    size_t freeSeats = 0;
    for (size_t i = 0; i < cnt; i++)
    {
        if ((strcmp(events[i]->getName(), name)==0) && events[i]->getDate() == date)
            freeSeats += events[i]->getFreeSeats();      
    }

    return freeSeats;
}

void InformationSystem::reserveTickets(const char* name, Date& date, size_t row, size_t col, const char* password)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if ((strcmp(events[i]->getName(), name) == 0) && events[i]->getDate() == date)
            strcpy(events[i]->getSeat(row, col), password);
    }
}

void InformationSystem::unReserveTickets(const char* name, Date& date, size_t row, size_t col, const char* password)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if ((strcmp(events[i]->getName(), name) == 0) && events[i]->getDate() == date 
            && (strcmp(events[i]->getSeat(row, col), password) == 0))
            strcpy(events[i]->getSeat(row, col), "2");
    }
}

void InformationSystem::buyTickets(const char* name, Date& date, size_t row, size_t col)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if ((strcmp(events[i]->getName(), name) == 0) && events[i]->getDate() == date)
            if (events[i]->getSeat(row, col) != "0")
            {
                if (strcmp(events[i]->getSeat(row, col), "2") == 0)
                    strcpy(events[i]->getSeat(row, col), "1");
                else
                {
                    char* password = nullptr;
                    std::cout << "Enter a password: ";
                    std::cin.getline(password, 100);
                    if (strcmp(events[i]->getSeat(row, col), password) == 0)
                        strcpy(events[i]->getSeat(row, col), "1");
                    else
                        std::cout << "Incorect password!" << std::endl;
                }
            }
            else
                std::cout << "Ticket for this seat is sold!" << std::endl;
    }
}

void InformationSystem::print() const
{
    std::cout << events;
}
/*
std::ostream& operator<<(std::ostream& out, const InformationSystem& system)
{
}
*/