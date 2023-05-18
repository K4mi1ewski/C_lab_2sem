#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

void print_fun(double (*fun)(double param),const char* napis, double args[], int len)
{
    printf("Wynik: ");
    for(int i = 0; i<len;i++)
    {
        printf("%s(%.2lf) = %.4lf, ",napis,args[i],fun(args[i]));
    }
    printf("\n");
}

double (*(*find_max(double (*(*fun_tab))(double), double arg)))(double)
{
    double max = fun_tab[0](arg);
    double (*(*max_fun))(double) = fun_tab;
    fun_tab++;
    while(*fun_tab)
    {
        if (max < (*fun_tab)(arg))
            {
                max = (*fun_tab)(arg);
                max_fun = fun_tab;
            }
            fun_tab++;
    }
    return max_fun;//wskaznik do wskaznika do funkcji

}

double (*fun_ptr)(double);//zmienna globalna

int cmp_sortarg(const void* a, const void* b)
{
    double fun_a = fun_ptr(*(const double*)a);
    double fun_b = fun_ptr(*(const double*)b);
    return (fun_a>fun_b)-(fun_a<fun_b);
}

void sort_arg(double(*funkcja)(double),double tab[], int len)
{
    fun_ptr = funkcja;
    qsort(tab,len,sizeof(double),cmp_sortarg);
}
int main (void)
{

char* nazwy[]={"log", "pow","sin","cos"};
double data[8] = { 3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0 }; 

double (*TAB_FUN[5])(double);
TAB_FUN[0] = fun0; 
TAB_FUN[1] = fun1; 
TAB_FUN[2] = fun2; 
TAB_FUN[3] = fun3;
TAB_FUN[4] = NULL;
print_fun(fun0, "log",data,8);

//char (*str1)[4] = nazwy;
char **str = nazwy;
double (*(*wsk_fun))(double);
wsk_fun = TAB_FUN;

while(*wsk_fun)
{
    printf("\n");
    print_fun(*wsk_fun, *str, data, 8);
    wsk_fun++;
    str++;
}

double (*(*wsk_max))(double);
wsk_max = find_max(TAB_FUN, 0.05);
 
int index = wsk_max - TAB_FUN;
printf("index:%d\n",index);
printf ("dla x= %.3f najwieksza wartosc wynosi %.5f dla funkcji %s\n", 0.05, TAB_FUN[index](0.05), nazwy[index]);

sort_arg (TAB_FUN[2], data, 8);
printf("Posortowane wartosci tablicy data ze wzgledu na wartosci dla funkcji TAB_FUN[2]:\n");
for (int i = 0; i<8;i++)
    printf("%.2lf ", data[i]);
printf("\n");
printf("Wartosci funkcji TAB_FUN[2] dla kolejnych argumentow:\n");
for (int i = 0; i<8;i++)
    printf("%.2lf ", TAB_FUN[2](data[i]));
printf("\n");

}
