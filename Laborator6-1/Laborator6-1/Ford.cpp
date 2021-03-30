#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Ford.h"
#include <string.h>

Ford::Ford()
{
	this->avgSpeed = new double[3];
	SetFuelCapacity(60);
	SetFuelConsumption(3);
	SetAVGspeed(100, 150, 80);
	strcpy(this->brand, "Ford\0");
}

void Ford::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;
}

void Ford::SetFuelConsumption(double value)
{
	this->fuel_consumption = value;
}

void Ford::SetAVGspeed(double Rainspeed, double Sunnyspeed, double Snowspeed)
{
	this->avgSpeed[Rain] = Rainspeed;
	this->avgSpeed[Sunny] = Sunnyspeed;
	this->avgSpeed[Snow] = Snowspeed;
}

#endif _CRT_SECURE_NO_WARNINGS