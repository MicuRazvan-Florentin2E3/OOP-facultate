#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#pragma once
class Sort
{
public:
    int NrElem, v[100];
public:
    Sort( int min , int max , int NrElemente ) : NrElem( NrElemente ) { }
    Sort( int NrElemente ) : NrElem( NrElemente ) , v{  6 , 1 , 10 , 9 , 21 , 59 ,12 , 0 } { }
    Sort( int NrElemente , int v2[10] ) : NrElem( NrElemente ) { }
    Sort( int NrElemente , ... ) : NrElem( NrElemente ) { }
    Sort( const char* a[100] ) : NrElem( 0 ) {}
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    void Merge( Sort& s );//face interclasarea  elementelor din vectorul curent cu cele din s
};


#endif // SORT_H_INCLUDED
