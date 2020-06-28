#include <stdio.h>
#include <cs50.c>

typedef struct 
{
    string name ;
    int    count;
}
canditate;


int main(void)
{
    int votes = get_int("Please enter the votes coutn : \n");
    
    canditate human[votes];
    
    for(int v = 0 ; v < votes ; v++)
    {
        printf("please enter the name of # %i vote \n", v+1);
        string person_name =get_string("","");
        human[v].name = person_name ;
    }
    
    for (int i = 0; i <= votes /*6*/; i++)
    {
        for (int r = 0; r < votes; r++)
        {
            if (human[r].name == human[i].name)
            {
                human[i].count++;
            }
        }
    }

    printf("votes is %i ",human[2].count);
}