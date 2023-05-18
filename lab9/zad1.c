#include <stdio.h>
#include <stdlib.h>

int suma (int *p, int len) { 
  int sum = 0;
  
  for (int i = 0; i < len; i++)
      sum += p[i];
  
  return sum;}
  void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}

int cmp1(const void*a, const void*b)
{
    return (*(const int*)a - *(const int *)b);
}
void proc1(int cols, int tab[][cols], int rows)
{
    for (int i = 0; i<rows;i++)
    {
        qsort(tab[i], cols, sizeof(int), cmp1);
    }
}
int columns;
int cmp2(const void*a, const void*b)
{
    int a_sum = suma((const int *)a, columns);
    int b_sum = suma((const int *)b, columns);
    return a_sum-b_sum;
}
void proc2(int cols, int tab[][cols], int rows)
{
    columns = cols;
    qsort(tab, rows, cols*sizeof(int), cmp2);

}
int main(void)
{
int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
print_tab_all(3,tab_B,4);
proc1(3,tab_B,4); printf("\n");
print_tab_all(3,tab_B,4); printf("\n");
print_tab_all(6,tab_A,3);
proc1(6,tab_A,3); printf("\n");
print_tab_all(6,tab_A,3);
printf("\n");

proc2(3,tab_B, 4);
print_tab_all(3,tab_B,4); printf("\n");
proc2(6,tab_A,3);
print_tab_all(6,tab_A,3); printf("\n");






    return 0;
}