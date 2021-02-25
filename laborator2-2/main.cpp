#include <iostream>
#include <string.h>
#include "students.h"
#include "students.cpp"
#include "students2.cpp"

using namespace std;

int main()
{
    student s1,s2;
    s1.SetName( "Marcel" , "Ion" );
    s1.SetMath(6);
    s1.SetENG(9);
    s1.SetHistory(7);
    s1.GetName();
    s1.GetMath();
    s1.GetENG();
    s1.GetHistory();
    s1.GetAVG();

    cout<<endl;

    s2.SetName( "Mihai" , "Boroboaca" );
    s2.SetMath(3);
    s2.SetENG(10);
    s2.SetHistory(5);
    s2.GetName();
    s2.GetMath();
    s2.GetENG();
    s2.GetHistory();
    s2.GetAVG();

    cout<<endl;


    cout<<CompareMath( s1 , s2 )<<endl;
    cout<<CompareENG( s1 , s2 )<<endl;
    cout<<CompareHistory( s1 , s2 )<<endl;
    cout<<CompareAVG( s1 , s2 )<<endl;
    cout<<CompareName( s1 , s2 )<<endl;
    return 0;
}
