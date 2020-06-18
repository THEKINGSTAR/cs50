#include <stdio.h>
#include <cs50.c>

bool valid_traiangle(int a , int b , int c);
int bool_result(int bool_result);
string input();

int main(void)
{
    input();
}


string input()
{
    int a = get_int("Please enter the frist ent  \n");
    int b = get_int("Please enter the second ent \n");
    int c = get_int("Please enter the third ent  \n");
    valid_traiangle(a, b, c);
    int result = valid_traiangle(a, b, c);
    string validity = bool_result(result);
    printf("%s \n", validity);
}

bool valid_traiangle(int a , int b , int c)
{
    
    if (a > 0 & b > 0 & c > 0)
    {
        if (a + b > c || a + c > b || b + c > a )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false ; 
}

int bool_result(int bool_result)
{
    string results="";
    if (bool_result == 1)
    {
        results = "True";
    }
    else
    {
        results = "False";
    }
    return results;
}