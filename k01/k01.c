#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double square_ave);

int N;

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double ave=0;
    double var=0;
    double square_ave=0;
    double u;
    double val2=0;
    double ave_var=0;
    double square_ave_var;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    N=0;
   

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        N=N+1;

        ave_var=ave;
        
        ave=ave_online(val,ave);
        square_ave_var=square_ave;

        val2=val*val;

        square_ave=ave_online(val2,square_ave);

        var=var_online(val,ave_var,square_ave_var);

    }

    u=(N*var)/(N-1);

    printf("ave=%lf\n",ave);
    printf("var=%lf\n",var);
    printf("expected ave=%lf\n",ave);
    printf("expected var=%lf\n",u);


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

double ave_online(double val,double ave)
{
    double ave2;

    ave2=((N-1)*ave+1*val)/N;

    return ave2;

}

double var_online(double val,double ave,double square_ave)
{
    double var;

    var=(((N-1)*square_ave+val*val)/N)-(((N-1)*ave+val)/N)*(((N-1)*ave+val)/N);

    return var;

}