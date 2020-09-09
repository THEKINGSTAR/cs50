#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
bool vote(string name);
void print_winner(void);

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
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    //pringint the number of candidates
    //printf("number of candidates %i\n",candidate_count);

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    for (int l = 0; l < candidate_count; l++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            string rsort_name = candidates[i + 1].name;
            int rsort_vote = candidates[i + 1].votes;

            string lsort_name = candidates[i].name;
            int lsort_vote = candidates[i].votes;

            string temp_name;
            int temp_vote;

            if (rsort_vote > lsort_vote)
            {
                temp_name = candidates[i].name;
                temp_vote = candidates[i].votes;

                candidates[i].name = candidates[i + 1].name;
                candidates[i].votes = candidates[i + 1].votes;

                candidates[i + 1].name = temp_name;
                candidates[i + 1].votes = temp_vote;
            }
        }
    }
    /*
            //checking the sort algorithm and the correct orders of the names:

            printf("end of souting , printing the sort and there votes \n");

            for (int s = 0; s <candidate_count ; s++)
            {
                printf("the candiate %s ,have : %i votes \n", candidates[s].name, candidates[s].votes);
            }
            */

    //----------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    //CREATING WINNER COUNTER AND ENCREMET IT ACCOURDING TO THE TOTAL VOTES
    /*
    //counting the total winner an print them if any
    int count_winner = 0;

    if (candidates[0].votes > candidates[1].votes)
    {
        //printf("the winner is %s whit total of  %i votes \n", candidates[0].name, candidates[0].votes);
        printf("%s \n", candidates[0].name);
        count_winner = count_winner + 1;
    }

    if (count_winner == 0)
    {
        for (int i = 0; i < candidate_count; i++)
        {

            if (candidates[i].votes == candidates[i + 1].votes)
            {
                // printf("%s \n", candidates[i].name);

                count_winner = count_winner + 1;
                printf("%s \n", candidates[i].name);
                // printf("count inside the more than one winner %i \n", count_winner);
            }
        }
    }

    printf("count of wiiners counting form 0 is :  %i \n",count_winner);

    for (int i = 0; i <=count_winner; i++)
    {
        printf("%s \n", candidates[i].name);
    }

 */
    //----------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    //BUT SINCE THE ARRAY IS SORTING THERE IS NO NEED FOR THIS SO DO IT WITH MORE SIMBLE WAY
    //counting the total winner an print them if any
    if (candidates[0].votes > candidates[1].votes)
    {
        printf("%s\n", candidates[0].name);
        return;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        /*         if (candidates[i].votes == candidates[i + 1].votes)
        {
            printf("%s \n", candidates[i].name);
            if ( candidates[i - 1].votes > candidates[i].votes )
            {
                return;
            }
        }
 */
        if (candidates[i - 1].votes > candidates[i].votes)
        {
            return;
        }
        printf("%s\n", candidates[i].name);
    }

    //----------------------------------------------------------------------------------------------------------------------
    //--------------------------------TESTING THE OUTPUT NOTHING MORE ------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    /*
    string winner = "";
    for (int i = 0; i <candidate_count; i++)
    {
        int next_candiata=i+1;
        if (candidates[i].votes > candidates[next_candiata].votes)
        {
            winner = (candidates[i].name);
            //printf(" %i \n", candidates[0].votes);
            printf("%s \n", winner);
            return ;
        }
        if (candidates[i].votes == candidates[i-1].votes)
        {
            winner = (candidates[i].name);

            printf("%s \n", winner);
        }
    }
    */

    return;
}

/**################################################################################################################################*/
/*TESTIN CASES */
/*
Results for cs50/problems/2020/x/plurality generated by check50 v3.1.2
:) plurality.c exists
:) plurality compiles
:) vote returns true when given name of first candidate
:) vote returns true when given name of middle candidate
:) vote returns true when given name of last candidate
:) vote returns false when given name of invalid candidate
:) vote produces correct counts when all votes are zero
:) vote produces correct counts after some have already voted
:) vote leaves vote counts unchanged when voting for invalid candidate
:) print_winner identifies Alice as winner of election
:) print_winner identifies Bob as winner of election
:) print_winner identifies Charlie as winner of election
:) print_winner prints multiple winners in case of tie
:) print_winner prints all names when all candidates are tied
To see the results in your browser go to https://submit.cs50.io/check50/727d02b12253a83b85f3bb6e36ecbc99ebc6ba0a

*/
