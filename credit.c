#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <stdlib.h>

// valid credit number for test 4003600000000014

long long  validty_check() ;
bool lengh_chek();
long long lenght_clac();

    //main
    int main(void)
{
    //#1- prombit user for input number
    validty_check();
    
    //#2- check if the number is correct or not
    
    //#3- run check usm on th number to show if it is valid credit card number
}

//prombit user for input number
long long validty_check()
{
    //check if the number is correct or not
    long long input_number = get_long_long("please enter your card number : \n ");
    if (input_number > 0)
    {
        if (lenght_clac(input_number) == false)
        {
            //if the number enterd is not correct prombit user for entring correct number
            validty_check();
        }
        else
        {
            printf("the enterd number is correct is , %LL \n", input_number);
        }
    }
    else
    {
        validty_check();
    }
    
    
    
   
}
//check if the enterd number is 14 digit 
long long lenght_clac(number)
{
    int lenght ;

    for(int i=0 ; i<lenght ; i++)
    {
        while(number != 0)
        {
            number = number / 10;
            printf("number now is %i , ", number);
            printf("I now is : %i , lenght now is %i : \n", i, lenght);
            lenght = lenght + 1;
        }    
    }

    printf("After finishing the loop the number %LL \n",number);

    return lengh_chek(lenght);
}

bool lengh_chek(lenght_clac_number)
{
    if (lenght_clac_number > 14)
    {
        printf("lenght is true = :%i  \n", lenght_clac_number);
        return true;
    }
    else
    {
        printf("lenght is false = :%i  \n", lenght_clac_number);
        return false;
    }
}
