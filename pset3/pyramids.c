#include <stdio.h>
#include <cs50.c>

void pyramid(int hight) ;

int main(void)
{
    int highyt = get_int("Enter the pyramids hight: \n");
    pyramid(highyt);

}

void pyramid(int hight)
{

    if (hight == 0)
    {
        return;
    }

    pyramid(hight - 1 );

    for (int i = 0; i < hight; i++)
    {
        printf("#");
    }
    printf("\n");
}