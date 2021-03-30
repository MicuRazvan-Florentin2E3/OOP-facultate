#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
	int Lenght, NrMasini = 0;
	weather c_w;
	Car cars[15];
public:
	Circuit();

	void SetLength(int value);
	void SetWeather(weather w);
	void AddCar(Car* masina);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
};