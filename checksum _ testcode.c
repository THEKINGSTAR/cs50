#include <stdio.h>
#include <cs50.h>

long long second_to_last();
long long first_digit();

int main(void)
{
    long long number = 378282246310005; //tow valid card  4003600000000014  || 378282246310005
    second_to_last(number);
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

    printf("the total sum is : %i  ", total_sum);
}


/*
###############################################################################################################################
long long loop_throw_number_digit_by_digit()
{
    
    printf("("the resutl of 99999*10 is :%i \n",99999*10);
    printf("the resutl of 98/10 is :  %i \n",98/10);
    
    //---the test number---//
    //long long  number = 987654321;

    long long number = 987654321;
    int storage = 0;

    //loop throw the number digit by digit from last to start
    while ((number / 10) != '\0')
    {
        printf("the enterd number is  %i \n", number);

        printf("this is the storage before add  : %i \n", storage);

        //substract the last digit from the inputed number and sum those sustracted numbers
        storage = storage + (number - ((number / 10) * 10));

        /* now we need to make sure if the multip of the last digit of the number 
            is more than (9) we split it to tow digit and some those digit 
            same is the sum do with some tweek */

    /*
            if(the outcome of the multi is > 9 )
            {
                    split it /10
                    sum the tow digit
            }
        */
    /*
        printf("this is the storage after  add  : %i \n ", storage);

        // this update  the number with removing  tha last digit
        number = (number / 10);
        printf("the number after remove the last digit is %i \n", number);
    }

    printf("this is the sum : %i \n", storage + number);
}
###############################################################################################################################
*/