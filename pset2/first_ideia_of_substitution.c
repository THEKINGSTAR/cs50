//substitution

#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions.
More formally, if p is some plaintext (i.e., an unencrypted message), 
pi is the ith character in p, and k is a secret key (i.e., a non-negative integer), 
then each letter, ci, in the ciphertext, c, is computed as

//https://www.asciichart.com/
//ALGORATHIM  #### ci = (pi + k) % 26 ####

*/

/*
A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. 
This 26-character key means that A (the first letter of the alphabet)
  should be converted into N (the first character of the key), B (the second letter of the alphabet)
  should be converted into Q (the second character of the key), and so forth.


*/

/*-----------------------Take input from user---------------------*/

string digit_check(string input_key);
int text_to_cypher(int key);
string cipher(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //printf("argv enterd is %s \n", argv[1]);
        digit_check(argv[1]);
    }
    else
    {
        //printf("Usage: ./caesar key ::main::\n");
        printf("Usage: ./substitution key \n");
    }
    //printf("main loaded\n");
}

//Check user argv input is digit and not many argv
string digit_check(string input_key)
{
    int count_key_letters = 0;
    for (int i = 0; i < strlen(input_key); i++)
    {

        if (isalpha(input_key[i]))
        {
            //printf("is digit \n");
            count_key_letters++;
        }
        else
        {
            //printf("is alpha \n");
            
        }
    }
    if (count_key_letters == 26)
    {
        //printf("key is %i\n", key);
        //if the key enterd is bigger thean the aphabit count >26
        int lenght = strlen(input_key);
        int key_to_convert[lenght];
        for (int i = 0; i < strlen(input_key); i++)
        {
            //to_convert[i] = atoi(text[i]);
            key_to_convert[i] = ("%i", input_key[i]);
        }
        while (key_to_convert > 26)
        {
            key_to_convert = key_to_convert - 26;
        }
        text_to_cypher(key_to_convert);
    }
    else
    {
        //printf("Usage: ./caesar key ::digit_check::\n");
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

int text_to_cypher(key)
{
    string input_text = get_string("", "plaintext:\n");
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
        to_convert[i] = ("%i", text[i]);
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