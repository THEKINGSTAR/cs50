#include "algoluhn.c"

#include <stdio.h>
#include <stdlib.h>

//
int main()
{
    // LUHN
    char number[] = "1789372997";

    printf("%s X\n", number);
    printf(" %i", GetKeyLuhn(number));
    printf(" \n");

    return 0;
}