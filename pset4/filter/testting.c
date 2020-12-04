#include <stdio.h>
#include <math.h>
#include "helpers.h"
#include <cs50.h>

int main(void)
{

    int count_i = 0;
    int count_j = 0;

    int ith = 1;

    for (int i = 0; i < 3; i++)
    {
        int jth = 1;
        printf("I is :%i \n", ith);

        for (int j = 0; j < 3; j++)
        {

            printf("J is :%i \n", jth);
            count_j++;
            count_i++;
            jth++;
        }
        ith++;
    }
    printf("count i  is :%i \n", count_i);
    printf("count j  is :%i \n", count_j);

    printf("\n");
    //return 0;
}
