#include <stdio.h>
#include <string.h>
#include <cs50.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
string vote(string name);
void print_winner(void);

void sorting(void);
void find_the_winnner(void);
int check_the_existing_of_the_name(int index, string name)
/*###########END OF FUNCTIONS DEFINITIONS #######################*/

/*###########################///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////##################*/
                            /*######################## starting of the program ############################################*/
                            
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("","Vote: ");

        // Check for invalid vote
                //vote(name);
         if (!vote(name))
        {
            printf("Invalid vote.\n");
        } 
    }

    // Display winner of election
    print_winner();
}



/*////////////////////////////////////////////START OF MAIN PROGRAMS FUNCTIONS///////////////////////////////////////////////////////////*/

// Update vote totals given a new vote
string vote(string name)
{
    printf("Recived name , %s \n",name);
    printf("number of candidate to check is : %i \n",candidate_count);
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        string compareing_name = candidates[i].name;
        printf("Inside of the name chekingg loop , the name to check is %s \n", compareing_name);
        check_the_existing_of_the_name( i,  name);
    }
}



//sorting form gratest to lowest
void sorting(void)
{
    for (int l = 0; l < candidate_count; l++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            int rsort = candidates[i + 1].votes;
            int lsort = candidates[i].votes;
            string temp;
            if (rsort > lsort)
            {
                temp = candidates[i].name;
                candidates[i].name = candidates[i + 1].name;
                candidates[i + 1].name = temp;
            }
        }
    }
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //1- sorting based on total voices
    sorting();
    //2- find the one with the bigest voices if tai print the tow
    find_the_winnner();
}

//suposly to find if the name is exitst encress the votes by one
int check_the_existing_of_the_name(int index, string name)
{

    if (candidates[index].name == name)
    {
        printf("Cheking the name of : %s ", candidates[index].name);
        int adding_one_vote = candidates[index].votes ;
        adding_one_vote ++ ;
        candidates[index].votes = adding_one_vote ;
        printf("Candidate : %s , Have %i  Votes", candidates[index].name, candidates[index].votes);
    }

    return 0;
}

//supposley to find the biggest number if tow is equal return tow
    void
    find_the_winnner(void)
{
    if (candidates[0].votes > candidates[1].votes)
    {
        printf("%s", candidates[0].name);
    }
}