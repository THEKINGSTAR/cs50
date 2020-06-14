//testing
#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string digit_check();

int main(void)
{
    string key = "NQXPOMAFTRHLZGECYJIUWSKDVB";
    string input_text = "KHALED MOHAMAED";

    int array_of_keys[26];
    for (int i = 0; i < 26; i++)
    {
        //to_convert[i] = atoi(text[i]);
        array_of_keys[i] = key[i];
        //converted every givin charc to number
    }

    int lenght = strlen(input_text);
    int array_of_input[lenght];
    for (int l = 0; l < lenght; l++)
    {
        //to_convert[i] = atoi(text[i]);
        array_of_input[l] = input_text[l];
       // printf("%i,", array_of_input[l]);
        //converted every givin charc to number
    }
    for (int i = 0; i < lenght ; i++)
    //loop in hole text
    {

            int charc = array_of_input[i];
            loop_in_charactar(charc, array_of_keys);
        
    }

    return 0;
}

int loop_in_charactar(string charc, string array_of_keys)
{

    //sort the key in array of 26 letter

    //for each letter inputed from the user in the array == what it is in the key upper case or lower case
    //[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]
    //create tow arrays of asscii one fore lower alpha && one fore upper alpha
    int asscii_lower_case[26];
    for (int l = 0; l < 26; l++)
    {
        asscii_lower_case[l] = 97 + l;
        //printf("%c", lower_case[l]);
    }
    int asscii_upper_case[26];
    for (int u = 0; u < 26; u++)
    {
        asscii_upper_case[u] = 65 + u;
        //printf("%c",upper_case[u]);
    }
    //convert the input text to array of int

    /*
            array_of_keys;
            [#,#,#,#,#,#,#]
            array_of_input;
        */

    for (int j = 0; j < 26; j++)
    //loop in every alphabet charctar to see what it equal in asscii and convert it to key
    {

/*         for (int j = 0; j < 1; j++)
        {
            
        } */

        int upper = asscii_upper_case[j];
        //printf("%i,", charc);
        if (isalpha(charc))
        {
            if (isupper(charc))
            {
                if (charc == upper)
                {
                    printf("#%c#", upper);
                    if (isupper(array_of_keys[j]))
                    {
                        charc = array_of_keys[j];
                        printf("%c", atoi(charc));
                    }
                    if (islower(array_of_keys[j]))
                    {
                        charc = array_of_keys[j];
                        printf("%c", charc - 32);
                    }
                }
            }
            if (islower(charc))
            {
                if (charc == asscii_lower_case[j])
                {
                    if (islower(array_of_keys[j]))
                    {
                        charc = array_of_keys[j];
                        printf("%c", charc);
                    }
                    if (isupper(array_of_keys[j]))
                    {
                        charc = array_of_keys[j];
                        printf("%c", charc + 32);
                    }
                }
            }
        }
        else
        {
            // printf("%c", charc);
        }

        return 0;
    }
}