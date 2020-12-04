#include <stab.h>
#include <cs50.h>

int main(void)
{

    int gx[3][3] =
        {
            {-1, 0, 1},
            {-2, 0, 2},
            {-1, 0, 1}};
 
    for (int bi = 0; bi < 3; bi++)
    {
 
        for (int bj = 0; bj < 3; bj++)
        {
            printf("%i \n",gx[bi][bj]);
        }
    }
}