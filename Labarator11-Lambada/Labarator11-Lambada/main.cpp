//de terminat: functia iterate/filter
#include <iostream>
#include <vector>
#include <string>
#include "Lucru.h"
using namespace std;

/*
void Sort(vector<string> v, int n, int(*compare)(string, string)) {
	for (int i = 0; i < n - 1; ++i) {
		string min = v[i];
		int poz = i;
		for (int j = i + 1; j < n; j++) {
			if (compare(v[j], min) == 1) {
				min = v[j];
				poz = j;
			}
		}
		swap(v[i], v[poz]);
	}
}*/

int main()
{
	cout << "ex1:" << endl;
	vector<string> A;
	string s("O sa trec la sisteme de operare");

	int start, poz = 0;
	while (s.find_first_not_of(" ", poz) < s.size())
	{
		start = s.find_first_not_of(" ", poz);
		poz = s.find_first_of(" ", start);
		A.push_back(s.substr(start, poz - start));
	}

	auto lambda1 = [](string a, string b) {
		return a.size() < b.size();
	};

	//Sort(A, A.size(), lambda1);
	
	for (int i = 0; i < A.size() - 1; ++i) {
		string min = A[i];
		int poz = i;
		for (int j = i + 1; j < A.size(); j++) {
			if (lambda1(A[j], min) == 1) {
				min = A[j];
				poz = j;
			}
		}
		string temp;
		temp = A[i];
		A[i] = A[poz];
		A[poz] = temp;
	}
	
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;

	cout << "ex2:" << endl;

	vector<int> B;
	B.push_back(2);
	B.push_back(23);
	B.push_back(5);
	B.push_back(12);
	B.push_back(512);
	B.push_back(0);
	B.push_back(5);
	B.push_back(23);
	B.push_back(1);
	B.push_back(6);

	auto lambda2 = [](int a, int b) {
		if (a > b) return a;
		return b;
	};

	int max = 0;
	for (int i = 0; i < B.size(); i++) 
		max = lambda2(B[i], max);
	
	cout << max << endl;

	cout << "ex3:" << endl;
	MyVector C(25);
	C.Add(6);
	C.Add(3);
	C.Add(2);
	C.Add(1);
	C.Add(86);
	C.Add(23);
	C.Add(5);
	C.Add(21);

	C.Delete(2);

	C.Print();

	return 0;

}