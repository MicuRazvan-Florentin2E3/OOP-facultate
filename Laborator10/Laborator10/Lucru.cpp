#include "Lucru.h"

using namespace std;

int binarySearchh(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearchh(arr, l, mid - 1, x);
		return binarySearchh(arr, mid + 1, r, x);
	}
	return -1;
}

template<class T>
Array::Array()	// Lista nu e alocata, Capacity si Size = 0
{
	Size = 0; 
	Capacity = 0; 
}

template<class T>
Array::~Array()		// destructor
{
	delete[] List;
}

template<class T>
Array::Array(int capacity)		// Lista e alocata cu 'capacity' elemente
{
	List = new T[capacity]; 
}

/*template<class T>
Array(const Array<T>& otherArray)		// constructor de copiere
{

}*/

template<class T>
Array::T& operator[] (int index)		// arunca exceptie daca index este out of range
{
	if (index < 0 || index >= size) {
		throw IndexException();
	}
	return v[index];
}

template<class T>
const Array<T>& Array::operator+= (const T& newElem)   // adauga un element de tipul T la sfarsitul listei si returneaza this
{
	List[Size++] = newElem;
	return this;
}

template<class T>
const Array<T>& Array::Insert(int index, const T& newElem);		// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
{
	if (index < size || index >= size || index + size > Capacity) {
		throw IndexException();
	}
	size++;
	for (int i = size + 1; i > index; i--)
		List[i] = List[i - 1];
	List[index] = newElem;
	return this;
}

template<class T>
const Array<T>& Array::Insert(int index, const Array<T> otherArray);	// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
{
	if (index < size || index >= size || index + size > Capacity) {
		throw IndexException();
	}
	size = size + otherArray.size;
	for (int i = 1; i <= otherArray.size; i++)
	{
		List[size - i] = List[size - i - index];
	}
	i = 0;
	for (int j = 1; j <= otherArray.size; j++)
	{
		List[index + i] = otherArray.List[i];
		i++;
	}
	return this; 
}

template<class T>
const Array<T>& Array::Delete(int index);	// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
{
	if (index < size || index >= size) {
		throw IndexException();
	}
	size--;
	for (int i = index; i < size; i--)
		List[i] = List[i + 1];
	return this;
}

template<class T>
void Array::operator= (const Array<T>& otherArray);
{
	size = otherArray.size;
	for (int i = 0; i < size; i++)
		List[i] = otherArray.List[i];
}

template<class T>
void Array::Sort()
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (List[j] > List[j + 1])
			{
				temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
}

template<class T>
void Array::Sort(int(*compare)(const T&, const T&))
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (compare(List[j],List[j+1]) == 1)
			{
				temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
}

template<class T>
int Array::BinarySearch(const T& elem); // cauta un element folosind binary search in Array
{
	int a = BinarySearchh(List, 0, size, elem);
	return a;
}

template<class T>
int Array::find(const T& elem)
{
	for (int i = 0; i < size; i++)
		if (elem == List[i])
			return i;
	return -1;
}

template<class T>
int Array::GetSize()
{
	return size;
}

template<class T>
int Array::GetCapacity()
{
	return Capacity;
}