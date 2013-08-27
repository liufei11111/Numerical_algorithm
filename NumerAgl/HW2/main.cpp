#include "Allocate.h"
#include "Matrix.h"
#include "See_matrix.h"
#include "Shaw_Traub_Poly.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
using  namespace std;
int main(int argc, char** argv){
    if (argc>22){
        fprintf(stderr,"There are most arguments than expected. The only argument taken is the file name of the input file!");
        exit(-1);
    }
        FILE* file;
	char buff[1000];
        double coef[100];// no more than so many coefficients.
	int count=-1;
	double x=0;
        file= fopen(argv[1],"r+");
        int whichline=0;
        
        while(fgets(buff,1000,file)!=NULL){
             if(whichline==0){
                count=atoi(buff);
                whichline++;
             }
             else if (whichline==1){
                 char* pch;
                 int i=0;
                 pch=strtok(buff," ");
                 coef[i++]=atof(pch);
                 while (pch!=NULL){
                        pch=strtok(NULL," ");
                        if (pch!=NULL)
                            coef[i]=atof(pch);
                        i++;
                 }
                whichline++;
             }else{
                x=atof(buff);
             }
                 
             }      

        double *a=(double *)malloc(sizeof(double)*(count+1));
    for (int i=0;i<count+1;i++)
		a[i]=coef[i];
	
	Shaw_Traub_Poly b(a,count,x);
	free(a);
	cout<<"This is the evaluation: "<<b.Apply_STP()<<endl;
	b.Show();
 
	return 0;
}
