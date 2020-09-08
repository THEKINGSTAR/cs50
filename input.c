#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string("can you give me your name , please : \n ");
    printf(" hi %s \n ",name);
}