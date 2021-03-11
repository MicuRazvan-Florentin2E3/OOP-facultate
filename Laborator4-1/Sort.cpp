#pragma once
#include <iostream>
#include "Sort.h"


using namespace std;

Sort::Sort( int min , int max , int NrElememente )
{
    int i = -1, x;
    while( i < NrElem-1)
    {
        cin>>x;
        if( x >= min && x <= max )
            v[++i] = x;
        else
            cout<<"Numarul ales nu este in intervaluk [ "<<min<<" , "<<max<<"]"<<endl;
    }
    BubbleSort();
}


Sort::Sort( int NrElemente )
{
    InsertSort();
}

Sort::Sort( int NrElemente , int v2[] )
{
    int i;
    for( i = 0 ; i < NrElem ; i++ )
        v[i] = v2[i];
    InsertSort();
}

Sort::Sort( int NrElemente , ... )
{
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
    for ( i = 0; i < NrElem-1; i++ )
        for ( j = 0; j < NrElem-i-1; j++ )
            if (v[j] > v[j+1])
                swap( &v[j] , &v[j+1] );
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/*
void Sort::QuickSort(bool ascendent)
{
    int low, high;
    low = 0;
    high = NrElemente-1;
    if (low < high)
    {
        int pi = partition(v, low, high);
        QuickSort(v , low, pi - 1);
        QuickSort(v , pi + 1, high);
    }
}*/

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
    int v3[200];
    while( i+j <= L1+L2-1 )
    {
        if( j > L2 )
        {
            v3[i+j] = this.v[i];
            i++;
        }
        else
            if( i > L1 )
        {
            v3[i+j] = s.v[j];
            j++;
        }
        else
            if( this.v[i] <= s.v[j] )
            {
                v3[i+j] = this.v[i];
                i++;
            }
            else
            {
                v3[i+j] = s.v[j];
                j++;
            }
    }
    for( i = 1 ; i < L1+L2 ; i++ )
        cout<<v3[i];
}
