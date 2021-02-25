#include "students.h"
#pragma once

int CompareENG( student s1 , student s2 )
{
    if ( s1.gradeENG == s2.gradeENG )
        return 0;
    if( s1.gradeENG < s2.gradeENG )
        return -1;
    return 1;
}

int CompareMath( student s1 , student s2 )
{
    if ( s1.gradeMath == s2.gradeMath )
        return 0;
    if( s1.gradeMath < s2.gradeMath )
        return -1;
    return 1;
}

int CompareHistory( student s1 , student s2 )
{
    if ( s1.gradeHistory == s2.gradeHistory )
        return 0;
    if( s1.gradeHistory < s2.gradeHistory )
        return -1;
    return 1;
}

int CompareAVG( student s1 , student s2 )
{
    if ( s1.gradeAVG == s2.gradeAVG )
        return 0;
    if( s1.gradeAVG < s2.gradeAVG )
        return -1;
    return 1;
}

int CompareName( student s1 , student s2 )
{
    if( strcmp ( s1.nume , s2.nume ) == 0 )
        return 0;
    if( strcmp ( s1.nume , s2.nume ) < 0 )
        return -1;
    return 1;
}

