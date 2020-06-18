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

int key_validate(string input_key);
int text_to_cypher(int key);
int assciconvert(input_text, key);
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
int key_validate (string input_key)
{
    int count_key_letters = 0;
    int check_repated_letter =0;
    int check_digit_in_key =0;
    int key_kenght = strlen(input_key);
    for (int i = 0; i < key_kenght ; i++)
    {
        if (isalpha(input_key[i]))
        {
            for (int j = 0; j < i; j++)
            {
                if ( input_key[j] == input_key[i] )
                {
                    check_repated_letter ++ ;
                }
            }
        }
        count_key_letters++;
//printf("%i\n", count_key_letters);
        if(isdigit(input_key[i]))
        {
            check_digit_in_key ++ ;
        }
    }
//printf("%i\n",count_key_letters);
    if (count_key_letters == 26 )
    {
        if (check_digit_in_key > 0)
        {
            printf("Key must contain alphabit characters only.\n");
            return 1;
        }
        if (check_repated_letter > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }

        else
        {
            text_to_cypher(input_key);
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
    string input_text = get_string("", "plaintext:");
    printf("ciphertext: ");
    assciconvert(input_text, key);
    return 0;
}

/*------------------------------assciconvert -------------------------------------*/
//https://www.asciichart.com/

int assciconvert(string input_text,string key)
{
    /*
    string key = "nQXPOMAFTRHLZGECYJIUWSKDVB";
    string input_text = "Hello";
    */

    string array_of_keys[26];
    for (int i = 0; i < 26; i++)
    {
        //to_convert[i] = atoi(text[i]);
        array_of_keys[i] = key[i];
        //converted every givin charc to number
    }

    string asscii_lower_case[26];
    for (int l = 0; l < 26; l++)
    {
        asscii_lower_case[l] = 97 + l;
        //printf("%c,", asscii_lower_case[l]);
    }
        //printf("\n");
    string asscii_upper_case[26];
    for (int u = 0; u < 26; u++)
    {
        asscii_upper_case[u] = 65 + u;
        //printf("%c,", asscii_upper_case[u]);
    }
        //printf("\n");
    /*
        array_of_asscii_code(lower or upper);
        
        [#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#]
        
        array_of_keys;

        [#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#]
        
        array_of_input;
        
        [#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#,#]

    */

    //convert every character in the asscii to its key

/*
string converted_asscii_upper_case[26];
string converted_asscii_lower_case[26];
*/
    string converted_asscii_table[26];
    for (int c = 0; c < 26; c++)
    {
    /*     
    if (isupper(array_of_keys[c]))
    {
        converted_asscii_upper_case[c] = array_of_keys[c];
        printf("%i,", converted_asscii_upper_case[c]);
    }
    if (islower(array_of_keys[c]))
    {
        converted_asscii_lower_case[c] = array_of_keys[c];
        printf("%i,", converted_asscii_lower_case[c]);
    } 
    */
        converted_asscii_table[c] = array_of_keys[c];
    }
    //loop in the lenght of the string
    int lenght = strlen(input_text);
    for (int l = 0; l < lenght; l++)
    {
        //chek for every charcter position of the string
        int charcter_in_text = input_text[l];
        if (isalpha(charcter_in_text))
        {
            for (int c = 0; c < 26; c++)
            {

                if (isupper(charcter_in_text))
                {
                    if (charcter_in_text == asscii_upper_case[c])
                    {
                        printf("%c", toupper(converted_asscii_table[c]));
                        //printf("ciphertext: %c", toupper(converted_asscii_table[c]));
                    }
                }
                if (islower(charcter_in_text))
                {
                    if (charcter_in_text == asscii_lower_case[c])
                    {
                        //printf("ciphertext: %c", tolower(converted_asscii_table[c]));
                        printf("%c", tolower(converted_asscii_table[c]));
                    }
                }
            }
        }
        else
        {
            printf("%c", charcter_in_text);
        }
    }
    //chek where it belong to the asscii

    //chsnge the character with the one in the key as the posation of the key is the same position of the carcter in the asscii code

    return 0;
}

/*################ TEST CASES ################################*/
/*
:) substitution.c exists
:) substitution.c compiles
:( encrypts "A" as "Z" using ZYXWVUTSRQPONMLKJIHGFEDCBA as key
    expected "ciphertext: Z\...", not "Z"
:( encrypts "a" as "z" using ZYXWVUTSRQPONMLKJIHGFEDCBA as key
    expected "ciphertext: z\...", not "z"
:( encrypts "ABC" as "NJQ" using NJQSUYBRXMOPFTHZVAWCGILKED as key
    expected "ciphertext: NJ...", not "NJQ"
:( encrypts "XyZ" as "KeD" using NJQSUYBRXMOPFTHZVAWCGILKED as key
    expected "ciphertext: Ke...", not "KeD"
:( encrypts "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZTEOGXHCIPJSQD as key
    expected "ciphertext: Cb...", not "Cbah ah KH50"
:( encrypts "This is CS50" as "Cbah ah KH50" using yukfrnlbavmwzteogxhcipjsqd as key
    expected "ciphertext: Cb...", not "Cbah ah KH50"
:( encrypts "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZteogxhcipjsqd as key
    expected "ciphertext: Cb...", not "Cbah ah KH50"
:( encrypts all alphabetic characters using DWUSXNPQKEGCZFJBTLYROHIAVM as key
    expected "ciphertext: Rq...", not "Rqx tokug wlji..."
:) handles lack of key
:( handles invalid key length
    expected exit code 1, not 0
:( handles invalid characters in key
    expected exit code 1, not 0
:( handles duplicate characters in key
    expected exit code 1, not 0
:( handles multiple duplicate characters in key
    expected exit code 1, not 0
*/

/*
How to Test Your Code
Execute the below to evaluate the correctness of your code using check50.
But be sure to compile and test it yourself as well!

//---------------------------------------  check50 cs50/problems/2020/x/substitution
Execute the below to evaluate the style of your code using style50.

//---------------------------------------  style50 substitution.c
How to Submit
Execute the below, logging in with your GitHub username and password when prompted.
For security, you’ll see asterisks (*) instead of the actual characters in your password.

//--------------------------------------   submit50 cs50/problems/2020/x/substitution
*/



/*########################################code from caesar#########################################*/
/*########################################code from caesar#########################################*/
/*########################################code from caesar#########################################*/
/*########################################code from caesar#########################################*/

/*----------------------- sipher the text but this time leter by letter  ---------------------*/
//1- take every letter from inpute and compare it to what it equal to in asscii location
//2- convert the letter to what it is location is in the key



/*----------------------- sipher the text but this time leter by letter  ---------------------*/
//becuse we everty letter in itis own is key
/*

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
*/

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

/*########################################code from caesar#########################################*/
/*########################################code from caesar#########################################*/
/*########################################code from caesar#########################################*/
/*########################################code from caesar#########################################*/