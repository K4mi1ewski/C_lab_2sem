#include <stdio.h>
#include <stdlib.h>

void file_copy(FILE *f1,FILE *f2){
    int buff;
    buff = fgetc(f2);

    while(buff!= EOF) 
    {
        fputc(buff,f1);
        buff=fgetc(f2);
    }
}

int file_cmp(char* name1,char* name2){
    FILE *f1 = fopen(name1,"rb");
    FILE *f2 = fopen(name2,"rb");
    char a = fgetc(f1);
    char b = fgetc(f2);
    while((a != EOF) && (b!= EOF))
    {
        if(a != b) {
            
            fclose(f1);
            fclose(f2);
            return 1;
        }
    a=fgetc(f1);
    b=fgetc(f2);
    }
    if ( a==feof(f1)&& b==feof(f2));
       {
        fclose(f1);
        fclose(f2);
        return 0;
        }
       
        
        fclose(f1);
        fclose(f2);
        return 1;
}

int main()
{
    FILE* plik_out = fopen("t_1", "rb");
    FILE* plik_in = fopen("t1cpy", "wb");
    FILE* plik_out2 = fopen("b_1", "rb");
    FILE* plik_in2 = fopen("b1cpy", "wb");
    file_copy(plik_in,plik_out);
    file_copy(plik_in2,plik_out2);
    
    if(file_cmp("t_1","t1cpy") == 0) 
        printf("%s i %s zawieraja to samo\n","t_1","t1cpy");
   // printf("%d",file_cmp("t_1","t1cpy"));
    if(file_cmp("b_1","b1cpy") == 0) 
        printf("%s i %s zawieraja to samo\n","b_1","b1cpy");
    //printf("%d",file_cmp("b_1","b1cpy"));
    if(file_cmp("b_1","t1cpy")==0)
        printf("%s i %s sa takie same\n","b_1","t1cpy");
    if(file_cmp("t_1","b1cpy")==0)
        printf("%s i %s sa takie same\n","t_1","b1cpy");
    
    fclose(plik_in);
    fclose(plik_out);
    fclose(plik_in2);
    fclose(plik_out2);
}