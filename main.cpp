#include "Hall.h"
#include "Date.h"
#include "Event.h"
#include "InformationSystem.h"

int main()
{
	Hall hall1(1, 5, 5);
	Hall hall2(2, 10, 6);	
	
	Date date1(16, 8, 2019);
	Date date2(18, 9, 2020);
	Date date3(20, 11, 2020);

	Event event1("sasho1",date1, hall1);
	Event event2("sasho2",date2, hall1);
	Event event3("sasho3",date3, hall1);	

	InformationSystem system;
	system.pushEvent(&event1);
	system.pushEvent(&event2);
	system.pushEvent(&event3);
	
	system.reserveTickets("sasho1", date1, 3, 2, "h");
	system.reserveTickets("sasho1", date1, 1, 4, "h");
	system.reserveTickets("sasho1", date1, 0, 0, "h");
	system.reserveTickets("sasho1", date1, 0, 1, "h");
	system.reserveTickets("sasho1", date1, 0, 2, "h");
	system.reserveTickets("sasho1", date1, 0, 3, "h");
	system.reserveTickets("sasho1", date1, 0, 4, "h");
	system.reserveTickets("sasho2", date2, 2, 1, "h");
	system.reserveTickets("sasho2", date2, 4, 1, "h");
	system.reserveTickets("sasho2", date2, 2, 2, "h");
	system.reserveTickets("sasho1", date1, 3, 1, "h");
	
	system.buyTickets("sasho1", date1, 3, 2);
	system.buyTickets("sasho1", date1, 0, 2);
	system.buyTickets("sasho2", date2, 3, 1);
	system.buyTickets("sasho2", date2, 2, 1);
	system.buyTickets("sasho1", date1, 2, 4);
	system.buyTickets("sasho3", date3, 2, 2);
	system.buyTickets("sasho3", date3, 2, 0);
	system.buyTickets("sasho3", date3, 1, 0);
	system.buyTickets("sasho3", date3, 3, 0);
	system.buyTickets("sasho3", date3, 4, 0);
	system.buyTickets("sasho3", date3, 2, 4);
	
	//system.unReserveTickets("sasho1", date1, 3, 2, "h");
	//system.reportForSoldTickets(hall1, date1, date3);
	//system.listWithReservetion("ALL", date1);
	//system.printStatisticsForTheMostWatchedEvents();

	return 0;
}
