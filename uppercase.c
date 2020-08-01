#include <stdio.h>
#include <ctype.h>
#include <cs50.c>
#include <string.h>

int main(void)
{

    string name = get_string("","Please give me your name : ");
    printf("Your name in UPPER CASE : ");

    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] >= 'a' && name[i] <='z')
        {
            //convert to upper case
            printf("%c",name[i]-32);
        }
        else
        {
            /* pinrt the same crater */
            printf("%c",name[i]);
        }
        
    }
    
    printf(" \n ");

printf("//using the <ctype.h> libraary \n");

    for (int i = 0; i < strlen(name); i++)
    {
            /* pinrt the same crater */
            printf("%c", toupper(name[i]));
     
    }
}