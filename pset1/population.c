#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

/*
Background
Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
For example, if we were to start with n = 1200 llamas, 
then in the first year, 1200 / 3 = 400 new llamas would be born and 1200 / 4 = 300 llamas would pass away.
 At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.
To try another example, if we were to start with n = 1000 llamas, at the end of the year,
 we would have 1000 / 3 = 333.33 new llamas. We can’t have a decimal portion of a llama, though, 
 so we’ll truncate the decimal to get 333 new llamas born. 1000 / 4 = 250 llamas will pass away, 
 so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.
*/

    // TODO: Prompt for start size
    int start_size;
    do
    {
      start_size = get_int("Start size:\n");
    } while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size:\n");
    } while (end_size < start_size);


    // TODO: Calculate number of years until we reach threshold
    /*
    To calculate how many years it will take for the population to reach the end size, another loop might be helpful! Inside the loop,
     you’ll likely want to update the population size according to the formula in the Background, and update the number of years that have passed.
    */



/*
    int born_llamas;
    int pass_llamas;
    for (int i = 0; i < count; i++)
    {
        int n =n+(n/3)-(n/4);
        born_llamas = start_size / 3;
        pass_llamas = end_size / 4;
    } 
*/
    int population = start_size;
    int years = 0;
    do
    {
        population = population + (population / 3) - (population / 4);
        printf("population is : %i\n", population);
        years=years +1;

    } while (population != end_size);
    

    // TODO: Print number of years
    printf("Years:%i\n",years);
}