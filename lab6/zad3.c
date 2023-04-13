#include <stdio.h>
#include <stdlib.h>

void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}

int(*multi_tab(int p, int q, int r, int a[][q], int b[][r]))[ ]
{
    //p - ilosc wierszy wyjsciowej macierzy, r - ilosc kolumn wyjsciowej macierzy
    int(*matrix)[r] = malloc(p*r*sizeof(int));
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j<r; j++)
        {
            int sum = 0;
            for(int k = 0; k< q; k++)
            {
                sum+= (a[i][k]*b[k][j]);
            }
            matrix[i][j]=sum;
        }
    }
    return matrix;
}
int main (void)
{

int tab_A[2][3] = {{1,2,3}, {4,5,6}};
int tab_B[3][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1,1,1,1}};
int(*result1)[4];
result1 = multi_tab(2, 3, 4, tab_A, tab_B);
printf("Result1:\n");
print_tab_all(4, result1, 2);

int tab_c[4][2] = {{1,2},{2,5},{1,0},{1,5}};
int tab_d[2][2] = {{1, -1}, {1,0}};

int(*result2)[2];
result2 = multi_tab(4,2,2,tab_c,tab_d);
printf("Result2:\n");
print_tab_all(2, result2, 4);
free(result1);
free(result2);
result1 = NULL;
result2 = NULL;
    return 0;
}