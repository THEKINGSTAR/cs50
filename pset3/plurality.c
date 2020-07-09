
#include <stdio.h>
#include <string.h>
#include <cs50.c>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);

//Bubble Sort Function
void bubbleSort(int arr[], int n);

//swap to find the largest votes at the begining
void swap(int *xp, int *yp);


//compare the largest intert name show the largest votes go to
void print_winner(void);

/****************************************************************/

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
    for (int i = 0; i < MAX; i++)
    {
        string compare = candidates[i].name;
        if (name == compare)
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
    int ii, jj, min_idx;

    // One by one move boundary of unsorted subarray
    for (ii = 0; ii < MAX - 1; ii++)
    {

        // Find the minimum element in unsorted array
        min_idx = ii;
        for (jj = ii + 1; jj < MAX; jj++)
            if (candidates[jj].votes < candidates[min_idx].votes)
                min_idx = jj;

        // Swap the found minimum element
        // with the first element
        swap(&candidates[min_idx].votes, &candidates[ii].votes);
    }

    for (int i = 1; i < MAX; ++i)
    {
        if (candidates[0].votes < candidates[i].votes)
        {
            candidates[0].votes = candidates[i].votes;
        }
    }
    printf("%s \n", candidates[0].name);
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
