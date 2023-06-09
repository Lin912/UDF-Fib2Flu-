#include "udf.h"
#include "stdio.h"

DEFINE_SDOF_PROPERTIES(sdof2, prop, dt, time, dtime)
{
    double fx;
    double fy;
    double fz;

    int n = 0;
    FILE *fp;

    prop[SDOF_MASS] = 0.355;
    prop[SDOF_IXX] = 0.00044955;
    prop[SDOF_IYY] = 0.00044955;
    prop[SDOF_IZZ] = 0.00044955;
    prop[SDOF_IXY] = 0;
    prop[SDOF_IXZ] = 0;
    prop[SDOF_IYZ] = 0;

    for(;n == 0;)
    {
        fp = fopen("judge.txt","r");
        fscanf(fp,"%d",&n);
        fclose(fp);
    }


    for(;n == 2;)
    {
        fp = fopen("judge.txt","r");
        fscanf(fp,"%d",&n);
        fclose(fp);
    }

    fp = fopen("force.txt","r");
    fscanf(fp,"%lf %lf %lf",&fx, &fy, &fz);
    fclose(fp);

    prop[SDOF_LOAD_LOCAL] = FALSE;
    prop[SDOF_LOAD_F_X] = fx;
    prop[SDOF_LOAD_F_Y] = fy;
    prop[SDOF_LOAD_F_Z] = fz;

    printf("\ndof: update 6dof properties new");
    printf("\nNow Fx is %f", fx);
    printf("\nNow Fy is %f", fy);
    printf("\nNow Fz is %f", fz);

    Message("\ndof: update 6dof properties new");
    Message("\nNow Fx is %f", fx);
    Message("\nNow Fy is %f", fy);
    Message("\nNow Fz is %f", fz);


}