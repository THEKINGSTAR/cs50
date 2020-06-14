//test
#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(void)
{

    string key        = "nQXPOMAFTRHLZGECYJIUWSKDVB" ; 
    string input_text = "Hello"            ;

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
        printf("%c,", asscii_lower_case[l]);
    }
    printf("\n");
    string asscii_upper_case[26];
    for (int u = 0; u < 26; u++)
    {
        asscii_upper_case[u] = 65 + u;
        printf("%c,", asscii_upper_case[u]);
    }
    printf("\n");
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
for (int c = 0; c < 26 ; c++)
{
/*     if (isupper(array_of_keys[c]))
    {
        converted_asscii_upper_case[c] = array_of_keys[c];
        printf("%i,", converted_asscii_upper_case[c]);
    }
    if (islower(array_of_keys[c]))
    {
        converted_asscii_lower_case[c] = array_of_keys[c];
        printf("%i,", converted_asscii_lower_case[c]);
    } */
    converted_asscii_table[c] = array_of_keys[c];
}
printf("\n");

//loop in the lenght of the string
int lenght = strlen(input_text);
for (int l = 0; l < lenght; l++)
{
    //chek for every charcter position of the string
    for (int c = 0; c < 26; c++)
    {
        int charcter_in_text = input_text[l];

        if (isupper(charcter_in_text))
        {
            if (charcter_in_text == asscii_upper_case[c])
            {
                printf("%c", toupper(converted_asscii_table[c]));
            }
        }
        if (islower(charcter_in_text))
        {
            if (charcter_in_text == asscii_lower_case[c])
            {
                printf("%c", tolower(converted_asscii_table[c]));
            }
        }
    }
    
}
//chek where it belong to the asscii 

//chsnge the character with the one in the key as the posation of the key is the same position of the carcter in the asscii code



}