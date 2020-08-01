//crdit card number testing

#include <stdio.h>
#include <cs50.c>
#include <"test.c">

int main(void)
{
    long long test_number[] = [ 378282246310005, 371449635398431, 5555555555554444, 5105105105105100, 4111111111111111, 4012888888881881, 1234567890,
                                369421438430814, 4062901840, 5673598276138003, 4111111111111113 ];

    for (int i = 0; i < 11 ; i++)
    {
        lenght_clac(test_number[i]);
    }
    
}