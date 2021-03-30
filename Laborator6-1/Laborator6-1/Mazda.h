#pragma once
#include "Car.h"

class Mazda : public Car
{
public:
	Mazda();
	~Mazda() { delete[] avgSpeed; };
	void SetFuelCapacity(int value);
	void SetFuelConsumption(double value);
	void SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed);
};