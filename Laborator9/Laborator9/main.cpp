#include <stdio.h>
#include "Map.h"

using namespace std;

int main()
{
    Map<int, string> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    m.Print();
    /*
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }*/

    m.Set(20, "Ana");
    m.Print();

    string val;
    m.Get(30, val);
    cout << val << endl;

    cout << m.count << endl;

    m.Delete(10);
    m.Print();

    m.Clear();
    m.Print();
    return 0;

}