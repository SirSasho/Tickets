#include "Hall.h"
#include "Date.h"
#include "Event.h"
#include "InformationSystem.h"

int main()
{
	Hall hall1(1, 5, 5);
//	Hall hall2(2, 30, 10);
	
	//hall1.print();
	Date date1(22, 10, 2020);
//	Date date2(23, 10, 2020);
//	Date date3(25, 10, 2020);
	
	Event event1("sasho",date1, hall1);
	std::cout << event1.getSeat(2, 2);
	//std::cout << event1.getFreeSeats();
//	Event event2("sasho",date1, hall2);
//	Event event3("sasho",date3, hall1);
	//Event event4("sasho",date3, hall1);
	//event1.print();

//	
	//std::cout << event1.getFreeSeats() <<std::endl;
	//InformationSystem system;
//	system.pushEvent(event1);
	//system.reserveTickets("sasho", date1, 3, 2, "hello");
	//std::cout << event1.getFreeSeats() << std::endl;
	//system.unReserveTickets("sasho", date1, 3, 2, "hello");
//	std::cout << event1.getFreeSeats() << std::endl;

//	system.buyTickets("sasho", date1, 2, 2);
	//system.buyTickets("sasho", date1, 2, 2);
//	system.pushEvent(event2);
	//std::cout << system.freeSeats("sasho", date1);
//	system.pushEvent(event3);

	//std::cout<<system.getCnt();
	

	return 0;
}