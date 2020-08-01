#include <stdio.h>
#include <cs50.c>
#include <ctype.h>
#include <string.h>
#include <math.h>

string digit_check(string input_text);
int text_to_cypher(int key);
string cypher(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //printf("argv enterd is %s \n", argv[1]);
        //string input_text = "This is CS50!"; //argv;
        //key will be :: 2 :: output shoud be   :: Vjku ku EU50!
        digit_check(argv[1]);
    }
    else
    {
    //printf("Usage: ./caesar key ::main::\n");
    printf("Usage: ./caesar key\n");
    }
    //printf("main loaded\n");
}

string cypher(string text , int key)
{
    int lenght = strlen(text);
    int to_convert[lenght];

    for (int i = 0; i < strlen(text); i++)
    {
        to_convert[i] = ("%i", text[i]);
    }

    int charac;
    for (int j = 0; j < lenght; j++)
    {
        charac = to_convert[j];
        if (isalpha(charac))
        {
            if(isupper(charac))
            {
                int upper_convert = (((charac + key) % 26) + 65);
                printf("%c", upper_convert);
            }
            else
            {
                printf("%c", charac + key);
            }
        }
        else
        {
            printf("%c", charac);
        }
    }
    printf("\n");
}

string digit_check(string input_text)
{
    int coung_nun_digit = 0;
    for (int i = 0; i < strlen(input_text); i++)
    {

        if (isdigit(input_text[i]))
        {
            //printf("is digit \n");
        }
        else
        {
            //printf("is alpha \n");
            coung_nun_digit++;
        }
    }
    if (coung_nun_digit == 0)
    {
        int key = (atoi(input_text));
        //printf("key is %i\n", key);
        text_to_cypher(key);
    }
    else
    {
        //printf("Usage: ./caesar key ::digit_check::\n");
        printf("Usage: ./caesar key\n");
    }
}

int text_to_cypher(key)
{
    string input_text = get_string("", "Please enter your text\n");
    cypher(input_text, key);
}