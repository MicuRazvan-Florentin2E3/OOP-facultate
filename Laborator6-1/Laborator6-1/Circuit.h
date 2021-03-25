#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
	int Lenght;
	char Weather weather;
public:
	Circuit();
	void SetLength(int value);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShwoFinalRanks();
	void ShowWhoDidNotFinish();
};