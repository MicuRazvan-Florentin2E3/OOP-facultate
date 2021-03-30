#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Mazda.h"
#include <string.h>

Mazda::Mazda()
{
	this->avgSpeed = new double[3];
	SetFuelCapacity(55);
	SetFuelConsumption(6);
	SetAVGspeed(105, 130, 85);
	strcpy(this->brand, "Mazda\0");
}

void Mazda::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;
}

void Mazda::SetFuelConsumption(double value)
{
	this->fuel_consumption = value;
}

void Mazda::SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed)
{
	this->avgSpeed[Rain] = Rainspeed;
	this->avgSpeed[Sunny] = Sunnyspeed;
	this->avgSpeed[Snow] = Snowspeed;
}

#endif _CRT_SECURE_NO_WARNINGS