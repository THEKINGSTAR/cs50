#include <stdio.h>
#include <cs50.c>
#include <math.h>
#include <string.h>
#include <ctype.h>

    //Coleman-Liau index is computed using the formula:
    /*    index = 0.0588 * L - 0.296 * S - 15.8     */


int main(void)
{
    string input=get_string("","Text : \n");
/* 
    int letters_count=0;
    for (int i = 0; i < strlen(input) ; i++)
    {
        if(input[i]!='\0'&input[i]!=" ")
        {
            letters_count ++;
        }
    }
    printf("%i \n",letters_count); 
*/

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
        if (input[i] == ' ' & input[i+1] != ' ')
        {
            its_word++;
        }
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence ++;
        }
     }
     its_word ++;
     
    printf("%i letter(s)   \n" , its_alpha );
    printf("%i word(s)     \n" , its_word  );
    printf("%i sentence(s) \n" , sentence  );
//printf("%i digit(s)    \n" , its_digit );



    float avg_word_p_litter =((double)its_alpha/its_word)*100 ;
    float avg_sentences_p_word_letters = ((double)sentence / its_word) * 100;
//int avg_word = round(avg_word_p_litter);
//int avg_sentence =round(avg_sentences_p_word_letters);
//printf("%i , %i\n", avg_word, avg_sentence);

    float index = ((0.0588 * avg_word_p_litter) - (0.296 * avg_sentences_p_word_letters) - 15.8);
    int grade = round(index);

    if (grade<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (grade > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", grade);
        }
        
        
    }
    
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