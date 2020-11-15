#include <cs50.h>
#include <stdio.h>
#include <string.h>

//#################################################################################################################################################################### 
/*
    First, notice the two-dimensional array preferences . 
    The integer preferences[i][j] will represent the number of voters who prefer candidate i over candidate j .
    The åle also deånes another two-dimensional array, called locked , which will represent the candidate graph. locked is a boolean array, so locked[i][j] being true
    epresents the existence of an edge pointing from candidate i to candidate j ; false means there is no edge. (If curious, this representation of a graph is known as an
    adjacency matrix”).

    Next up is a struct called pair , used to represent a pair of candidates: each pair includes the winner ’s candidate index and the loser ’s candidate index.
    
    The candidates themselves are stored in the array candidates , which is an array of string s representing the names of each of the candidates. There’s also an array of pairs ,
    which will represent all of the pairs of candidates (for which one is preferred over the other) in the election.
    
    The program also has two global variables: pair_count and candidate_count , representing the number of pairs and number of candidates in the arrays pairs and
    candidates , respectively.

    Now onto main . Notice that after determining the number of candidates, the program loops through the locked graph and initially sets all of the values to false , which mean
    our initial graph will have no edges in it.
    
    Next, the program loops over all of the voters and collects their preferences in an array called ranks (via a call to vote ), where ranks[i] is the index of the candidate who is
    he i th preference for the voter. These ranks are passed into the record_preference function, whose job it is to take those ranks and update the global preferences variable.
    Once all of the votes are in, the pairs of candidates are added to the pairs array via a called to add_pairs , sorted via a call to sort_pairs ,
     and locked into the graph via a call o lock_pairs . Finally, print_winner is called to print out the name of the election’s winner!
    Further down in the åle, you’ll see that the functions vote , record_preference , add_pairs , sort_pairs , lock_pairs , and print_winner are left blank. That’s up to you!
*/
//####################################################################################################################################################################

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    /*
         Complete the vote function.
        The function takes arguments rank , name , and ranks . 
        If name is a match for the name of a valid candidate, then you should update the ranks array to indicate that
        the voter has the candidate as their rank preference (where 0 is the årst preference, 1 is the second preference, etc.)
        
         Recall that ranks[i] here represents the user’s i th preference.
         The function should return true if the rank was successfully recorded,
         and false otherwise (if, for instance, name is not the name of one of the candidates).
         You may assume that no two candidates will have the same name
    */

    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[i]=candidates[i];
            return true;
        }
    } 

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    /*
         Complete the record_preferences function.
        The function is called once for each voter, and takes as argument the ranks array, 
        (recall that ranks[i] is the voter’s i th preference, where ranks[0] is the årst preference).
        
        The function should update the global preferences array to add the current voter’s preferences.
        Recall that preferences[i][j] should represent the number of voters who prefer candidate i over candidate j .
         You may assume that every voter will rank each of the candidates.
    */
    // TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
