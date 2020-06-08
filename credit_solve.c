#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("Please give me your credit card number: ") ;

    long long card_num = 0LL;

    while (card_num < 1LL || card_num > 9999999999999999LL)
    {
        card_num = get_long_long("Please inter a valide credit card number : ");
    }

    // Make a copy of the card number to be used and modified throughout the process.

    long long temp_num = card_num;

    // Isolate every digit from the credit card number using a loop and the variable 'digit'.
    // Keep track of the amount and position of each digit using variable 'count'.

    int count = 0;

    while (temp_num > 0LL)
    {
        temp_num = temp_num / 10LL;
        count++;
    }

    // If the number entered doesn't have the right amount of digits according
    // to variable 'count', declare the number as invalid.

    if (count != 13 && count != 15 && count != 16)
    {
        printf("This is an invalid number (# of digits).\n");
        return 1;
    }

    // Reset value of variable 'temp_num' and apply calculations that will isolate the first two digits. 
    // Store the results in a variable 'company_id'.

    temp_num = card_num;

    while (temp_num > 100LL)
    {
        temp_num = temp_num / 10LL;
    }

    int company_id = temp_num;

    // Print the type of credit card depending on the company ID and amount of digits.

    if (company_id > 50 && company_id < 56 && count == 16)
    {
        printf("MASTERCARD\n") ;
    }
    else if ((company_id == 34 || company_id == 37) && (count == 15)) 
    {
        printf("AMEX\n") ;
    }
    else if ((company_id / 10 == 4) && (count == 13 || count == 16 || count == 19))
    {
        printf("VISA\n") ;
    }
    else
    {
        printf("This card was issued by an unknown company.\n");
    }

    // Apply Luhn's algorithm.

    int sum = 0;

    temp_num = card_num;

    for (int i = 1; i <= count; i++)
    {
        int digit = temp_num % 10LL;

        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;

        temp_num /= 10LL;
    }

    // Checking the validity of the number according to Luhn's algorithm

    if (sum % 10 != 0)
    {
        printf("This is an invalid number (Luhn's algorithm).\n");
        return 1; 
    }

    printf("This is a valid number.\n");

    return 0;
} 
