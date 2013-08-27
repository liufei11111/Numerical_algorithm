#include "Matrix.h"


void Matrix::fill(double **x, int tam){
	for (int i=0;i<tam;i++)
		for (int j=0;j<tam;j++)
			theMatrix[i][j]=x[i][j];
}
Matrix& Matrix::operator=(Matrix a){
	this->refresh(a.tam);
	for (int i=0;i<a.tam;i++)
		for (int j=0;j<a.tam;j++)
			this->fill(a.theMatrix,tam);
	return *this;
}

Matrix& Matrix::operator+= (Matrix& b){
	if (this->tam!=b.tam){
		fprintf(stderr,"the dimension of the two matrix in + doesn't match!");
		exit(2);
	}
	else{
		
	for (int i=0;i<this->tam;i++)
		for (int j=0;j<this->tam;j++)
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
	if (this->tam!=b.tam){
		fprintf(stderr,"the dimension of the two matrix in + doesn't match!");
		exit(2);
	}
	else{
		
	for (int i=0;i<this->tam;i++)
		for (int j=0;j<this->tam;j++)
			this->theMatrix[i][j]=this->theMatrix[i][j]-b.theMatrix[i][j];
	return *this;
	}

}
Matrix operator- (Matrix& a,Matrix& b){
	Matrix temp(a);
	temp-=b;
	return temp;
}