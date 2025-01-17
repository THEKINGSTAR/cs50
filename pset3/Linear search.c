//Linear search
//Let’s take a look at numbers.c:

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of numbers
    int numbers[] = {4, 8, 15, 16, 23, 42};

    // Search for 50
    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == 50)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}


/*********************************************************************************************************************************************
Here we initialize an array with some values, and we check the items in the array one at a time, in order.
And in each case, depending on whether the value was found or not, we can return an exit code of either 0 (for success) or 1 (for failure).
*********************************************************************************************************************************************/
//We can do the same for names:

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of names
    string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

    // Search for EMMA
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "EMMA") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}


/********************************************************************************************************************************
We can’t compare strings directly, since they’re not a simple data type but rather an array of many characters,
 and we need to compare them differently. Luckily, 
 the string library has a strcmp function which compares strings for us and returns 0 if they’re the same, so we can use that.
*********************************************************************************************************************************/

//Let’s try to implement a phone book with the same ideas :


#include <cs50.h>
#include <stdio.h>
#include <string.h>

        int
        main(void)
    {
        string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
        string numbers[] = {"617–555–0100", "617–555–0101", "617–555–0102", "617–555–0103"};

        for (int i = 0; i < 4; i++)
        {
            if (strcmp(names[i], "EMMA") == 0)
            {
                printf("Found %s\n", numbers[i]);
                return 0;
            }
        }
        printf("Not found\n");
        return 1;
    }

/********************************************************************************************************************************************    
We’ll use strings for phone numbers, since they might include formatting or be too long for a number.
Now, if the name at a certain index in the names array matches who we’re looking for,
we’ll return the phone number in the numbers array,
at the same index. But that means we need to particularly careful to make sure that each number corresponds to the name at each index,
especially if we add or remove names and numbers.
********************************************************************************************************************************************/