#pragma once
#include "Car.h"

class Dacia : public Car
{
public:
	Dacia();
	~Dacia() { delete[] avgSpeed; };
	void SetFuelCapacity(int value);
	void SetFuelConsumption(double value);
	void SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed);
};