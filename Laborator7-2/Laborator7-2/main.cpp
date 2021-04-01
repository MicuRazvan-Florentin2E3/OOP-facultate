#include <iostream>
#include "temp.h"

using namespace std;


int main()
{
	vect<int> a;
	a.push(5);
	a.push(7);
	a.push(2);
	a.push(12);
	a.push(1);
	a.print();

	cout << a.pop() << endl;

	a.delete(2);
	a.print();

	a.insert(3, 25);
	a.print();

	cout << a.count() << endl;
	cout << a.get(3) << endl;

	a.set(2, 10);
	a.print();
	
	a.sort(NULL);
	a.print();

	a.sort(compara);
	a.print();

	vect<int> b;
	b.push(4);
	b.push(5);
	b.push(6);
	b.push(1);
	b.push(65);

}

