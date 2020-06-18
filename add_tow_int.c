#include <stdio.h>
#include <ctype.h>

sum(int a, int b);

int main(void)
{
    int a =  898;
    int b =  -270 ;
    //sum(a,b);
    printf("%i",sum(a , b));
    return 0;
}

int sum(a, b)
{
    int sum = 0 ;
    if ( a > 0)
    {
        for(int i = 0 ; i < a ; i++)
        {
            //sprintf("%i",sum++);
            sum++;
        }
    }
    else
    {
        for (int i = a ; i < 0 ; i++)
        {
            //printf("%i",sum++);
            sum--;
        }
    }
    if (b > 0)
    {
        for (int i = 0; i < b; i++)
        {
            //printf("%i",sum++);
            sum++;
        }
    }
    else
    {
        for (int i = b; i < 0; i++)
        {
            //printf("%i",sum++);
            sum--;
        }
    }
    return sum;
}