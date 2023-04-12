#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* funkcja (char* txt1, char* txt2)
{
    int len1 = strlen (txt1);
    int len2 = strlen (txt2);
    char *ptr1=txt1, *ptr2 = txt1;
    int len3 = len1+1;
    char* wynik = calloc (len3, sizeof(char));

    ptr1 = strstr (ptr2, txt2);
    strncat (wynik, ptr2, ptr1-ptr2);
    while (ptr1!=NULL)
    {
        ptr2 = ptr1+len2+1;
        ptr1 = strstr(ptr2, txt2);
        strncat (wynik, ptr2, ptr1-ptr2);
        len3 = len3 - len2;
        wynik = realloc (wynik, len3*sizeof(char));
    }


    return wynik;

}


int main (int argc, char*argv[])
{

char* t1 = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
char* t2 = "sie";
char*t3 = funkcja (t1, t2);
printf ("Napis 1: %s\nNapis 2: %s\nNapis 3: %s\n", t1, t2, t3);
free (t3);
t3 = NULL;
    return 0;
    
}