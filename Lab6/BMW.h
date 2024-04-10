#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	double timpParcurs(double lungime, Weather vreme) const override;

	void setTimes(bool finished, int secunde);

	std::string getNume() const override { return "BMW"; }
};
