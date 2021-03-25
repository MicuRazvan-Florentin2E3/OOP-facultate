#pragma once
#include "Weather.h"

class Car
{
	int fuel_capacity;
	double fuel_consumption;
	double average_speed;
public:
	Car() { avgSpeed = new double[3]; };
	~Car() { delete[] avgSpeed; }

};