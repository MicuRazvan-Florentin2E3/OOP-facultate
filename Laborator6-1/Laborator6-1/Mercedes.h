#pragma once
#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes();
	~Mercedes() { delete[] avgSpeed; };
	void SetFuelCapacity(int value);
	void SetFuelConsumption(double value);
	void SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed);
};