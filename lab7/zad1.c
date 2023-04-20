#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

srand(time(NULL));
//array_1
int rows = rand()%5 + 3;
int columns = rand()%5+3;
int ** array_1 = calloc(rows, sizeof(int*));
for (int i = 0; i < rows; i++)
{
    array_1[i] = calloc (columns, sizeof(int));
}
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j<columns;j++)
    {
        array_1[i][j] = rand()%15+1;
    }
}
printf("Array1:\n");
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j<columns;j++)
    {
        printf("%3d", array_1[i][j]);
    }
    printf("\n");
}
int rows_new = rand()%5+3;
if(rows_new > rows)
{
    array_1 = realloc(array_1, rows_new*sizeof(int*));
    for (int i = rows; i<rows_new;i++)
    {
        array_1[i] = calloc(columns, sizeof(int));
    }
    for (int i = rows; i<rows_new;i++)
    {
        for(int j = 0; j<columns;j++)
        {
            array_1[i][j] = rand()%15-15;
        }
    }
}
else if (rows_new < rows)
{
    for (int i = 0; i<rows-rows_new; i++)
    {
        free(array_1[rows-i-1]);
    }
    array_1=realloc(array_1, rows_new*sizeof(int*));
}
printf("Array1 po operacjach:\n");
for (int i = 0; i < rows_new; i++)
{
    for (int j = 0; j<columns;j++)
    {
        printf("%3d", array_1[i][j]);
    }
    printf("\n");
}
//zwolnienie pamieci:
for (int i = 0; i < rows_new; i++)
{
    free (array_1[i]);
}
free (array_1);
//Array2:
rows = rand()%5+3;
columns = rand()%5+3;
int ** array_2 = calloc (rows, sizeof(int*));
array_2[0] = calloc(columns*rows, sizeof(int));
for(int i = 1; i<rows;i++)
    array_2[i] = array_2[i-1]+columns;
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
        array_2[i][j] = rand()%15+1;
    }
}
printf("Array2:\n");
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
        printf("%3d", array_2[i][j]);
    }
    printf("\n");
}
rows_new = rand()%5+3;
if (rows_new > rows)
{
    array_2 = realloc(array_2, rows_new*sizeof(int*));
    array_2[0] = realloc(array_2[0], rows_new*columns*sizeof(int));
    for (int i = 1; i<rows_new;i++)
        array_2[i] = array_2[i-1]+columns;

     for(int i = rows; i < rows_new; i++)
     {
        for(int j = 0; j<columns;j++)
        {
            array_2[i][j] = rand()%15-15;
        }
     }
}
else if (rows_new < rows)
{
    array_2 = realloc(array_2, rows_new*sizeof(int*));
    array_2[0] = realloc(array_2[0], rows_new*columns*sizeof(int));
    for (int i = 1; i<rows_new;i++)
        array_2[i] = array_2[i-1]+columns;

}
printf("Array2 po operacjach:\n");
for (int i = 0; i < rows_new; i++)
{
    for (int j = 0; j < columns; j++)
    {
        printf("%3d", array_2[i][j]);
    }
    printf("\n");
}
free(array_2[0]);
free(array_2);

//array3:
rows = rand()%5+3;
columns = rand()%5+3;
int (*array_3)[columns] = calloc(rows*columns, sizeof(int));
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
        array_3[i][j] = rand()%15+1;
    }
}
printf("Array3:\n");
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
        printf("%3d", array_3[i][j]);
    }
    printf("\n");
}
rows_new = rand()%5+3;
if (rows_new > rows)
{
    array_3 = realloc (array_3, rows_new*columns*sizeof(int));
    for (int i = rows; i<rows_new; i++)
    {
        for (int j = 0; j<columns; j++)
        {
            array_3[i][j] = rand()%15-15;
        }
    }
}
else if (rows_new < rows)
{
    array_3 = realloc(array_3, rows_new*columns*sizeof(int));
}
printf("Array3 po operacjach:\n");
for (int i = 0; i < rows_new; i++)
{
    for (int j = 0; j < columns; j++)
    {
        printf("%3d", array_3[i][j]);
    }
    printf("\n");
}

free (array_3);


return 0;
}