#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size ;
    do
    {
        start_size=
         get_int("Start size::\n");
    } while (start_size < 9);

    // TODO: Prompt for end size
    int end_size = 0 ;
    do
    {
        end_size = get_int("End size:\n");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    /*
        Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
        For example, if we were to start with n = 1200 llamas, 
        then in the first year, 1200 / 3 = 400 new llamas would be born and 1200 / 4 = 300 llamas would pass away. 
        At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.
    */

    
    float years = 0;
    float population = start_size ;
    for (; population < end_size; population++)
    {
        population = roundf(population + (population / 3) - (population / 4));
        // printf("population :%i\n", population);
        years ++;
    }
    int ryears=roundf(years);
    // TODO: Print number of years
    printf("Years: %i\n", ryears);
}