#include "Shaw_Traub_Poly.h"
void Shaw_Traub_Poly::Show(){
	for(int i=0;i<this->power+1;i++)
		cout<<"coef of a"<<i<<" order: "<<this->coef[i]<<endl;
	cout<<"dimension of the matrix is :"<< this->power+2<<endl;
	cout<<"The evaluated x is :"<< this->x<<endl;
	this->localM.Show();
}

double Shaw_Traub_Poly::Apply_STP(){
	double * xx=(double*) malloc(sizeof(double)*(this->power+1));
	double * y=(double*) malloc(sizeof(double)*(this->power+1));
	for(int i=0;i<this->power+1;i++){
		xx[i]=pow(this->x,i);
	}
	for (int i=0;i<this->power+1;i++){
		y[i]=xx[this->power-i];// to produce a power sequence of x and cite directly from below
	}
	for (int i=0;i<this->power+1;i++)
			this->localM.theMatrix[i][0]=this->coef[i+1]*y[i+1];
	for (int i=1;i<this->power+2;i++)
			this->localM.theMatrix[i-1][i]=this->coef[0]*y[0];
	for (int j=1;j<this->power+1;j++)
		for(int i=j;i<this->power+1;i++)
			this->localM.theMatrix[i][j]=this->localM.theMatrix[i-1][j-1]+this->localM.theMatrix[i-1][j];

	free(xx);
	free(y);
	return this->localM.theMatrix[this->power][1];
}