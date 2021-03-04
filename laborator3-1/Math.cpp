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
/*
char Math::Add( const char *s1 , const char *s2 )
{
    char* rez = new char[100];
    return nr;
}

char Math::Sub( const char *s1 , const char *s2 )
{
    char* rez = new char[100];
    return rez;
}*/
