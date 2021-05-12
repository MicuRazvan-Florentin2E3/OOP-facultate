#include <iostream>
#include "Lucru.h"

using namespace std;

template<class T>
int Array<T>::compare(const T& a, const T& b){
	if (a == b)
		return -1;
	return a > b;
}

template<class T>
Array<T>::Array(int nr){
	Size = 0; 
	Capacity = nr; 
}

template<class T>
Array<T>::~Array(){
	delete[] List;
}

template<class T>
Array<T>::Array(){
	List = new T[Capacity]; 
}

template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
	otherArray.Size = Size;
	otherArray.Capacity = Capacity;
	for (int i = 0; i < Size; i++)
		otherArray.List[i] = List[i];
}

template<class T>
T& Array<T>::operator[] (int index){
	if (index < 0 || index >= Size) {
		throw IndexException();
	}
	return List[index];
}

template<class T>
const Array<T>& Array<T>::operator+= (const T& newElem){
	if(Size + 1 > Capacity)
	{
		throw SizeException();
	}
	else
		List[Size++] = newElem;
	return this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem){
	if (index < Size || index >= Size) 
	{
		throw IndexException();
	}
	else
		if (Size + 1 > Capacity)
		{
			throw SizeException();
		}
	Size++;
	for (int i = Size - 1; i > index; i--)
		List[i] = List[i - 1];
	List[index] = newElem;
	return this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)	{
	if (index < 0 || index >= Size) {
		throw IndexException();
	}
	else
		if (Size + otherArray.Size > Capacity)
		{
			throw SizeException();
		}
	Size = Size + otherArray.Size;
	int i;
	for (i = 1; i <= otherArray.Size; i++)
	{
		List[Size - i] = List[Size - i - index];
	}
	i = 0;
	for (int j = 1; j <= otherArray.Size; j++)
	{
		List[index + i] = otherArray.List[i];
		i++;
	}
	return this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)	{
	if (index < 0 || index >= Size) 
	{
		throw IndexException();
	}
	Size--;
	for (int i = index; i < Size; i--)
		List[i] = List[i + 1];
	return this;
}

template<class T>
void Array<T>::operator= (const Array<T>& otherArray){
	Capacity = otherArray.Capacity;
	size = otherArray.Size;
	for (int i = 0; i < Size; i++)
		List[i] = otherArray.List[i];
}

template<class T>
void Array<T>::Sort(){
	int i, j, temp;
	for (i = 0; i < Size - 1; i++)
		for (j = 0; j < Size - i - 1; j++)
			if (List[j] > List[j + 1])
			{
				temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
}


template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&)){
	int i, j, temp;
	for (i = 0; i < Size - 1; i++)
		for (j = 0; j < Size - i - 1; j++)
			if (compare(List[j] , List[j + 1]) == 0)
			{
				temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
}

template<class T>
void Array<T>::Sort(Comparee comparator){
	int i, j, temp;
	for (i = 0; i < Size - 1; i++)
		for (j = 0; j < Size - i - 1; j++)
			if (comparator.CompareElements(List[j], List[j+1]) == 1)
			{
				temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
}

template<class T>
int Array<T>::BinarySearch(const T& elem) {
	int l = 0, r = Size - 1, mid;
	while (l <= r)
	{
		mid = (l + r ) / 2;
		if (List[mid] == elem)
			return mid;
		if (List[mid] > elem)
			r = mid;
		else
			l = mid+1;
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
	int l = 0, r = Size - 1, mid;
	while (l <= r)
	{
		mid = (l + r ) / 2;
		if (compare(List[mid], elem) == -1)
			return mid;
		if (compare(List[mid], elem) == 1)
			r = mid;
		else
			l = mid+1;
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Comparee comparator) {
	int l = 0, r = Size - 1, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (comparator.CompareElements(elem, List[mid]) == -1)
			return mid;
		if (comparator.CompareElements(elem, List[mid]) == 1)
			r = mid;
		else
			l = mid + 1;
	}
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem){
	for (int i = 0; i < Size; i++)
		if (elem == List[i])
			return i;
	return -1;
}

template<class T>
int Array<T>::Find(int(*compare)(const T&, const T&), const T& elem){
	for (int i = 0; i < Size; i++)
		if (compare(elem , List[i]) == -1)
			return i;
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, Comparee comparator)
{
	for (int i = 0; i < Size; i++)
	{
		if (comparator.CompareElements(elem, List[i]) == 1)
			return i;
	}
	return -1;
}

template<class T>
int Array<T>::GetSize(){
	return Size;
}

template<class T>
int Array<T>::GetCapacity(){
	return Capacity;
}

template<class T>
void Array<T>::Print(){
	for (int i = 0; i < Size; i++)
		cout << List[i] << " ";
	cout << endl;
}