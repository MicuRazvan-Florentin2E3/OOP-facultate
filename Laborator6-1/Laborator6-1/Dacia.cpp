#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Dacia.h"
#include <string.h>

Dacia::Dacia()
{
	this->avgSpeed = new double[3];
	SetFuelCapacity(40);
	SetFuelConsumption(5);
	SetAVGspeed(80, 90, 70);
	strcpy(this->brand, "Dacia\0");
}

void Dacia::SetFuelCapacity(int value)
{
	this->fuel_capacity = value;
}

void Dacia::SetFuelConsumption(double value)
{
	this->fuel_consumption = value;
}

void Dacia::SetAVGspeed(double Rainspeed , double Sunnyspeed, double Snowspeed)
{
	this->avgSpeed[Rain] = Rainspeed;
	this->avgSpeed[Sunny] = Sunnyspeed;
	this->avgSpeed[Snow] = Snowspeed;
}

#endif _CRT_SECURE_NO_WARNINGS