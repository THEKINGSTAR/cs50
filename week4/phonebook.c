#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    FILE *file = fopen("phoneboo.csv" , "a");
    
    char *name   =get_string("Name :");
    char *number =get_string ("NUmber :");


    fprintf(file,"%s ,%s \n",name , number);

    fclose(file);

}