#include <exception>

using namespace std;

class IndexException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Index invalid";
	}
};

class SizeException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Capacitate depasita!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class Comparee : public Compare
{
public:
	Comparee() {}
	int CompareElements(void* e1, void* e2) {
		if(e1 == e2)
			return -1;
		return e1 > e2;
	}
};

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator();
	ArrayIterator& operator ++ ();
	ArrayIterator& operator -- ();

	bool operator= (ArrayIterator<T>&);
	bool operator!=(ArrayIterator<T>&);

	T* GetElement();
};

template<class T>
class Array
{
private:
	T** List;		// lista cu pointeri la obiecte de tipul T*
	int Capacity;	// dimensiunea listei de pointeri
	int Size;		// cate elemente sunt in lista
public:
	Array(int nr); 						// Lista nu e alocata, Capacity si Size = 0
	~Array(); 							// destructor
	Array(); 							// Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray);	// constructor de copiere

	T& operator[] (int index);		// arunca exceptie daca index este out of range

	const Array<T>& operator+=(const T& newElem);					// adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T& newElem);			// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray);	// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index);								// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	void operator= (const Array<T>& otherArray);

	void Sort();									// sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&));	// sorteaza folosind o functie de comparatie
	void Sort(Comparee comparator);					// sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem);										// cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));		// cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Comparee comparator);					// cauta un element folosind binary search si un comparator

	int Find(const T& elem);										// cauta un element in Array
	int Find(int(*compare)(const T&, const T&), const T& elem);		// cauta un element folosind o functie de comparatie
	int Find(const T& elem, Comparee comparator);					// cauta un element folosind un comparator

	int GetSize();

	int GetCapacity();

	void Print();
	
	//ArrayIterator<T> GetBeginIterator();
	//ArrayIterator<T> GetEndIterator();

	int compare(const T& a, const T& b);
};