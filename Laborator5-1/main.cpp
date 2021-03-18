#include <iostream>
#include "Number.h"

using namespace std;

int main()
{
    Number n1("1234" , 10 );
    Number n2("FFFF" , 16 );

    Number n3 = n1 + n2;
    return 0;
}
