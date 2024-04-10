#pragma once
#include "Weather.h"
#include <iostream>

class Car {
public:
	double rezervor;
	double consum;
	double vitSunny;
	double vitRain;
	double vitSnow;
	mutable bool finished;
	mutable int secunde;
public:
	Car() {};

	virtual double timpParcurs(double lungime, Weather vreme) const = 0;

	virtual std::string getNume() const = 0;


	bool areBenzina(double distanta) const {
		if ((distanta * consum) / 100 <= rezervor) return true;
		else return false;
	}

	void benzinaConsumata(double distanta) {
		rezervor = rezervor - consum * distanta;
	}

	double capcitateRezervor() {
		return rezervor;
	}

	double consumMasina() {
		return consum;
	}
};