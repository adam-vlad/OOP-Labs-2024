#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
	Volvo();
	double timpParcurs(double lungime, Weather vreme) const override;

	void setTimes(bool finished, int secunde);

	std::string getNume() const override { return "Volvo"; }
};
