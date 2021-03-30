#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Toyota.h"
#include <string.h>

Toyota::Toyota()
{
	this->avgSpeed = new double[3];
	SetFuelCapacity(60);
	SetFuelConsumption(3);
	SetAVGspeed(90, 120, 80);
	strcpy(this->brand, "Toyota\0");
}

void Toyota::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;
}

void Toyota::SetFuelConsumption(double value)
{
	this->fuel_consumption = value;
}

void Toyota::SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed)
{
	this->avgSpeed[Rain] = Rainspeed;
	this->avgSpeed[Sunny] = Sunnyspeed;
	this->avgSpeed[Snow] = Snowspeed;
}

#endif _CRT_SECURE_NO_WARNINGS