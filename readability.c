#include <stdio.h>
#include <cs50.c>
#include <math.h>
#include <string.h>
#include <ctype.h>

    //Coleman-Liau index is computed using the formula:
    /*index = 0.0588 * L - 0.296 * S - 15.8*/


int main(void)
{
    string input=get_string("","Text : \n");

    int letters_count=0;
    for (int i = 0; i < strlen(input) ; i++)
    {
        if(input[i]!='\0'&input[i]!=" ")
        {
            letters_count ++;
        }
    }
    printf("%i \n",letters_count);

    int its_alpha = 0;
    int its_digit = 0;
    int its_word  = 0;
    int sentence  = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            its_alpha++;
        }
        if (isdigit(input[i]))
        {
            its_digit++;
        }
        if (input[i] ==' ')
        {
            its_word++;
        }
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence ++;
        }
        
     }
     its_word = its_word +1;
     
    printf("%i letter(s) \n ", its_alpha);
    printf("%i word(s) \n", its_word);
    print("%i sentence(s) \n", sentence);
    printf("%i digit(s) \n", its_digit);
}


/*-------test catsese---------------------------------------- */
/*
It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
*/
//250 letter(s)
//55 word(s)
/*-----------------------------------------------------------*/

/*
Text: When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
*/
//295 letter(s)
//70 word(s)
//3 sentence(s)