//algorithm

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

string loop_in_array(string elections_receved);
int find_the_biiger(int k, int l, int m, int n, int o);

int counter_of_k = 0;
int counter_of_l = 0;
int counter_of_m = 0;
int counter_of_n = 0;
int counter_of_o = 0;

int main(void)
{

    string elections[8];
    elections[0] = "k";
    elections[1] = "k";
    elections[2] = "o";
    elections[3] = "m";
    elections[4] = "l";
    elections[5] = "m";
    elections[6] = "k";
    elections[7] = "n";


/* 
string array_of_singels[5];
array_of_singels[0] = "k";
array_of_singels[1] = "l";
array_of_singels[2] = "m";
array_of_singels[3] = "n";
array_of_singels[4] = "o";

 */

    for (int i = 0; i <= 8; i++)
    {
    /*     if (elections[i] == "m")
        {
            printf("found in index number # %i : %s \n", i + 1, elections[i]);
            counter_of_m++;
        }
    */

    loop_in_array(elections[i]);

    }

    //printf(" m founde %i  tiems \n", counter_of_m);
}

string loop_in_array(string elections_receved)
{
        if (elections_receved == "k")
        {
            counter_of_k++;
        }
        else if (elections_receved == "l")
        {

            counter_of_l++;
        }
        else if (elections_receved == "m")
        {

            counter_of_m++;
        }
        else if (elections_receved == "n")
        {

            counter_of_n++;
        }
        else if (elections_receved == "o")
        {

            counter_of_o++;
        }

        printf("K # is %i ;- L # is  %i ; M # is %i ; N # is %i  ; O # is %i  \n", counter_of_k, counter_of_l, counter_of_m, counter_of_n, counter_of_o);
        find_the_biiger(counter_of_k, counter_of_l, counter_of_m, counter_of_n, counter_of_o);

        return 0;
}

int find_the_biiger(int k,int l,int m,int n,int o)
{
    if (k > l & k > m & k > o & k > n)
    {
        printf("k ,%i \n",k);
    }
    else if (m > k & m > n & m > o & m > l)
    {
        printf("m , %i \n",m);
    }
    

    return 0;
}
