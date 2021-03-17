#pragma once
#include <iostream>
#include "Sort.h"


using namespace std;

Sort::Sort( int min , int max , int NrElememente )
{
    int x;
    NrElem = -1;
    for( int i = 0 ; i < NrElemente ; i++ )
    {
        cin>>x;
        if( x >= min && x <= max )
            v[++NrElem] = x;
        else
            cout<<"Numarul ales nu este in intervalul [ "<<min<<" , "<<max<<"]"<<endl;
    }
    BubbleSort();
}

Sort::Sort( int NrElemente , int v2[] )
{
    int i;
    NrElem = NrElemente;
    for( i = 0 ; i < NrElem ; i++ )
        v[i] = v2[i];
    InsertSort();
}

Sort::Sort( int NrElemente , ... )
{
    NrElem = NrElemente;
    va_list v2;
    va_start( v2 , NrElem);
    for( i = 0 ; i < NrElem ; i++ )
        v[i] = va_arg( v2 , int );
    va_end( v2 );
    InsertSort();
}

Sort::Sort( const char *a )
{
    int i = 0, nr;
    NrElem = 0;
    while( i < strlen(a) )
    {
        nr = 0;
        while( a[i] >= 48 && a[i] <= 58 )
        {
            nr = nr*10 + atoi(a[i] );
            i++;
        }
        i++;
        v[++NrElem] =  nr;
    }
    InsertSort();
}

void Sort::InsertSort(bool ascendent)
{
    int i, temp, j;
    if( ascendent == 1 )
        for ( i = 1; i < NrElem; i++ )
        {
            temp = v[i];
            j = i - 1;
            while ( j >= 0 && v[j] > temp )
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
            v[j + 1] = temp;
        }
    else
        for ( i = 1; i < NrElem; i++ )
        {
            temp = v[i];
            j = i - 1;
            while ( j >= 0 && v[j] < temp )
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
            v[j + 1] = temp;
        }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j;
    if( ascendent == 1 )
        for ( i = 0; i < NrElem-1; i++ )
            for ( j = 0; j < NrElem-i-1; j++ )
                if (v[j] > v[j+1])
                    swap( &v[j] , &v[j+1] );
    else
        for ( i = 0; i < NrElem-1; i++ )
            for ( j = 0; j < NrElem-i-1; j++ )
                if (v[j] < v[j+1])
                    swap( &v[j] , &v[j+1] );
}

void Sort::Print()
{
    int i;
    for (i = 0; i < NrElem; i++)
        cout << v[i] << " ";
    cout << endl;
}

int Sort::GetElementsCount();
{
    cout<<NrElem<<<endl;
}

void Sort:Merge( Sort& s )
{
    int L1 = this.NrElem, L2 = s.Nrelem, i = 0 , j = 0;
    Sort daux[100];
    while( i+j <= L1+L2-1 )
    {
        if( j > L2 )
        {
            i++;
            v[i+j] = this.v[i];
        }
        else
            if( i > L1 )
        {
            daux.v[i+j] = s.v[j];
            j++;
        }
        else
            if( this.v[i] <= s.v[j] )
            {
                daux.v[i+j] = this.v[i];
                i++;
            }
            else
            {
                daux.v[i+j] = s.v[j];
                j++;
            }
    }
    daux.NrElem = L1+L2;
    daux.Print();
}
