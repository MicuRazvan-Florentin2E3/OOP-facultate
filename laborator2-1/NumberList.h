#ifndef NUMBERLIST_H_INCLUDED
#define NUMBERLIST_H_INCLUDED
#pragma once

class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector

    bool Insert( int pozitie , int x ); //adauga la pozitie val x si aceeasi conditie ca la functia add
    void RemoveNumber( int x ); //sterge nr x din vector
};

#endif // NUMBERLIST_H_INCLUDED

