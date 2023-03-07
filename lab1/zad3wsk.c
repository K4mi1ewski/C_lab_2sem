#include <stdio.h>
#include <math.h>
#define N 10
float suma (float *t, int n, float*min, float*max, float*srednia, float*max_od, float* min_od);

int main (void)
{
float tablica [N] = {1.8, 2.6, 3.9, 14.12, 59.09, 0.75, 8.1, 2.44, 10.11, 19.5};
    float maksimum;
    float minimum;
    float sr;
    float maxodchylenie;
    float minodchylenie;
    printf ("Tablica: \n");
    for (int i = 0; i<N; i++)
    {
        printf ("tablica[%d] = %f\n", i, *(tablica+i));
    }
    float sum = suma (tablica, N, &minimum, &maksimum, &sr, &maxodchylenie, &minodchylenie);
    printf ("Maksimum: %f\n", maksimum);
    printf ("Minimum: %f\n", minimum);
    printf ("Srednia: %f\n", sr);
    printf ("Maksymalne odchylenie od sredniej: %f\n", maxodchylenie);
    printf ("Minimalne odchylenie od sredniej: %f\n", minodchylenie);
    return 0;
}

float suma (float *t, int n, float*min, float*max, float*srednia, float*max_od, float* min_od)
{
    float wynik=*t;
    *min = *t;
    *max = *t;
    for (int i = 1; i<n;i++)
    {
        wynik+=*(t+i);
        if (*(t+i) > *max)
            *max = *(t+i);
        else if (*(t+i) < *min)
            *min = *(t+i);
    }
    *srednia = (wynik/n);
    *max_od = fabs(*t - *srednia);
    *min_od = fabs(*t - *srednia);
    for (int i = 1; i<n;i++)
    {
        if (fabs(*(t+i)-*srednia) > *max_od)
            *max_od = fabs(*(t+i)-*srednia);
        else if (fabs(*(t+i)-*srednia) < *min_od)
            *min_od = fabs(*(t+i)-*srednia);
    }



    return wynik;

}