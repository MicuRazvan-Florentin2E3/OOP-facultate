#include <iostream>
#include "Number.h"
using namespace std;



int main()
{
    Number n1("1234" , 10 );
    Number n2("FFFF" , 16 );

    Number n3 = n1 + n2;
    n3.Print();
    /*
    n3 = n1 - n2;
    n3.Print();

    n3 = n1 | n2;
    n3.Print();

    cout<< n3[2]<<endl;

    n3 = -n3;
    n3.Print();

    if( n1 < n2 )
        n1.Print();
    else
        n2.Print();

    if( n1 <= n2 )
        n1.Print();
    else
        n2.Print();

    if( n1 > n2 )
        n1.Print();
    else
        n2.Print();

    if( n1 <= n2 )
        n1.Print();
    else
        n2.Print();

    if( n1 == n2 )
        n1.Print();
    else
        n2.Print();

    if( n1 != n2 )
        n1.Print();
    else
        n2.Print();

    cout<<n1.GetBase()<<endl;
    cout<<n1.GetDigitsCount()<<endl;
    n1.SwitchBase( 2 );
    n1.Print();
    */
    return 0;
}
