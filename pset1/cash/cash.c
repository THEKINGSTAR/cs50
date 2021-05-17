#include <stdio.h>
#include <cs50.h>


//function for check if the input mony is divided by 5 or 1 or 25 or 10
int cash_check(cash)
{
    int amount = cash;

    int count = 0;

    while (amount > 0)
    {
        if (amount > 24)
        {
            amount = amount - 25;
            count = count + 1;
            printf("amount now  in 25 calc is :%i \n", amount);
            printf("count in 25 calc is :%i \n", count);
            printf("------ \n");
        }

        if (amount < 25 && amount > 9)
        {
            amount = amount - 10;
            count = count + 1;
            printf("amount now  in 10 calc is :%i \n", amount);
            printf("count in 10 calc is :%i \n", count);
            printf("------ \n");
        }

        if (amount < 10 && amount > 4)
        {
            amount = amount - 5;
            count = count + 1;
            printf("amount now  in 5 calc is :%i \n", amount);
            printf("count in 5 calc is :%i \n", count);
            printf("------ \n");
        }

        if (amount < 10 && amount > 0)
        {
            amount = amount - 1;
            count = count + 1;
            printf("amount now  in 1 calc is :%i \n", amount);
            printf("count in 1 calc is :%i \n", count);
            printf("------ \n");
        }

    }
    printf("%i \n", count);

    return 0;
}




float checking_input(void)
{
    float inputed_amount = get_float("please enter amount  \n");

    if (inputed_amount > 0)//& inputed_amount < 1)
    {
        int convert = inputed_amount * 100;
        printf("%i \n", convert);
        cash_check(convert);
    }

    else
    {
        checking_input();
    }

    return 0;
}



int main(void)
{
    checking_input();
}