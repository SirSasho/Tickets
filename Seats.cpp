#include "Seats.h"

Seats::Seats()
{
	this->password = "";
	this->seatType = seatTypes::empty;
}

Seats::~Seats()
{
	password.clear();
	seatType = seatTypes::empty;
}

