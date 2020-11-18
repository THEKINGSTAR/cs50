#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    /* 
    
    string s =get_string("S:");
  //char * s = get_string("S:");

    string t = s;
  //char * t = s;

    t[0] = toupper(t[0]);
    
    
    printf("%s\n", s);
    printf("%s\n", t); 
    
    */

/*     char *s = get_string("S:");
    char *t = malloc(strlen(s) + 1);

    for (int i = 0 , n= strlen(s) ; i < n+1 ; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);
 */

    char *s = get_string("S:");
    char *t = malloc(strlen(s) + 1);

    strcpy(t,s);

    t[0] = toupper(t[0]); 

    printf("%s\n", s);
    printf("%s\n", t);
    free(t);
}