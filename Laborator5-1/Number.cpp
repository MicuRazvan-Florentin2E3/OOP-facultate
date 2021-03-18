#include "Number.h"
#include <string.h>


//Alte functii:

int maxim( int a , int b )
{
    if ( a > b )
        return a;
    else
        return b;
}
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int toDeci( char* str, int base )
{
	int len = strlen(str);
	int power = 1;
	int num = 0;
	int i;
	for (i = len - 1 ; i >= 0 ; i--)
	{
		if (val(str[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += val(str[i]) * power;
		power = power * base;
	}

	return num;
}


//de facut functie ToBase() care sa transformare din baza 10 in baza B



//Constructori / Deconstructori:

Number::~Number()
{
	delete[] value;
}

Number::Number( const char* value, int base)
{
    this -> value = value;
    this -> base = base;
}

// +constructor pt move




//Operatori:

// de facut operator pentru []
Number Number::operator+ ( const Number& n1 , const Number& n2 )
{
    int a, b, bazaMaxima , aux;
    bazaMaxima = maxim( n1.base , n2.base );
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );

    Number rez( "0" , 10 );
    aux = a + b;
    rez.value = ToBase( aux , bazaMaxima ) ;
    rez.base = bazaMaxima ;
    return rez;
}

Number Number::operator- ( const Number& n1 , const Number& n2 )  //substraction
{
    int a, b, bazaMaxima ;
    bazaMaxima = maxim( n1.base , n2.base );
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );

    Number rez( "0" , 10 );
    aux = a - b;
    rez.value = ToBase( aux , bazaMaxima ) ;
    rez.base = bazaMaxima ;
    return rez;

}


Number Number::operator- ( const Number &n ) //negate
{
    Number rez( "0" , 10 );
    strcpy( n.value , rez.value );
    strcpy( rez.value , rez.value+1 );
    rez.value[0] = '-';
    return rez;
}

bool Number::operator< ( const Number& n1 , const Number& n2 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );


    if( a > b )
        return 1;
    else
        return 0;
}

bool Number::operator> ( const Number& n1 , const Number& n2 )
{
     int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );

    if( a > b )
        return 1;
    else
        return 0;
}

bool Number::operator== ( const Number& n1 , const Number& n2 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );


    if( a == b )
        return 1;
    else
        return 0;
}

bool Number::operator<= ( const Number& n1 , const Number& n2 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );


    if( a <= b )
        return 1;
    else
        return 0;
}

bool Number::operator>= ( const Number& n1 , const Number& n2 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );

    if( a >= b )
        return 1;
    else
        return 0;
}

bool Number::operator!= ( const Number& n1 , const Number& n2 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( n2.base != 10)
        b = toDeci( n2.value , n2.base );

    if( a != b )
        return 1;
    else
        return 0;
}

//Number Number::operator| ( const Number& n1 , const Number& n2 )


//Metode:

void Number::Print();
{
    cout<<"Numarul "<<this.value<<" in baza "<<this.base<<endl;
}

int Number::GetDigitsCount()
{
    int count = 0, i;
    if( this.value[0] == "-" )
        i = 1;
    else
        i = 0;
    while( i <strlen( this.value ) )
    {
        count++;
        i++;
    }
    return count;
}

int Number::GetBase()
{
    return this.base;
}
//void SwitchBase(int newBase);
