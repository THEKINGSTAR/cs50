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
        printf("%i\n", count_key_letters);
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
    string input_text = get_string("", "plaintext:\n");
    assciconvert(input_text, key);
    return 0;
}

/*------------------------------assciconvert -------------------------------------*/
//https://www.asciichart.com/

int assciconvert(string input_text,string key)
{
    //sort the key in array of 26 letter
    int array_of_keys[26];
    for (int i = 0; i <27; i++)
    {
        //to_convert[i] = atoi(text[i]);
        array_of_keys[i] = ( "%i",key[i] );
        //converted every givin charc to number
    }
    //for each letter inputed from the user in the array == what it is in the key upper case or lower case
    //[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]
    //create tow arrays of asscii one fore lower alpha && one fore upper alpha
    int lower_case[26];
    for (int l = 0; l < 26; l++)
    {
        
        lower_case[l] = 97 + l;
    }
    int upper_case[26];
    for (int u = 0; u < 26; u++)
    {
        upper_case[u] = 65 + u;
    }
    //convert the input text to array of int
    int lenght = strlen(input_text);
    int array_of_input[lenght];
    for(int l = 0 ; l < lenght ; l++)
    {
        //to_convert[i] = atoi(text[i]);
        array_of_input[l] = ("%i", input_text[l]);
        //converted every givin charc to number
    }
        /*
            array_of_keys;
            [#,#,#,#,#,#,#]
            array_of_input;
        */
    for (int i = 0; i<lenght-1 ; i++)
    //loop in hole text
    {
         for (int j = 0; j < 26; j++)
         //loop in every alphabet charctar to see what it equal in asscii and convert it to key
         {
             if (isupper(array_of_input[j]))
             {
                 if ( array_of_input[j] == upper_case[j] )
                 {
                     if (isupper(array_of_keys[j]))
                     {
                         array_of_input[j] = array_of_keys[j];
                         printf("%c", array_of_input[j]);
                     }
                     if (islower(array_of_keys[j]))
                     {
                         array_of_input[j] = array_of_keys[j];
                         printf("%c", array_of_input[j-32]);
                     }
                 }
             }
             if (islower(array_of_input[j]))
             {
                 if (array_of_input[j] == lower_case[j])
                 {
                     if (islower(array_of_keys[j]))
                     {
                         array_of_input[j] = array_of_keys[j];
                         printf("%c", array_of_input[j]);
                     }
                     if (isupper(array_of_keys[j]))
                     {
                         array_of_input[j] = array_of_keys[j];
                         printf("%c", array_of_input[j+32]);
                     }
                 }
             }
         }
    }

    return 0;
}
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