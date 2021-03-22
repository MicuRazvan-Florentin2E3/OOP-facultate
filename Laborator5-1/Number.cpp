#include "Number.h"
#include <string.h>
#include <stdio.h>


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

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

char* fromDeci( int base, int inputNum )
{
    char res[1000];
    int index = 0;
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    strrev(res);
    return res;
}

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
Number Number::operator= ( const Number& n)
{
    Number rez( "0" , 10 );
    strcpy( rez.value , this.value );
    rez.base = this.base;
    return rez;
}
char& Number::operator[](int index) {
	return value[index];
}

Number Number::operator+ ( const Number& n1 )
{
    int a, b, bazaMaxima , aux;
    bazaMaxima = maxim( n1.base , n2.base );
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    Number rez( "0" , 10 );
    aux = a + b;
    strcpy( rez.value , fromDeci( bazaMaxima , aux ) ;
    rez.base = bazaMaxima ;
    return rez;

}

Number Number::operator- ( const Number& n1 )  //substraction
{
    int a, b, bazaMaxima ;
    bazaMaxima = maxim( n1.base , n2.base );
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    Number rez( "0" , 10 );
    aux = a - b;
    strcpy( rez.value , fromDeci( aux , bazaMaxima ) ;
    rez.base = bazaMaxima ;
    return rez;

}


char Number::operator- ( ) //negate
{
    Number rez( "0" , 10 );
    strcpy( rez.value , this.value );
    strcpy( rez.value+1 , rez.value );
    rez.value[0] = '-';
    return rez.value;
}

bool Number::operator< ( const Number& n1 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );


    if( a > b )
        return 1;
    else
        return 0;
}

bool Number::operator> ( const Number& n1)
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    if( a > b )
        return 1;
    else
        return 0;
}

bool Number::operator== ( const Number& n1 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    if( a == b )
        return 1;
    else
        return 0;
}

bool Number::operator<= ( const Number& n1 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    if( a <= b )
        return 1;
    else
        return 0;
}

bool Number::operator>= ( const Number& n1 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    if( a >= b )
        return 1;
    else
        return 0;
}

bool Number::operator!= ( const Number& n1 )
{
    int a, b;
    if( n1.base != 10 )
        a = toDeci( n1.value , n1.base );
    if( this.base != 10)
        b = toDeci( this.value , this.base );

    if( a != b )
        return 1;
    else
        return 0;
}

Number Number::operator| ( const Number& n1 )
{
    Number rez( "0" , 10 );
    int bazaMaxima;
    if( this.base > n1.base )
    {
        rez.base = this.base;
        int a = toDeci( n1.value , n1.base );
        strcpy(rez.value , fromDeci( rez.base , a ));
    }
    else
        {
        rez.base = n1.base;
        int a = toDeci( this.value , this.base );
        strpcy(rez.value , fromDeci( rez.base , a ));
        }
    return rez;
}

void Number:operator--()
{
    strcpy( this.value , this.value+1);
}
void Number::operator--(int VariabilaExtremDeFolositoare)
{
    int nr = strlen(this.value);
    this.value[nr-1] = this.value[nr];
}

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

void SwitchBase(int newBase);
{
    int a = toDeci( this.value , this.base );
    this.base = newBase;
    strcpy( this.value , fromDeci( this.base , a );
}

