#include "Circuit.h"
#include "Weather.h"

Circuit::Circuit()
{
	this->count = 0;
	this->masini = new Car * [100];
	this->nrKm = 0;
	this->vreme = Weather::null;
}

Circuit::~Circuit()
{
	delete[] masini;
}

void Circuit::SetLength(double lungime)
{
	this->nrKm = lungime;
}

void Circuit::SetWeather(Weather vreme)
{
	this->vreme = vreme;
}

void Circuit::AddCar(Car* carAux)
{
	masini[this->count] = carAux;
	this->count++;
}

void Circuit::Race()
{
	for (int i = 0; i < count; i++)
		masini[i]->timpParcurs(this->nrKm, this->vreme);
}

void Circuit::ShowFinalRanks()
{
	int finalisti[100], k = 0;

	for (int i = 0; i < count; i++)
		if (masini[i]->finished)
			finalisti[k++] = i;


	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (masini[finalisti[i]]->secunde > masini[finalisti[j]]->secunde)
				std::swap(finalisti[i], finalisti[j]);

	for (int i = 0; i < k; i++)
	{
		printf("%s a terminat in %d minute si %d secunde\n",
			masini[finalisti[i]]->getNume().c_str(),
			masini[finalisti[i]]->secunde / 60,
			masini[finalisti[i]]->secunde % 60);
	}

}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < count; i++)
		if (!masini[i]->finished)
			printf("%s nu a terminat cursa \n", masini[i]->getNume().c_str());
}