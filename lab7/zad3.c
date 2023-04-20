#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int zero (double(*f)(double), double a, double b, double* m_z, double eps)
{
   //double x = 0;
    if (f(a)*f(b)<0){
    while (1)
    {
        double x;
        x = ((a+b)/2);
    
        if (f(a)*f(x) <= 0)
        {
            b = x;
        }
        else if (f(b)*f(x) <= 0)
        {
            a = x;
        }
        if (fabs(b-a)<2*eps)
            {   *m_z = x;
                return 1;
            }
    }
    
    }
    return 0;
}
double f1(double x)
{
    return -1*pow(x, 2) + 3 * x + 11;
}

int main (void)
{
double eps_ = 0.000000001;
double mz_sin=0;
double mz_f1=0;
double mz_f2=0;
int wynik_sin = zero(sin, -1, 1, &mz_sin, eps_);
int wynik_f1 = zero(f1, 0, 8, &mz_f1, eps_);
int wynik_f2 = zero(f1, -1, 1, &mz_f2, eps_);
printf("Dla sin(x): czy znaleziono : %d, miejsce zerowe: %lf\n", wynik_sin, mz_sin);
printf("Dla wielomianu w przedziale <0,8>, czy znaleziono : %d, miejsce zerowe: %lf\n", wynik_f1, mz_f1);
printf("Dla wielomianu w przedziale <-1,1>, czy znaleziono: %d, miejsce zerowe: %lf\n", wynik_f2, mz_f2);


return 0;
}