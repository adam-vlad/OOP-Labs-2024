#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
	Fiat();
	double timpParcurs(double lungime, Weather vreme) const override;

	void setTimes(bool finished, int secunde);

	std::string getNume() const override { return "Fiat"; }
};
