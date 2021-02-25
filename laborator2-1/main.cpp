#include "NumberList.h"
#include "Numberlist.cpp"
#include <iostream>

using namespace std;

int main()
{
    NumberList l;
    l.Init();

    l.Add( 5 );
    l.Add( 2 );
    l.Add( 8 );
    l.Add( 11 );
    l.Add( 12 );
    l.Add( 2 );
    l.Print();

    l.Sort();
    l.Print();

    l.Insert( 2 , 15 );
    l.Insert( 0 , 21 );
    l.Print();

    l.RemoveNumber( 2 );
    l.Print();
    return 0;
}
