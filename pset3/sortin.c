//sortin

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int main(void)
{
 
    int numbers[9]={ 11 , 20 , 3 , 12 , 55 , 29 , 50 , 77 , 18 };

    for (int l = 0; l < 9 ; l++)
    {
        for (int i = 0; i < 9; i++)
        {
            int rsort = numbers[i + 1];
            int lsort = numbers[i];
            int temp;
            if (rsort > lsort)
            {
                temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1]=temp;
            }
        }
    }
    

    for (int l = 0; l <9; l++)
    {
        printf("%i \n", numbers[l]);
    }
}


