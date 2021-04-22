#pragma once
#include <iostream>
#include <string>
#include "Myiterator.h"

using namespace std;

template<typename K , typename V>
class Map
{
public:
	struct pereche {
		K key;
		V value;
		int index;
	};
	pereche Panda[100];
	int count = 0;
	V& operator[] (K _key)
	{
		for (int i = 0; i < count; ++i)
			if (_key == Panda[i].key)
				return Panda[i].value;
		Panda[count].key = _key;
		Panda[count].index = count;
		return Panda[count++].value;
	}

	void Set(K _key, V val)
	{
		for (int i = 0; i < count; ++i)
			if (_key == Panda[i].key)
				Panda[i].value = val;
	}	

	bool Get(const K& _key, V& val)
	{
		for (int i = 0; i < count; ++i)
			if (_key == Panda[i].key)
			{
				val = Panda[i].value;
				return true;
			}
		return false;
	}

	int Count() { return count; }

	void Clear() 
	{	
		count = 0;
	}

	bool Delete(const K& _key)
	{
		for (int i = 0; i < count; ++i)
			if (_key == Panda[i].key)
			{
				for (int j = i; j < count-1; j++)
				{
					Panda[j].value = Panda[j + 1].value;
					Panda[j].key = Panda[j + 1].key;
					Panda[j].index = Panda[j + 1].index;
				}
				count--;
				return true;
			}
		return false;
	}

	bool Includes(const Map<K, V>& mapp)
	{
		bool OK;
		for (int i = 0; i < mapp->count; ++i)
		{
			OK = 0;
			for (int j = 0; j < count; ++j)
				if (mapp->Panda[j].key == Panda[i].key)
					OK == 1;
			if (OK == 0)
				return false;
		}
		return true;
	}

	void Print()
	{
		for (int i = 0; i < count; ++i)
			cout << "Index:" << Panda[i].index << ", Key=" << Panda[i].key << ", Value=" << Panda[i].value << endl;
	}
};
