#include "See_matrix.h"
void see_matrix(double **x,int tam){
	for (int i=0;i<tam;i++){
		for (int j=0;j<tam;j++)
			printf("%f ",x[i][j]);
			printf("\n");
	}
	printf("\n");
}