//pyramid.c
//the porbase is to remember how to use loop inside loop

#include <stdio.h>

int main(void)
{
    int pyramid = 50 ;
    int counter = pyramid;
//first draw spaces as the basewhight is

    for (int hight = 1; hight <=pyramid ; hight++)
    {
        //this will drwo the base one tiem , now i need it to go down with drwaing it les by one every time
        //by another loop

        //in every line drwo spaces as long as the pyrmid base
        for (int whight =0; whight <counter; whight++)
        {
            printf(" ");
        }
        //in every line draw block start from one encresing with every hight till the final 
        for (int block = 1; block <=hight; block++)
        {
            printf("#");
        }
        //print space in between the pyramid tow shapes
        printf("  ");

        //and becuse i didnt draw loop spaces before the shape it become strate line
        //the i loop in draw the pyramid second shape
        for (int block = 1; block <= hight; block++)
        {
            printf("#");
        }
        counter--;
        printf("\n");
    
    }


}