//substitution
/*
A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. 
This 26-character key means that A (the first letter of the alphabet)
  should be converted into N (the first character of the key), B (the second letter of the alphabet)
  should be converted into Q (the second character of the key), and so forth.
*/

#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string key_validate(string input_key);
int text_to_cypher(int key);
string cipher(string text, int key);

/*-----------------------Take key    from user--------------------------------------------------*/
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        key_validate(argv[1]);
    }
    else
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
}

/*-----------------------check if the lenght of the user input is 26 digit ---------------------*/
//non repeated alpha
//no numbers in the key
string key_validate (string input_key)
{
    int count_key_letters = 0;
    int check_repated_letter =0;
    int check_digit_in_key =0;
    for (int i = 0; i < strlen(input_key); i++)
    {

        if (isalpha(input_key[i]))
        {
            for (int j = 0; j < i; j++)
            {
                if ( input_key[j] == input_key[i] )
                {
                    check_repated_letter ++ ;
                }
                count_key_letters++;
            }
        }
        if(isdigit(input_key))
        {
            check_digit_in_key ++ ;
        }
    }
    if (count_key_letters == 26 & check_repated_letter ==0)
    {
        if (check_digit_in_key > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else
        {
            assciconvert(input_key);
        }
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    return 0;
}

/*-------------------------------take text from user  to cipher -------------------------------------*/

int text_to_cypher(key)
{
    string input_text = get_string("", "plaintext:\n");
    cipher(input_text, key);
    return 0;
}

/*------------------------------assciconvert -------------------------------------*/
//https://www.asciichart.com/

string assciconvert(key)
{
    //sort the key in array of 26 letter
    int array_of_keys[26];
    for (int i = 0; i <27; i++)
    {
        //to_convert[i] = atoi(text[i]);
        array_of_keys[i] = ( "%i",key[i] );
    }


    //for each letter inputed from the user in the arry

}


/*----------------------- sipher the text but this time leter by letter  ---------------------*/
//becuse we everty letter in itis own is key

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


/*
string to_convert(text)
{
    int lenght = strlen(text);
    int to_convert[lenght];

    for (int i = 0; i < strlen(text); i++)
    {
        //to_convert[i] = atoi(text[i]);
        to_convert[i] = ("%i", text[i]);
    }
    return to_convert,lenght;
}
*/