#include <cs50.h>
#include <stdio.h>
#include <math.h>


/**
 * Returns the difference of two longs read from stdin, or LONG_MAX if there was an error.
 */
long subtract_longs(void)
{
    // read long from stdin
    long i = get_long("Enter a long: ");

    // make sure we read one successfully
    if (i == LONG_MAX)
    {
        return LONG_MAX;
    }

    long j = get_long("What do you want to subtract from %ld? ", i);

    if (j == LONG_MAX)
    {
        return LONG_MAX;
    }

    return i - j;
}