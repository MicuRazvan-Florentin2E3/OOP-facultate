//define _CRT_SECURE_NO_WARNINGS -pentru visual studio ca sa putem folosi FILE*.....
#include <string.h>
#include "stdio.h"
using namespace std;

int main()
{
    int sum = 0, i, nr;
    char x[200];
    FILE* f = fopen("in.text" , "r");

    if (f == NULL)
    {
    fprintf(stderr, "error file not found");
    return 1;
    }

    //while( !feof(x) )
    while( fscanf(f, "%s", x) != EOF)
    {
        //fgets( x , 100 , f );
        nr=0;
        if( x[0] == '-' )
            i=1;
        else
            i=0;
        while( i < strlen(x) )
        {
            nr = nr*10 + ( x[i] - 48 ) ;
            i++;
        }
        if( x[0] == '-' )
            sum-= nr ;
        else
            sum+= nr ;
    }
    fclose(f);
    printf("%d", sum);
    return 0;
}
