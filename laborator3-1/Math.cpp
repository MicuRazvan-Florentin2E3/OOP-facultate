#include "Math.h";
#include <stdarg.h>
#include <string.h>
#pragma once
int Math::Add(int x ,int y)
{
    return x+y;
}

int Math::Add(int x ,int y ,int z)
{
    return x+y+z;
}

int Math::Add(double a ,double b)
{
    return a+b;
}

int Math::Add(double a ,double b ,double c)
{
    return a+b+c;
}

int Math::Mul(int x ,int y)
{
    return x*y;
}

int Math::Mul(int x ,int y ,int z )
{
    return x*y*z;
}

int Math::Mul(double a ,double b )
{
    return a*b;
}

int Math::Mul(double a ,double b ,double c )
{
    return a*b*c;
}

int Math::Add(int count,...)
{
    va_list V;
    int i, sum = 0;
    va_start( V , count ); //lista va incepe dupa va_start
    for ( i = 1 ; i <= count ; i++ )
        sum = sum + va_arg( V , int );
    va_end(V);
    return sum;
}

int max( int a , int b )
{
    if( a > b )
        return a;
    return b;
}

char* Math::Add( const char *s1 , const char *s2 )
{
    char* rez = new char[100];
    int maxim, i, aux;
    maxim=max( strlen(s1) , strlen(s2) );

    for( i = 0 ; i <= maxim ; i++ )
        rez[i] = 48;

    for( i = maxim-1 ; i > 0 ; i-- )
        if( s1[i] && s2[i] )
        {
            aux = rez[i] + s1[i] + s2[i] - 3*48;
            if( aux < 10 )
                rez[i] = 48 + aux;
            else
            {
                rez[i] = 48 + ( aux - 10 );
                rez[i-1] = rez[i-1] + 1;
            }
        }
        else
            if( s1[i] )
                rez[i] = rez[i] + s1[i] - 48;
            else
                rez[i] = rez[i] + s2[i] - 48;

    aux = rez[0] + s1[0] + s2[0] - 3*48;
    if( aux < 10 )
    {
        rez[0] = aux + 48;
        rez[maxim]='\0';
    }
    else
    {
        rez[0] = ( aux - 10 ) + rez[0];
        strcpy( rez+1 , rez );
        rez[0] = 49 ;
        rez[maxim+1]='\0';
    }
    return rez;
}
int scadere[100];

char* Math::Sub( const char *s1 , const char *s2 )
{
    char* rez = new char[100];
    int maxim, i, j, aux, OK = 1;
    maxim=max( strlen(s1) , strlen(s2) );

    for( i = 0 ; i < maxim ; i++ )
        rez[i] = 48;

    for( i = maxim-1 ; i > 0 ; i-- )
    {
        aux = s1[i] - s2[i];
        if( aux == 0 && OK )
            rez[i] = 48;
        if( aux > 0 )
        {
            if( scadere[i] == 0 )
                rez[i] = aux + 48;
            else
                if( scadere[i] == 2 )
                    rez[i] = aux + 48 - 1;
                else
                    rez[i] = aux - 1 + 48;
        }
        else
        {
            OK = 0;
            if( scadere[i] == 2 )
                rez[i] = 9 + s1[i] - s2[i] + 48;
            else
            {
                j = i-1;
                while( s1[j] == 0)
                {
                    scadere[j] = 2;
                    j--;
                }
                scadere[j] = 1;
                if( scadere[i] == 0 )
                    rez[i] = 10 + s1[i] - s2[i] + 48;
                else
                    rez[i] = 10 + s1[i] - s2[i] + 48 - 1;
            }
        }
    }

    rez[maxim] = '\0';

    if( scadere[0] == 1 )
        aux = s1[0] - s2[0] - 1;
    else
        aux = s1[0] - s2[0];
    if( aux < 0 )
    {
        rez[0] = aux*(-1);
        strcpy( rez+1 , rez );
        rez[0]= '-';
    }
    else
        rez[0] = aux + 48;

    while( rez[0] == '0' && strlen(rez) > 1 )
        strcpy( rez , rez+1 );
    return rez;
}
