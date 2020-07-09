#include <stdio.h>
#include <cs50.h>

typedef struct 
{
    string names;
}
input_names ;

/* typedef struct 
{
    string candidate;
    int id;
    int voice_count;
}
coutn_voices;
 */
void swap(int *xp, int *yp);

int main(void)
{

 input_names elections[8];
 
 elections[0].names = "k";
 elections[1].names = "k";
 elections[2].names = "o";
 elections[3].names = "m";
 elections[4].names = "l";
 elections[5].names = "m";
 elections[6].names = "k";
 elections[7].names = "n";
 int total_votes=8;
 int candidtaes ;
 int single_vote        = total_votes;
 int total_enterd_names = 0 ;

 for (int loop_in_names = 0; loop_in_names <=8; loop_in_names ++)
 {
     for (; single_vote <=total_votes; single_vote ++)
     {
         string name_in_array = elections[loop_in_names].names;
         string every_vote_for = elections[single_vote].names ;
         if (name_in_array != every_vote_for)
         {
             printf("%s", every_vote_for);
             //the porbes of hte loop is to count how many defrent letter is there
             //check if the letter in the all input == the letter is beeing checked inside the loop if it is
             //do nothing
             //else add the counter +1 , the final count is the pure singer letter exist
             candidtaes++;
             }
    }
     if (candidtaes == 0)
     {
         total_enterd_names++;
     }
     total_votes--;
}


printf("%i \n",candidtaes);
printf("%i \n",total_enterd_names);


}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

    
}


void test()
{
    int array_of_numbers ={8,4,3,9,23,1,0,8,3,50,12,55};

    int array_lenght = len(array_of_numbers);

    for (int i = 0; i < array_lenght ; i++)
    {
        swap();
    }
    
}


