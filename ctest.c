#include <stdio.h>
#include <cs50.c>
#include <string.h>

print_star();

int main(void)
{
    
///THREE DEFRENT WAY TO PRINT THE LITTER INT THE STRING ONE BY ONE

    string name=get_string("","Please enter your name : \n" );
   
//check if the cs50 library work

/*  printf("hello %s \n",name);

    int number = get_int("please give me number \n ");
    printf("the number is  %i \n",number);

    int modluler = number /100;
    printf("moduler is , %i \n", modluler);
*/

    print_star();

//string moduler = "9876543210";

    string s_number = name;

    for (int i = 0; s_number[i] != '\0'; i++)
    {
        printf("this is the index of the number  , %c \n", s_number[i]);

   }
   print_star();

   //Using strlen() function form <string.h>
   for (int i = 0; i < strlen(s_number); i++)
   {
       printf("this is the index of the number  , %c \n", s_number[i]);
   }

   print_star();

//BeEIng more implemetn tha calling the strlen() function again and again ,
   int n =strlen(s_number);
   for (int i = 0; i <  n ; i++)
   {
       printf("this is the index of the number  , %c \n", s_number[i]);
   }
   print_star();

//AGAIN BEeIng more implemetn tha calling the strlen() function again and again , AND declaring the int inside the for condition
   for (int i = 0, n = strlen(s_number) ; i < n ; i++ )
   {
       printf("this is the index of the number  , %c \n", s_number[i]);
   }
   print_star();
}

int print_star(void)
{
    for (int i = 0; i < 30; i++)
    {
        printf("*");
    }
    printf("\n");
}