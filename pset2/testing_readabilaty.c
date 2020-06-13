//testing codes 
#include <stdio.h>
#include <cs50.c>
#include <math.h>
#include <float.h>

int main(void)
{
    string input = get_string("", "Text : \n");
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

    /*


//***********************************************************************************************************
    //Coleman-Liau index is computed using the formula: index = 0.0588 *L - 0.296 *S - 15.8
    //where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text
//***********************************************************************************************************

Text: When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
*/
    //295 letter(s)
    //70 word(s)
    //3 sentence(s)
//***********************************************************************************************************
/*
    The text the user inputted has 65 letters, 4 sentences, and 14 words.
     65 letters per 14 words is an average of about 464.29 letters per 100 words. 
     And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words.
     Plugged into the Coleman-Liau formula, 
    and rounded to the nearest whole number, we get an answer of 3: so this passage is at a third grade reading level.
*/

    int letters = 65;
    int its_word = 14 ;
    int sentence = 4  ;


    float avg_word_p_litter =((double)letters/its_word)*100 ;
    float avg_sentences_p_word_letters = ((double)sentence / its_word) * 100;
    int avg_word = round(avg_word_p_litter);
    int avg_sentence =round(avg_sentences_p_word_letters);
    printf("%i , %i\n", avg_word, avg_sentence);

    float index = ((0.0588 * avg_word_p_litter) - (0.296 * avg_sentences_p_word_letters) - 15.8);
    int grade = round(index);
    printf("Grade %i \n", grade);
}