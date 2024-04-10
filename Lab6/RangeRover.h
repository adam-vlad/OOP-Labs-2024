#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
	RangeRover();
	double timpParcurs(double lungime, Weather vreme) const override;

	void setTimes(bool finished, int secunde);

	std::string getNume() const override { return "RangeRover"; }
};
