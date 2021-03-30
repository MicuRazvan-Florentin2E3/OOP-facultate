#pragma once
#include "Car.h"

class Ford : public Car
{
public:
	Ford();
	~Ford() { delete[] avgSpeed; };
	void SetFuelCapacity(int value);
	void SetFuelConsumption(double value);
	void SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed);
};