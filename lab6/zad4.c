#include <stdio.h>
#include <stdlib.h>

float* min(float tab[], int len)
{
    int minn = 0;
    for (int i = 1; i<len; i++)
    {
        if(tab[i]<tab[minn])
            minn=i;
    }
    return tab+minn;
}
float* max(float tab[], int len)
{
    int maxx = 0;
    for (int i = 1; i<len; i++)
    {
        if(tab[i]>tab[maxx])
            maxx=i;
    }
    return tab+maxx;
}
float* min_or_max(int len, float tab[], float*(*wskfun)(float t[], int l))
{
float* var_ptr = wskfun(tab, len);
return var_ptr;

}
int main(void)
{
float tab_A[]={-12.0, 41.5, 3.6, 1.23, 6.15, -32.1};
 float tab_B[]= {2.0, 4.0, 6.5, -2.1};
 unsigned A_len = sizeof(tab_A)/sizeof(*tab_A);
 unsigned B_len = sizeof(tab_B)/sizeof(*tab_B);

float* A_max = min_or_max(A_len, tab_A, max);
float* A_min = min_or_max(A_len, tab_A, min);
float* B_max = min_or_max(B_len, tab_B, max);
float* B_min = min_or_max(B_len, tab_B, min);
float A_diff = *A_max - *A_min;
float B_diff = *B_max - *B_min;
printf("Tab_A %f\nTab_B %f\n", A_diff, B_diff);
    return 0;
}