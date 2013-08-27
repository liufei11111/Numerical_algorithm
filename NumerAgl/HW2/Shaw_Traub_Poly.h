#ifndef __SHAW_TRAUB_POLY_H__
#define __SHAW_TRAUB_POLY_H__
#include "Matrix.h"
#include "stdlib.h"
#include <iostream>
using namespace std;
struct Shaw_Traub_Poly{

	/* NULL matrix*/
	Shaw_Traub_Poly(){
	Matrix localM(1);
	power=-1;
	coef=NULL;
	x=0;
	}
	/* empty matrix*/
	Shaw_Traub_Poly(int dim){
	Matrix localM(dim);
	power=dim;
	coef=NULL;
	x=0;
	}
	/*useful constructor*/
	Shaw_Traub_Poly(double* a, int pow,double input){
		localM=Matrix(pow+2);
		power=pow;
		double * local=(double*)malloc(sizeof(double)*(pow+1));
		for(int i=0;i<pow+1;i++){
			local[i]=a[i];

		}
		coef=local;
		local=NULL;
		x=input;
	}
	void Show();
	double Apply_STP();
	~Shaw_Traub_Poly(){
	if (coef==NULL){}
	else
	free(coef);
	}


	Matrix localM;
	int power;
	double * coef;
	double x;
};

#endif