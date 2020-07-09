#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    // get canditate names
    // whay count !!!!??? in case i want it 😂 who know ???
    string name ;
    int    count;
}
canditate;

typedef struct 
{
    //create anew array with only sigle name input for the canditate without repeating his name
    //by
    //looping in everey intery of the array lenght chek if the mane exits in that entary or not

    string canditate_name  ;
    int    candiate_voises ;
}
canditate_voices_coutn;


//functions 
int input_check();

int voices_counter(int total_voices);

string get_names();

void loop_in_names(string human, int votes);




int main(void)
{
    input_check();
}

int input_check()
{
    int votes =get_int("Please enter the votes coutn : \n");
    //still working on input cheking


     voices_counter(votes);
}

string get_names()
{
    //printf("please enter the name of #  vote \n");
    string person_name = get_string("","please enter the name of #  vote \n");
    return person_name;
}

int voices_counter(int total_voices)
{
    canditate human[total_voices];

    for (int v = 0; v < total_voices; v++)
    {
        string person_name = get_names();
        human[v].name = person_name;
    }

    for (int i = 0; i <= total_voices /*6*/; i++)
    {
        if (loop_in_names(human, total_voices) == 0)
        {
            return; 
        }
    }

    printf("votes is %i ", human[2].count);
}

void loop_in_names(string human int votes)
{
    for (int r = 0; r < votes; r++)
    {
        if (human[r].name == human[i].name)
        {
            human[i].count++;
            return 0;
        }
    }
}