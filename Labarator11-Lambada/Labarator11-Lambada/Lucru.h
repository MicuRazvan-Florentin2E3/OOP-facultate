#pragma once
#include <iostream>

using namespace std;

//ex3:
class MyVector {
	int* V;
	int Size, Capacity;
public:
	MyVector(int nr);
	~MyVector();
	bool Add(int a);		//return true if the value was added. As a result, the size of the vector increases with one.
	bool Delete(int index); // return true if the value from index was removed. As a result, the sife of the vector decreases with one.
	void Iterate(int(*functie1)(int&));
	void Filter(bool(*functie2)(int));
	void Print();

};

MyVector::MyVector(int nr) {
	V = new int[nr];
	Size = 0;
	Capacity = 25;
}

MyVector::~MyVector() {
	delete[] V;
}

bool MyVector::Add(int a) {
	if (Size + 1 > Capacity)
		return 0;
	V[Size++] = a;
	return 1;
}

bool MyVector::Delete(int index) {
	if (index < Size)
	{
		for (int i = index; i < Size - 1; i++)
			V[i] = V[i+1];
		Size--;
		return 1;
	}
	return 0;
}

void MyVector::Iterate(int(*functie1)(int&))
{
	for (int i = 0; i < Size; i++)
		V[i] = functie1(V[i]);
}

void MyVector::Filter(bool(*functie2)(int))
{
	for (int i = 0; i < Size; i++)
		if (functie2(V[i]))
			Delete(i);

}

void MyVector::Print()
{
	for (int i = 0; i < Size; i++) {
		cout << V[i] << " ";
	}
	cout << endl;
}