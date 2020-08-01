#include <string.h>


// Sum Luhn
int GetSumLuhn(
    const char *number)
{
    //
    int digits = 0;
    int i = strlen(number);
    char digitv = 0;

    //
    while (i--)
    {
        //
        digitv = number - '0';
        digitv <<= !(i % 2); //
        digitv -= 9 * (digitv > 9);
        //
        digits += digitv;
    }

    //
    return digits;
}

// CheckSum Luhn
bool CheckSumLuhn(
    const char *number)
{
    return (GetSumLuhn(number) % 10 == 0);
}

// Get Luhn Key
char GetKeyLuhn(
    const char *number)
{
    return (10 - GetSumLuhn(number) % 10) % 10;
}

//
bool CheckKeyLuhn(
    const char *number,
    const char key)
{
    return (GetKeyLuhn(number) == (key - '0'));
}