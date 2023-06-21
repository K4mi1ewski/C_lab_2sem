#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MIN 100
#define MAX 150



    
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
typedef struct elastyna{
    int length;
    int liczba[];
} elastyna;

int cmp(const void *a, const void *b){
    elastyna* a1 = *(elastyna **)a, *b1 =  *(elastyna **)b;
    if(a1 -> length != b1 -> length) 
        return (a1 -> length) - (b1 -> length);
    
    for(int i = 0; i < a1 -> length; i++){
        if(a1 -> liczba[i] != b1 -> liczba[i]) 
            return (a1 -> liczba[i]) - (b1 -> liczba[i]);    
    }
    
    return 0;
}


int main(){
    srand((unsigned int) time(NULL));
    int len;
    elastyna* tab[5];
    for(int i = 0; i < 5; i++){
        len = i_rand(MIN, MAX);
        tab[i] = malloc(sizeof(elastyna) + len*sizeof(int));
        tab[i] -> length = len;
        for(int j = 0; j < len; j++){
            if(j==0)
                tab[i] -> liczba[j] = rand()%9 + 1;
            else
                tab[i] -> liczba[j] = rand()%10;
        }
    }
    for(int i = 0; i < 5; i++){
        printf("\ntab[%d] ",i);
        for(int j = 0; j < tab[i] -> length; j++){
            printf("%d",tab[i] -> liczba[j]);
        }
    }
    
    qsort(tab, 5, sizeof(elastyna *), cmp);
    printf("\nPo posortowaniu:\n");
    for(int i = 0; i < 5; i++){
        printf("\ntab[%d] ",i);
        for(int j = 0; j < tab[i] -> length; j++){
            printf("%d",tab[i] -> liczba[j]);
        }
    }
    
    for(int i = 0; i < 5; i++){
        free(tab[i]);
    }
    return 0;
}