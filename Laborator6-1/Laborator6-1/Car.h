#pragma once
#include "Weather.h"

class Car
{
public:
	int fuel_capacity;
	double fuel_consumption;
	double* avgSpeed;
	char brand[50];
public:
	Car() { avgSpeed = new double[3]; };
	~Car() { delete[] avgSpeed; };
	virtual void SetFuelCapacity(int value);
	virtual void SetFuelConsumption(double value);
	virtual void SetAVGspeed(weather w);
};