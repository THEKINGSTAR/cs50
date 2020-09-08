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

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i <= MAX; i++)
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
    string winner1 = "";
    string winner2 = "";

    // TODO
    for (int l = 0; l < MAX; l++)
    {
        for (int i = 0; i < MAX; i++)
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

printf("end of souting \n");
    int count_winner=0;
    //count the total winner an print them
    for (int i = 0; i < MAX; i++)
    {
       if (candidates[i].votes > candidates[i+1].votes)
       {
           count_winner =1;
           return;
       }
       if (candidates[i].votes == candidates[i + 1].votes)
       {
           count_winner = count_winner + 1;

       }
    }
    printf("%i \n",count_winner);
    for (int i = 0; i <count_winner; i++)
    {
        printf("%s \n", candidates[i].name);
    }
 
/* 
    if (candidates[0].votes > candidates[1].votes)
    {
        winner1 = (candidates[0].name);
        //printf(" %i \n", candidates[0].votes);
        printf("%s \n", winner1);
    }
    if (candidates[0].votes == candidates[1].votes)
    {
        winner1 = (candidates[0].name);
        winner2 = (candidates[1].name);
        printf("%s \n", winner1);
        printf("%s \n", winner2);
    } */

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
:( vote returns false when given name of invalid candidate
    vote function did not return false
:) vote produces correct counts when all votes are zero
:) vote produces correct counts after some have already voted
:( vote leaves vote counts unchanged when voting for invalid candidate
    vote function modified vote totals incorrectly
:( print_winner identifies Alice as winner of election
    print_winner function did not print winner of election
:( print_winner identifies Bob as winner of election
    print_winner function did not print winner of election
:( print_winner identifies Charlie as winner of election
    print_winner function did not print winner of election
:( print_winner prints multiple winners in case of tie
    print_winner function did not print both winners of election
:( print_winner prints all names when all candidates are tied
    print_winner function did not print all three winners of election
To see the results in your browser go to https://submit.cs50.io/check50/f382c70a190abdd139fd6ca57fd78ea4db457eb1

*/