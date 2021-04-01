#pragma once
#include <iostream>

using namespace std;

template <class T>
class vect
{
	T* V;
	int countt;
public:
	vect();
	~vect() { delete[] V; };

	void push(T value);
	T pop();
	void delete(int poz);
	void insert(int poz, T value);
	int count();
	void sort(int (*compara) (T e1, T e2)); //cand se apeleaza cu NULL o sa se sorteze crescator iar cand se apeleaza cu functie o sa se sorteze descrescator
	T get(int poz);
	void set(int poz, T value);
	//int firstIndexOf(T x);
	void print();
	//void schimba(vect<T>& , v)  //functie de interschimbare a unui vector cu alt vector

};

template <class T>
void compara<int>(T a, T b)
{
	if (a > b)
	{
		int aux;
		aux = a;
		a = b;
		b = aux;
	}
}

template <class T>
vect<T>::vect()
{
	V = new T[100];
	countt = 0;
}

template <class T>
void vect<T>::print()
{
	int i;
	for (i = 0; i < countt; i++)
		cout << V[i] << " ";
	cout << endl;
}

template <class T>
void vect<T>::push(T value)
{
	V[countt++] = value;
}

template <class T>
T vect<T>:::pop()
{
	return V[countt - 1];
}

template <class T>
void vect<T>:::delete(int poz);
{
	int i;
	for (i = poz - 1; i < countt - 1; i++)
		V[i] = V[i + 1];
	countt--;
}

template <class T>
void vect<T>:::insert(int poz, T value)
{
	int i;
	if (poz > countt)
		cout << "Pozitia nu se afla in vector" << endl;
	else
	{
		countt++;
		for (i = countt; i >= poz; i++)
			V[i] = V[i - 1];
		V[poz - 1] = value;
	}
}

template <class T>
int vect<T>:::count()
{
	return countt;
}

Template<class T>
void vect<int>::sort(int (*compara) (T e1, T e2));
{
	if(compara == NULL)
	{
		int i, j;
		for( i = 0 ; i < countt-1 ; i++ )
			for( j = i + 1 ; j < countt ; j++ )
				if (V[i] < V[j])
				{
					int aux;
					aux = V[i];
					V[i] = V[j];
					V[j] = V[i];
				}
	}
	Else
	{
		for (i = 0; i < countt - 1; i++)
			for (j = i + 1; j < countt; j++)
				compara(vect[i], vect[j]);
	}
}


template <class T>
T vect<T>::get(int poz)
{
	return V[poz];
}

template <class T>
void vect<T>::set(int poz, T value)
{
	V[poz] = value;
}