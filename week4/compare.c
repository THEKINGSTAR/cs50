 #include <stdio.h>
 #include <cs50.h>

 int main (void)
 {


//work for numbers
    /*   
    int i = get_int("i :  ");
     int j = get_int("j :  ");

     if (i == j)
     {
         printf("Same\n");
     }
     else
     {
         printf("Not Same\n");
     }
      */



//not working for string there are in defrent address
     string s = get_string("s: ");
     string t = get_string("t: ");

        if (s == t)
        {
            printf("Same\n");
        }
        else
        {
            printf("Not Same\n");
        }
     printf("%p\n",s);
     printf("%p\n", t);
     char *n = get_string("n:");
     char *z = get_string("z:");
     if (n == z)
     {
         printf("Same\n");
        }
        else
        {
            printf("Not Same\n");
        }
        
        
  }