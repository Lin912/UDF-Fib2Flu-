#include "udf.h"
#include "stdio.h"

DEFINE_EXECUTE_AT_END(write)
{
    static int n = 1;
    int i;

    char filename[] = "judge.txt";
    FILE *fp;
    i = 0;
    fp = fopen(filename,"w");
    fprintf(fp,"%d",n);
    fclose(fp);

    fp = fopen("judge.txt","w");
    fprintf(fp,"%d",i);
    fclose(fp);

    Message("\n n = %d, i = %d \n", n, i);


    
}