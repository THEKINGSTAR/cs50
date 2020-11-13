#include <cs50.h>
#include <stdio.h>

int condetion(hight)
{

    int i = 0;
    int spaceing = hight;
    while (i < hight)
    {
        int space = spaceing;
        while (space > 0)
        {
            printf(" ");
            space = space - 1;
        }
        int block = 0;
        while (block <= i)
        {

            printf("#");
            block = block + 1;
        }
        printf("  ");
        int block2 = 0;
        while (block2 <= i)
        {

            printf("#");
            block2 = block2 + 1;
        }

        printf("\n");

        spaceing = spaceing - 1;

        i = i + 1;
    }
    return 0;
}

int input(void)
{
    int hight = get_int("please enter positve number for hights between 1 to 8 : \n");

    if (hight > 0 && hight < 9)
    {
        condetion(hight);
    }
    else
    {
        input();
    }
    return 0;
}

int main(void)
{
    input();
}
