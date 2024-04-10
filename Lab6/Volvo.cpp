#include "Volvo.h"
#include <iostream>

Volvo::Volvo() : Car()
{
	this->rezervor = 70;
	this->consum = 10;
	this->vitRain = 170;
	this->vitSnow = 150;
	this->vitSunny = 210;
}

double Volvo::timpParcurs(double lungime, Weather vreme) const
{
	if (areBenzina(lungime)) {
		double vitMedie = 0;
		if (vreme == Weather::Sunny) vitMedie = vitSunny;
		else if (vreme == Weather::Rain) vitMedie = vitRain;
		else if (vreme == Weather::Snow) vitMedie = vitSnow;
		else printf("eroare vreme\n");

		this->finished = true;
		this->secunde = (int)(lungime * 3600 / vitMedie);

		return lungime * 3600 / vitMedie; // timpul in secunde
	}
	else
	{
		this->finished = false;
		this->secunde = 0;
		return 0.0f;
	}

}