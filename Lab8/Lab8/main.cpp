#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	 string s("I bought an apple. Then I eat an apple. Apple is my favorite.");
	 vector<string> cuv;
	 string sep(" ,.?!");
	 
	 int start, poz = 0;
	 while (s.find_first_not_of(sep, poz) < s.size())
	 {
		 start = s.find_first_not_of(sep, poz);
		 poz = s.find_first_of(sep, start);
		 cuv.push_back(s.substr(start, poz-start));
	 }
	 
	 map<string, int> M;
	 int i;
	 for (i = 0; i < cuv.size(); i++)
	 {
		 string mic;
		 mic = cuv[i];
		 mic[0] = tolower(mic[0]);
		 if (M.find(mic) == M.end())
			 M[mic] = 1;
		 else
			 M[mic]++;
	 }

	 cout << "Cuvintele cu numarul de aparitii nosortate: " << endl;
	 for (auto p : M)
	 {
		 cout << p.first << " " << p.second << endl;
	 }

	 priority_queue<string>Q;

	 cout << endl << "Afisare lexicografica :" << endl;
	 for (auto p : M)
	 {
		 Q.push(p.first);
	 }
	 
	 while (!Q.empty())
	 {
		 cout << Q.top() << " => " << M[Q.top()] << endl;
		 Q.pop();
	 }

	 //neterminate:
	 cout << endl << "Afisare dupa numarul de aparitii:" << endl;
	 cout << endl << "Afisare dupa lungimea cuvintelor:";
	 return 0;
}