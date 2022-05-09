#pragma once
#include <string>
enum seatTypes{empty = 0, reserve = 1, sold = 2};
struct Seats
{
	seatTypes seatType;
	std::string password;
	
	Seats();
	~Seats();

};

