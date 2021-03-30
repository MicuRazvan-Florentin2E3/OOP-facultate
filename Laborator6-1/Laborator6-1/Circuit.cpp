#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Circuit.h"
#include <string.h>
#include <iostream>

using namespace std;

int i;

void swapp(Car a, Car b)
{
	Car aux;

	aux.fuel_capacity = a.fuel_capacity;
	aux.fuel_consumption = a.fuel_consumption;
	aux.avgSpeed[Rain] = a.avgSpeed[Rain];
	aux.avgSpeed[Sunny] = a.avgSpeed[Sunny];
	aux.avgSpeed[Snow] = a.avgSpeed[Snow];
	strcpy(aux.brand, a.brand);

	a.fuel_capacity = b.fuel_capacity;
	a.fuel_consumption = b.fuel_consumption;
	a.avgSpeed[Rain] = b.avgSpeed[Rain];
	a.avgSpeed[Sunny] = b.avgSpeed[Sunny];
	a.avgSpeed[Snow] = b.avgSpeed[Snow];
	strcpy(a.brand, b.brand);

	b.fuel_capacity = aux.fuel_capacity;
	b.fuel_consumption = aux.fuel_consumption;
	b.avgSpeed[Rain] = aux.avgSpeed[Rain];
	b.avgSpeed[Sunny] = aux.avgSpeed[Sunny];
	b.avgSpeed[Snow] = aux.avgSpeed[Snow];
	strcpy(b.brand, aux.brand);
}

Circuit::Circuit() {}

void Circuit::SetLength(int value)
{
	this->Lenght = value;
}

void Circuit::SetWeather(weather w)
{
	c_w = w;
}

void Circuit::AddCar(Car* masina)
{
	this->NrMasini++;
	this->cars[NrMasini].fuel_capacity = masina->fuel_capacity;
	this->cars[NrMasini].fuel_consumption = masina->fuel_consumption;
	this->cars[NrMasini].avgSpeed[Rain] = masina->avgSpeed[Rain];
	this->cars[NrMasini].avgSpeed[Sunny] = masina->avgSpeed[Sunny];
	this->cars[NrMasini].avgSpeed[Snow] = masina->avgSpeed[Snow];
	strcpy(this->cars[NrMasini].brand, masina->brand);
	delete[] masina;

}

void Circuit::Race()
{
	int j;
	for (i = 0; i < NrMasini - 1; i++)
		for (j = i + 1; j <= NrMasini - 1; j++)
			if (cars[i].avgSpeed[c_w] < cars[j].avgSpeed[c_w])
				swapp(cars[i], cars[j]);
}

void Circuit::ShowFinalRanks()
{
	int loc = 0;
	cout << "Final ranks: " << endl;
	for (i = 0; i < NrMasini; i++)
		if (cars[i].fuel_capacity * 100 / cars[i].fuel_consumption >= this->Lenght)
		{
			loc++;
			cout << "locul " << loc << ": " << cars[i].brand << endl;
		}
}

void Circuit::ShowWhoDidNotFinis()
{
	cout << "Masini care nu au terminat cursa: " << endl;
	for( i = 0 ; i < NrMasini ; i++ )
		for (i = 0; i < NrMasini; i++)
			if (cars[i].fuel_capacity * 100 / cars[i].fuel_consumption >= this->Lenght)
				cout << cars[i].brand << endl;
}

#endif _CRT_SECURE_NO_WARNINGS