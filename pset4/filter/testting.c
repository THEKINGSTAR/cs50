#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
 //   int rounded=ceil((110+140+130)/3);
 float rounded = round((110 + 140 + 130) / 3);

 int rounde_roud ; 
 rounde_roud= round(rounded);

 printf("%d\n", rounde_roud);
}