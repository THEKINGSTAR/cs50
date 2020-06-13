//testing
#include <stdio.h>
#include <cs50.c>
#include <ctype.h>
#include <string.h>
#include <math.h>

string digit_check();

int main(void)
{

/*
    string input_text  = get_string("","Please enter your text\n");
    digit_check(input_text);
 */

int mudol_number = (((122 + 65) / 97) + ((122 + 65) % 97));
printf("%i",mudol_number);
printf("%c",mudol_number);
int divid_number =123/122;
printf("%i", divid_number);

}

string digit_check(string input_text)
{
    int coung_nun_digit = 0;
    for (int i = 0; i < strlen(input_text); i++)
    {

        if ( isdigit( input_text[i] ) )
        {
            printf("is digit \n");
        }
        else
        {
            printf("is alpha \n");
            coung_nun_digit++;
        }
    }
    if (coung_nun_digit == 0)
    {
        printf("out side the opp recog is digit \n");
    }
    else
    {
        /* code */
    }
}