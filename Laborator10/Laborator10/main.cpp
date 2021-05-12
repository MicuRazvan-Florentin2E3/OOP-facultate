#include <iostream>
#include "Lucru.h"

using namespace std;

int main()
{
	Array<int> V(25);
	Array<int> A(25);

	A += 4;
	A += 2;
	A += 5;
	try {
		V += 4;
		V += 5;
		V += 1;
		V += 8;
		V += 12;
		V += 3;
		V += 9;
		cout << V[0] << endl;
		cout << V[10] << endl;
		cout << V[5] << endl;

		V.Insert(4, 6);
		cout << V[4] << endl;
		V.Insert(0, 99);
		cout << V[0] << endl;
		V.Insert(24, 87);
		cout << V[24] << endl;

		V.Insert(2, A);
		cout << V[2] << endl;
		cout << V[3] << endl;
		cout << V[4] << endl;

		V.Delete(2);
	}
		catch (IndexException e)
		{
			cout << "Eroare index: " << e.what() << endl;
		}
		catch (SizeException e)
		{
			cout << "Eroare marime:" << e.what() << endl;
		}
		
	cout << V.GetSize() << endl;
	cout << V.GetCapacity() << endl;

	Comparee comp;
	V.Sort();
	V.Print();
	V.Sort(NULL);
	V.Print();
	V.Sort(comp);
	V.Print();

	cout << V.BinarySearch(5) << endl;
	cout << V.BinarySearch(9, NULL) << endl;
	cout << V.BinarySearch(12, comp) << endl;

	cout << V.Find(5) << endl;
	cout << V.Find(NULL, 9) << endl;
	cout << V.Find(25, comp) << endl;

	Array<int> D(23);

	D += 1;
	D += 5;
	D += 2;
	D += 3;
	D += 12;
	D += 43;
	D += 8;

	V = D;
	V.Print();

	return 0;
}