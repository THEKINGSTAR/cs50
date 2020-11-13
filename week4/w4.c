#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main (void)
{
    int n = 50;

    printf("%i\n",  n );
    printf("%p\n",  &n);
    printf("%i\n", *&n);

    int *p = &n ;

    printf("%p\n",  p);
    printf("%i\n", *p);
}