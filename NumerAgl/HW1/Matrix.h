#pragma once
#include "Allocate.h"
#include "See_matrix.h"
struct Matrix
{

	Matrix(){
		tam=0;
	theMatrix=NULL;
	}
	Matrix(int tam){
		this->tam=tam;
		this->theMatrix=allocate_real_matrix(tam,0);
	}
	//copier
	Matrix(const Matrix& a){
	this->tam=a.tam;
	this->theMatrix=allocate_real_matrix(tam,0);
	for (int i=0;i<tam;i++)
		for (int j=0;j<tam;j++)
			this->theMatrix[i][j]=a.theMatrix[i][j];
	}
	void refresh(int a){
	if (this->tam>=1){
		free_real_matrix(theMatrix,tam);
		this->theMatrix=allocate_real_matrix(a,0);
		this->tam=a;
	}
	else {
		this->theMatrix=allocate_real_matrix(a,0);
		this->tam=a;
	}
	}
	Matrix& operator=(Matrix a);

	Matrix& operator+=(Matrix& b);
	Matrix& operator-=(Matrix& b);
	friend Matrix operator+(Matrix& a,Matrix& b);
	friend Matrix operator-(Matrix& a,Matrix& b);
	void fill(double **x, int tam);
	void Show(){
		see_matrix(this->theMatrix,this->tam);
	}
	~Matrix(void){
		free_real_matrix(theMatrix,tam);
	}

	int tam;
	double ** theMatrix;
};

