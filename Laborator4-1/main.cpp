#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    cout<<"1."<<endl;
    Sort d1( 1 , 21 , 5 );
    d1.GetElementsCount();
    d1.Print();

    cout<<"3."<<endl;
    int v2[10]={ 6, 12 , 13 , 5 , 9 , 101 , 12 , 0 , 89 , 1004 };
    Sort d3( 10 , v2 );
    d3.GetElementsCount();
    d3.Print();
    d3.Merge( d1 );

    cout<<"4."<<endl;
    Sort d4( 10 , 12 , 13 , 5 , 9 , 101 , 12 , 0 , 89 , 1004 );
    d4.GetElementsCount();
    d4.Print();
    d4.Merge( d1 );

    cout<<"5."<<endl;
    const char *a[50] ={"10,40,100,6,70"};
    Sort d5( a );
    d5.GetElementsCount();
    d5.Print();
    d5.Merge( d1 );

    return 0;
}
