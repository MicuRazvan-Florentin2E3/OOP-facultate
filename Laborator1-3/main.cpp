#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
struct cuvinte
{
    char s[200];
    int lungime;
};
int main()
{
    cuvinte V[300], aux;
    int nr = 0, i, j;
    FILE *f = fopen("text.in", " r ");
    char x[1000];
    fscanf( f, "%[^\n]s", x );
    char* p = strtok(x, " ");
    while (p != NULL)
    {
        nr++;
        strcpy(V[nr].s, p);
        V[nr].lungime = strlen( V[nr].s );
        p = strtok(NULL, " ");
    }

    for( i = 1 ; i < nr ; i++ )
        for( j = i+1 ; j <= nr ; j++ )
            if( V[i].lungime < V[j].lungime )
            {
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
            }
    for ( i = 1 ; i <= nr ; i++ )
    {
        printf( "%s\n" , V[i].s );
    }
    return 0;
}
