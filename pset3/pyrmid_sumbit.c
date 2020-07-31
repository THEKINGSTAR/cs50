//pyrmid_sumbit.c

#include <cs50.c>
#include <stdio.h>

int main(void)
{

    int inputed_Pyramid_Hight = 10; //get_int("please enter positve number for hights more than 0 : \n");

    if (inputed_Pyramid_Hight > 0)
    {
        int incressing_the_hights = 1;

        while (inputed_Pyramid_Hight > 0)
        {
            for (int drow_Pyramids_Wights = inputed_Pyramid_Hight; drow_Pyramids_Wights > 0; drow_Pyramids_Wights--)
            {
                printf(" ");
            }

            //if the number is still more than zero print
            //and encrees the number when exit
            if (inputed_Pyramid_Hight > 0)
            {
                for (int drow_Pyramids_Hights = 0; drow_Pyramids_Hights < incressing_the_hights; drow_Pyramids_Hights++)
                {
                    printf("#");
                }
                
                printf("  ");
                
                for (int drow_Pyramids_Hights = 0; drow_Pyramids_Hights < incressing_the_hights; drow_Pyramids_Hights++)
                {
                    printf("#");
                }
                
                incressing_the_hights = incressing_the_hights + 1;
            }

            printf("\n");

            inputed_Pyramid_Hight = inputed_Pyramid_Hight - 1;
        }
    }
    else
    {
        main();
    }
    return 0;
}