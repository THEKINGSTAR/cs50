#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions.
More formally, if p is some plaintext (i.e., an unencrypted message),
pi is the ith character in p, and k is a secret key (i.e., a non-negative integer),
then each letter, ci, in the ciphertext, c, is computed as

ci = (pi + k) % 26

*/

/*-----------------------Take input from user---------------------*/

int digit_check(string input_text);
int text_to_cypher(int key);
string cipher(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //printf("argv enterd is %s \n", argv[1]);
        //string input_text                     = "This is CS50!" ; //argv[1];
        //key will be :: 2 :: output shoud be   :: Vjku ku EU50!
        return digit_check(argv[1]);
    }
    else
    {
        //printf("Usage: ./caesar key ::main::\n");
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //printf("main loaded\n");
}

int digit_check(string input_text)
{
    int count_nun_digit = 0;
    for (int i = 0; i < strlen(input_text); i++)
    {

        if (isdigit(input_text[i]))
        {
            //printf("is digit \n");
        }
        else
        {
            //printf("is alpha \n");
            count_nun_digit++;
        }
    }
    if (count_nun_digit == 0)
    {
        int key = (atoi(input_text));
        //printf("key is %i\n", key);
        while (key > 26)
        {
            key = key - 26;
        }
        text_to_cypher(key);
    }
    if (count_nun_digit > 0)
    {
        //printf("Usage: ./caesar key ::digit_check::\n");
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

int text_to_cypher(key)
{
    string input_text = get_string("plaintext:\n");
    cipher(input_text, key);
    return 0;
}

string cipher(string text, int key)
{
    printf("ciphertext:\n");
    int lenght = strlen(text);
    int to_convert[lenght];

    for (int i = 0; i < strlen(text); i++)
    {
        //to_convert[i] = atoi(text[i]);
        to_convert[i] = text[i];
    }

    int charac;
    for (int j = 0; j < lenght; j++)
    {
        charac = to_convert[j];
        if (isalpha(charac))
        {
            if (isupper(charac))
            {
                if ((charac + key) >= 90)
                {
                    int upper_convert = ((charac + key) % 90);
                    printf("%c", (upper_convert + 64));
                }
                else
                {
                    printf("%c", (charac + key));
                }
            }
            if (islower(charac))
            {
                if ((charac + key) >= 122)
                {
                    int lower_convert = ((charac + key) % 122);
                    printf("%c", (lower_convert + 96));
                }
                else
                {
                    printf("%c", (charac + key));
                }
            }
        }
        else
        {
            printf("%c", charac);
        }
    }
    printf("\n");
    return 0;
}

//make caesar
//check50 cs50/problems/2020/x/caesar
//style50 caesar.c
//submit50 cs50/problems/2021/x/caesar
