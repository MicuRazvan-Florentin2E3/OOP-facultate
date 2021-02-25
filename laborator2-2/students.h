#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED
#pragma once
#include <iostream>

using namespace std;

class student
{
public:
    char nume[25], prenume[25];
    float gradeMath, gradeENG, gradeHistory, gradeAVG;

public:
    void SetName( char numee[] , char prenumeep[] );
    void SetMath( int a );
    void SetENG( int a );
    void SetHistory( int a );

    void GetName();
    void GetMath();
    void GetENG();
    void GetHistory();

    void GetAVG();
};




#endif // STUDENTS_H_INCLUDED
