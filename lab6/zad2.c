#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
    if (argc != 2)
    {
        printf("Niepoprawne wywolanie programu!\n");
        return 1;
    }
int size = strlen(argv[1]);
char* argument = malloc(size*sizeof(char));
argument = strcpy(argument, argv[1]);
int licznik = 0;

char rozdzielniki[]=", ;.:";
char* buff = strtok(argument, rozdzielniki);

char* max = strcpy(max, buff);
while(buff!=NULL)
{
    
    if(strcmp(max, buff) == 0)
    {
        licznik++;
    }
    else if (strcmp(max, buff) <0)
    {
        max = strcpy(max, buff);
        licznik=1;
    }
    buff = strtok(NULL, rozdzielniki);
}
printf("\nNajwieksze slowo: %s %d razy\n", max, licznik);
free (argument);
argument = NULL;
    return 0;
}