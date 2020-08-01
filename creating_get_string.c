#include <stdio.h>

int get_text() ;
char *get_input();

int main(void)
{
/*     string name = get_string("","please enter your name \n");
    printf("%s \n",name); */
    get_input("Please enter your name : \n");
    get_text();


/* 
    

    scanf_s("%s", str, sizeof str);
    if (scanf_s("%s", str, sizeof str) != 1)
    {
        // inform user and retry etc. etc.
    } */
}



char *get_input(char * message )
{
    printf("%s",message);
    int lenght = sizeof(scanf("%s"));
    char str[lenght];
    scanf("%s", &str);
    printf("%s \n", str);
    return str;
}

int get_text()
{
    int lenght = sizeof(scanf("%s"));
    char name[lenght];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin); // read string
    printf("Name: ");
    puts(name); // display string

    return 0;
}