#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#pragma once
class Sort
{
public:
    int NrElem, v[100];
public:
    Sort( int min , int max , int NrElemente ) { }
    Sort( int NrElemente , int v2[10] ) { }
    Sort( int NrElemente , ... ) { }
    Sort( const char* a[100] ) {}
    void InsertSort(bool ascendent=false);
    //void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    //int  GetElementFromIndex(int index);
    void Merge( Sort& s );//face interclasarea  elementelor din vectorul curent cu cele din s
};


#endif // SORT_H_INCLUDED
