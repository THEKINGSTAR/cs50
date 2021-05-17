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

    //main
int main(void)
{
/*--------------------------------------------------*/
    /*  //--main testin the checksum--*/

    // long long number = 378282246310005; //tow valid card  4003600000000014  || 378282246310005
    // second_to_last(number);
/*--------------------------------------------------*/

    //#1- prombit user for input number
    validty_check();
    
    //#2- check if the number is correct or not
    
    //#3- run check usm on th number to show if it is valid credit card number
}

//prombit user for input number
long long validty_check()
{
    /* valid credit number for test 4003600000000014   ||       378282246310005 */
    /* check if the number is correct or not */
    long long input_number = get_long_long("please enter valid card number : \n ");
    if (input_number > 0)
    {
        lenght_clac(input_number) ;
    }
    else
    {
        validty_check();
    }
}
//check if the enterd number is more 14 digit 
long long lenght_clac(long long number)
{
    long long inputed_number = number ;
    int lenght =0 ;

        while( (number/10) != '\0')
        {
            /*simble loop to calculate the lenght*/
            lenght = lenght + 1;
            number = number / 10;
        }
    //remember to add 1 to the lenght     
    lenght = lenght +1;

    //printf("lenght is : %i  \n",lenght);
    company_check(inputed_number, lenght);
}

/*-------------------------------company check-----------------------------------*/
long long  company_check(long long inputed_number, int lenght)
{
    int checksum = second_to_last(inputed_number);
    checksum = (checksum - ((checksum / 10) * 10));

    if (checksum ==0 )
    {

        /*******line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n,*****/
        /*
    American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers
    All American Express numbers start with 34 or 37;
     most MasterCard numbers start with 51, 52, 53, 54, or 55 
     (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); 
     and all Visa numbers start with 4.*/

        //printf(" %0.f", 4003600000000014 / pow(10, 14));

        //American Express uses 15-digit
        if (lenght == 15)
        {
            int american = inputed_number / pow(10, lenght - 2);
            //All American Express numbers start with 34 or 37;
            if (american == 34 || american == 37)
            {
                printf("AMEX\n");
            }
        }
        //MasterCard uses 16-digit
        if (lenght == 16)
        {
            int master_Card = inputed_number / pow(10, lenght - 2);
            //most MasterCard numbers start with 51, 52, 53, 54, or 55
            if (master_Card == 51 || master_Card == 52 || master_Card == 53 || master_Card == 54 || master_Card == 55)
            {
                printf("MASTERCARD\n ");
            }
        }
        //Visa uses 13 && and 16-digit
        if (lenght == 13 || lenght == 16)
        {
            int Visa = inputed_number / pow(10, lenght - 1);
            //Visa numbers start with 4.
            if (Visa == 4)
            {
                printf("VISA\n");
            }
        }

    }
    else
    {
        printf("INVALID\n");
    }
}

long long second_to_last(long long number)
{
    long long inputed_number = number;
    int digit_sum = 0;
    /*--- loop throw the number digit by digit from last to start----*/
    while ((number / 10) != '\0')
    {
        number = (number / 10);
        // printf("the enterd number is  %i \n", number);
        // printf("this is the storage before add  : %i \n", digit_sum);

        /* now we need to make sure if the multip of the last digit of the number 
            is more than (9) we split it to tow digit and some those digit 
            same is the sum do with some tweek */

        if ((number - ((number / 10) * 10)) * 2 > 9)
        {
            /* split it / 10 sum the tow digit */

            int tow_digit = (number - ((number / 10) * 10)) * 2; /* 10 or 11 or 12 or 52 or 93 or ....*/
            // printf("the tow digit before calculate the sum  is : %i\n", tow_digit);
            /*suppose the number is : 93 */
            /* how to sum the to digit of ;93; (9+3) = (93 / 10 = 9 )+ ((93  - 9 * 10) = 3) ; */
            tow_digit = (tow_digit / 10) + (tow_digit /*==93*/ - ((tow_digit / 10 /*==9*/) * 10 /*==90*/));
            // printf("the tow digit after calcuate the sum is : %i\n",tow_digit);
            digit_sum = digit_sum + tow_digit;
        }
        else
        {
            digit_sum = digit_sum + (number - ((number / 10) * 10)) * 2;
        }

        /*substract the last digit from the inputed number and sum those sustracted numbers*/
        //digit_sum = digit_sum + (number - ((number / 10) * 10));

        // printf("this is the storage after  add  : %i \n ", digit_sum);

        /* this update  the number with removing  tha last digit*/

        //  printf("the number after remove the last digit is %i \n", number);
        number = (number / 10);
    }

    // printf("this is the sum of the second last to the frist is : %i \n", digit_sum); // + number);

    first_digit(inputed_number, digit_sum);
}

long long first_digit(long long number, int last_tow_sec_sum)
{
    //long long number = 378282246310005;
    //int last_tow_sec_sum =27;
    // printf("the enterd number is  %llo \n", number);

    int sum_first_digit = 0;

    while ((number / 10) != '\0')
    {
        //printf("the enterd number is  %llo \n", number);
        //printf("this is the sum_first_digit before add  : %i \n", sum_first_digit);

        /*substract the last digit from the inputed number and sum those sustracted numbers*/
        //printf("the last digit now is : %i \n",(number - ((number / 10) * 10)));

        sum_first_digit = sum_first_digit + (number - ((number / 10) * 10));

        //printf("this is the sum_first_digit after  add  : %i \n ", sum_first_digit);

        /* this update  the number with removing  tha last digit*/
        number = (number / 100);
        //printf("the number after remove the last digit is %i \n", number);
    }

    sum_first_digit = sum_first_digit + number;

    //printf("this is the sum_first_digit : %i \n", sum_first_digit);

    int total_sum = sum_first_digit + last_tow_sec_sum;

    //printf("the total sum is : %i  ", total_sum);
    return total_sum;
}