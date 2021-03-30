#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Mercedes.h"
#include <string.h>

Mercedes::Mercedes()
{
	this->avgSpeed = new double[3];
	SetFuelCapacity(60);
	SetFuelConsumption(2);
	SetAVGspeed(90, 140, 70);
	strcpy(this->brand, "Mercedes\0");
}

void Mercedes ::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;
}

void Mercedes::SetFuelConsumption(double value)
{
	this->fuel_consumption = value;
}

void Mercedes::SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed)
{
	this->avgSpeed[Rain] = Rainspeed;
	this->avgSpeed[Sunny] = Sunnyspeed;
	this->avgSpeed[Snow] = Snowspeed;
}

#endif _CRT_SECURE_NO_WARNINGS