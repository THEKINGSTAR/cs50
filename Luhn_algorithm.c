#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/* function checkLuhn(string purportedCC)
{
    int sum := integer(purportedCC[length(purportedCC)-1])
    int nDigits := length(purportedCC)
    int parity := nDigits modulus 2
    for i from 0 to nDigits - 2
    {
        int digit : = integer(purportedCC[i]) if i modulus 2 = parity
                        digit : = digit × 2 if digit > 9 digit : = digit - 9 sum : = sum + digit
    }
    return (sum modulus 10) = 0
} */

long  checkLuhn(string purportedCC);

int main(void) 
{
    long number =get_long("Please enter your credit card number : \n");
    checkLuhn(number);
}


long checkLuhn(string purportedCC)
{
    int sum = long(purportedCC[length(purportedCC)-1]);
    int nDigits = length(purportedCC);
    int parity = nDigits % 2;
    int i = 0;
    for (i ; i< ( len (purportedCC)-2 );i++)
    {
        int digit = integer(purportedCC[i]) ;

        if ( i % 2 == parity)
        {
                if ( digit > 9 && digit == (digit - 9) && sum == (sum + digit))
                {
                    digit = digit * 2;
                }

        }
                        
    }
    if (sum % 10) 
    {
        return  0;
    }
    
}