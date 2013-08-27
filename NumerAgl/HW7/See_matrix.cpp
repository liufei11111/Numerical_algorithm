#include "See_matrix.h"
void see_matrix(double **x,int tamx,int tamy){
	for (int i=0;i<tamx;i++){
		for (int j=0;j<tamy;j++)
			printf("%f ",x[i][j]);
			printf("\n");
	}
	printf("\n");
}