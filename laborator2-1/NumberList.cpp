#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
    count = 0;
    for( int i = 0 ; i < 10 ; ++i )
        numbers[i] = 0;
}

bool NumberList::Add( int x )
{
    count++;
    if( count > 10 )
    {
        count --;
        return 0;
    }
    numbers[count-1] = x;
}

void NumberList::Sort()
{
    int i , j;
    for( i = 0 ; i < count-1 ; i++ )
        for( j = i+1 ; j < count ; j++ )
            if( numbers[i] > numbers[j] )
            {
                int aux;
                aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
}

void NumberList::Print()
{
    int i;
    for ( i = 0 ; i < count ; i++ )
        cout<<numbers[i]<<" ";
    cout<<endl;
}

bool NumberList::Insert( int pozitie , int x )
{
    int  i;
    count++;
    if( count > 10 )
    {
        count --;
        return 0;
    }
    for ( i = count-1 ; i > pozitie ; i-- )
        numbers[i] = numbers[i-1];
    numbers[pozitie] = x;
}

void NumberList::RemoveNumber( int x )
{
    int OK = 0, i, poz;
    while( OK == 0 )
    {
        OK = 1;
        for ( i = 0 ; i < count ; i++)
            if( numbers[i] == x )
            {
                poz = i;
                //break;
                OK = 0;
            }
        if( OK == 0 )
        {
            for( i = poz ; i < count-1 ; i++ )
                numbers[i] = numbers[i+1];
            count--;
        }
    }
}
