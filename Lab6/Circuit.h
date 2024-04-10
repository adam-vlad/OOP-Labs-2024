#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    int count;
    double nrKm;
    Weather vreme;
    Car** masini;

public:
    Circuit();
    ~Circuit();
    void SetLength(double lungime);
    void SetWeather(Weather vreme);
    void AddCar(Car* carAux);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};