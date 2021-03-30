#pragma once
#include "Car.h"

class Toyota : public Car
{
public:
	Toyota();
	~Toyota() { delete[] avgSpeed; };
	void SetFuelCapacity(int value);
	void SetFuelConsumption(double value);
	void SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed);
};