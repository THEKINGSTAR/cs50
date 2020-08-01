#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int last_tow_sec_sum =27;
    long long number = 378282246310005;
    int sum_first_digit;

    while ((number / 10) != '\0')
    {
        printf("the enterd number is  %i \n", number);

        printf("this is the sum_first_digit before add  : %i \n", sum_first_digit);

        //substract the last digit from the inputed number and sum those sustracted numbers
        printf("the last digit now is : %i \n", (number - ((number / 10) * 10)));

        sum_first_digit = sum_first_digit + (number - ((number / 10) * 10));

        printf("this is the sum_first_digit after  add  : %i \n ", sum_first_digit);

        // this update  the number with removing  tha last digit
        number = (number / 100);
        printf("the number after remove the last digit is %i \n", number);
    }

    sum_first_digit = sum_first_digit + number;

    printf("this is the sum_first_digit : %i \n", sum_first_digit);

    int total_sum = sum_first_digit + last_tow_sec_sum;

    printf("the total sum is : %i  ", total_sum);
}