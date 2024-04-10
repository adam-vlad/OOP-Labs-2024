#pragma once
#include "Car.h"

class Seat : public Car
{
public:
	Seat();
	double timpParcurs(double lungime, Weather vreme) const override;

	void setTimes(bool finished, int secunde);

	std::string getNume() const override { return "Seat"; }
};
