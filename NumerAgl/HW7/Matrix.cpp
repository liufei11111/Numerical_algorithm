#include "Matrix.h"


void Matrix::fill(double **x, int tamx,int tamy){
	for (int i=0;i<tamx;i++)
		for (int j=0;j<tamy;j++)
			theMatrix[i][j]=x[i][j];
}
Matrix& Matrix::operator=(Matrix a){
	this->refresh(a.tamx,a.tamy);
	this->fill(a.theMatrix,tamx,tamy);
	return *this;
}

Matrix& Matrix::operator+= (Matrix& b){
	if (this->tamx!=b.tamx||this->tamy!=b.tamy){
		fprintf(stderr,"the dimension of the two matrix in + doesn't match!");
		exit(2);
	}
	else{
		
	for (int i=0;i<this->tamx;i++)
		for (int j=0;j<this->tamy;j++)
			this->theMatrix[i][j]=this->theMatrix[i][j]+b.theMatrix[i][j];
	return *this;
	}

}
Matrix operator+ (Matrix& a,Matrix& b){
	Matrix temp(a);
	temp+=b;
	return temp;
}
Matrix& Matrix::operator-=(Matrix& b){
	if (this->tamx!=b.tamx||this->tamy!=b.tamy){
		fprintf(stderr,"the dimension of the two matrix in + doesn't match!");
		exit(2);
	}
	else{
		
	for (int i=0;i<this->tamx;i++)
		for (int j=0;j<this->tamy;j++)
			this->theMatrix[i][j]=this->theMatrix[i][j]-b.theMatrix[i][j];
	return *this;
	}

}
Matrix operator- (Matrix& a,Matrix& b){
	Matrix temp(a);
	temp-=b;
	return temp;
}