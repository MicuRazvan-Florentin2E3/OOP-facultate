#include "students.h"

#pragma once

void student::SetName( char numee[] , char prenumee[] )
{
    strcpy( nume , numee );
    strcpy( prenume , prenumee );
}
void student::GetName()
{
    cout<<nume<<" "<<prenume<<endl;
}

void student::SetMath( int a )
{
    gradeMath = a;
}
void student::GetMath()
{
    cout<<gradeMath;
    cout<<endl;
}

void student::SetENG( int a )
{
    gradeENG = a;
}
void student::GetENG()
{
    cout<<gradeENG;
    cout<<endl;
}

void student::SetHistory( int a )
{
    gradeHistory = a;
}
void student::GetHistory()
{
    cout<<gradeHistory;
    cout<<endl;
}

void student::GetAVG()
{
    gradeAVG=(gradeMath+gradeENG+gradeHistory)/3;
    cout<<gradeAVG;
    cout<<endl;
}
