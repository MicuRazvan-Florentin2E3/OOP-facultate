#include "Math.h"
#include "Math.cpp"
#include <iostream>

 using namespace std;

int main()
{
    cout<<Math::Add( 2 , 1 )<<endl;
    cout<<Math::Add( 5 , 3 , 20 )<<endl;
    cout<<Math::Add( 5.3 , 7.2 )<<endl;
    cout<<Math::Add( 1.4 , 2.3 , 10.2 )<<endl;
    cout<<endl;

    cout<<Math::Mul( 2 , 1 )<<endl;
    cout<<Math::Mul( 5 , 3 , 20 )<<endl;
    cout<<Math::Mul( 5.3 , 7.2 )<<endl;
    cout<<Math::Mul( 1.4 , 2.3 , 10.2 )<<endl;
    cout<<endl;

    cout<<Math::Add( 4 , 1 , 2 , 3 , 10)<<endl;
    cout<<endl;

    /*char* r1 = Math::Add( "230" , "910" );
    cout<<r1 <<endl;

    r1 = Math::Sub( "230" , "910" );
    cout<<r1 <<endl;

    delete r1[]; //pt ca l-am alocat dinamic in functie, trebuie sa l tergem
    */
    return 0;
}
