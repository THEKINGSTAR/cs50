#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long validty_check();
long long second_to_last();
long long first_digit();
long long company_check();
long long lenght_clac();
long long testing_number();

int main(void)
{
    /*--------------------------------------------------*/
    /*  //--main testin the checksum--*/

    // long long number = 378282246310005; //tow valid card  4003600000000014  || 378282246310005
    // second_to_last(number);
    /*--------------------------------------------------*/
    /*--------------------------------------------------*/
    /*MAIN APP RUNT */

    validty_check();
    /*--------------------------------------------------*/
    //testing_number();
}

long long validty_check(void)
{
    long long input_number = get_long_long("please enter valid card number : \n");

    return lenght_clac(input_number);
}
/*-------------------------------lenght claculate--------------------------------*/
/*-------------------------------------------------------------------------------*/
long long lenght_clac(long long number)
{
    long long inputed_number = number;
    int lenght = 0;
    while ((number / 10) != '\0')
    {
        lenght = lenght + 1;
        number = number / 10;
    }
    lenght = lenght + 1;
    return company_check(inputed_number, lenght);
}
/*-------------------------------company check-----------------------------------*/
/*-------------------------------------------------------------------------------*/

long long company_check(long long inputed_number, int lenght)
{
    int checksum = second_to_last(inputed_number);
    //printf("recived checksum is : %i \n", checksum);

    checksum = (checksum - ((checksum / 10) * 10));
    //printf("lenght is : %i \n",lenght);
    int frist_tow_digit = inputed_number / pow(10, lenght - 2);
    //printf("the frist tow digit are : %i \n",frist_tow_digit);
    //printf("%i \n",checksum);
if (checksum == 0 &  lenght >= 13 & lenght < 17)
{
    if (lenght == 13)
    {
        int Visa = inputed_number / pow(10, lenght - 1);
            if (Visa == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
    }
    else if (lenght == 15)
        {
            int american = inputed_number / pow(10, lenght - 2);
                if (american == 34 || american == 37)
            {
                    printf("AMEX\n");
            }
                else
            {
                    printf("INVALID\n");
            }
        }
    else if (lenght == 16)
            {
                int master_Card = inputed_number / pow(10, lenght - 2);
                int Visa = inputed_number / pow(10, lenght - 1);

                if (master_Card == 51 || master_Card == 52 || master_Card == 53 || master_Card == 54 || master_Card == 55)
                {
                    printf("MASTERCARD\n ");
                }
                else if (Visa == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
    else
        {
            printf("INVALID\n");
        }
}
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

/*------------------calculate the  second to last digit sum----------------------*/
/*-------------------------------------------------------------------------------*/
long long second_to_last(long long number)
{
    long long inputed_number = number;
    int digit_sum = 0;
    while ((number / 10) != '\0')
    {
        number = (number / 10);
        if ((number - ((number / 10) * 10)) * 2 > 9)
        {
            int tow_digit = (number - ((number / 10) * 10)) * 2;
            tow_digit = (tow_digit / 10) + (tow_digit /*==93*/ - ((tow_digit / 10 /*==9*/) * 10 /*==90*/));
            digit_sum = digit_sum + tow_digit;
        }
        else
        {
            digit_sum = digit_sum + (number - ((number / 10) * 10)) * 2;
        }
        number = (number / 10);
    }
    return first_digit(inputed_number, digit_sum);
}

/*------------calculate the other disit sum + second to last digit sum------------*/
/*-------------------------------------------------------------------------------*/
long long first_digit(long long number, int last_tow_sec_sum)
{
    int sum_first_digit = 0;
    while ((number / 10) != '\0')
    {
        sum_first_digit = sum_first_digit + (number - ((number / 10) * 10));
        number = (number / 100);
    }
    sum_first_digit = sum_first_digit + number;
    int total_sum = sum_first_digit + last_tow_sec_sum;
    //printf("%i\n",total_sum);
    return total_sum;
}




//------------------------------------------TEST CASES ------------------------------------//
/*
1-    :) identifies 378282246310005 as AMEX
2-    :) identifies 371449635398431 as AMEX
3-    :( identifies 5555555555554444 as MASTERCARD
4-    :( identifies 5105105105105100 as MASTERCARD
5-    :) identifies 4111111111111111 as VISA
6-    :) identifies 4012888888881881 as VISA
7-    :( identifies 1234567890 as INVALID
8-    :( identifies 369421438430814 as INVALID
9-    :( identifies 4062901840 as INVALID
10-   :( identifies 5673598276138003 as INVALID
11-   :( identifies 4111111111111113 as INVALID
*/

/*  long long testing_number(void)
{
    long long test_number[11] = {378282246310005,371449635398431,5555555555554444,5105105105105100,4111111111111111,4012888888881881
                                ,1234567890,369421438430814,4062901840,5673598276138003,4111111111111113};
    for (int i = 0; i < 11; i++)
    {
        printf("Test case number %i :\n",i+1);
        lenght_clac(test_number[i]);
        printf("**************************************** \n");
    }
}  */