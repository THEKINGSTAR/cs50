#include <stdio.h>
#include <cs50.c>
#include <string.h>

typedef struct 
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4] ;
    people[0].name ="Emma";
    people[0].number = "617.355.0100";

    people[1].name = "Rodrigos";
    people[1].number = "617.355.0101";

    people[2].name = "Brain";
    people[2].number = "617.355.0102";

    people[3].name = "Daivd";
    people[3].number = "617.355.0103";
/*
    string names[4]   = {"Emma","Rodrigos","Brain","Daivd"};
    string numbers[4] = {"617.355.0100", "617.355.0101", "617.355.0102", "617.355.0103"};

    for (int i = 0; i <4; i++)
    {
        if (strcmp(names[i], "Brain") == 0)
        {
            printf("%s\n",numbers[i]);
            return 0;
        }
        
    }
*/

for (int i = 0; i < 4; i++)
{
    if ( people[i].name == "Rodrigos" )
    {
        printf("%s \n" , people[i].name  );
        printf("%s \n" , people[i].number);
        return 0;
    }
}
    printf("not found \n");
    return 1;
}

