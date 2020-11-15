#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main (void)
{
    int n = 50;

    printf("%i\n",  n );
    printf("%p\n",  &n);
    printf("%i\n", *&n);

    int *p = &n ;

    printf("%p\n",  p);
    printf("%i\n", *p);

    char *s = "EMMA WATSON";
    // s now is the character secunsys to the null tirminator
    printf("%s\n",s);


    //print (pointer ) the address of the string AKA character secunses
    printf("%p\n",s);

    // print the first chartctar of the name
    printf("%c\n",s[0]);
    
    //print hte adress of the fist char in tne mane
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n", &s[4]);

    //print the character in the frist adress of the name
    printf("%c\n", *s);

    //print the second latter of the name 
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));
}