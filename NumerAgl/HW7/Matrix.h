#pragma once
#include "Allocate.h"
#include "See_matrix.h"
struct Matrix
{

	Matrix(){
		tamx=0;
		tamy=0;
	theMatrix=NULL;
	}
	Matrix(int tam){
		this->tamx=tam;
		this->tamy=tam;
		this->theMatrix=allocate_real_matrix(tam,tam,0);
	}
	Matrix(int tamx,int tamy){
		this->tamx=tamx;
		this->tamy=tamy;
		this->theMatrix=allocate_real_matrix(tamx,tamy,0);
	}
	//copier
	Matrix(const Matrix& a){
	this->tamx=a.tamx;
	this->tamy=a.tamy;
	this->theMatrix=allocate_real_matrix(tamx,tamy,0);
	for (int i=0;i<tamx;i++)
		for (int j=0;j<tamy;j++)
			this->theMatrix[i][j]=a.theMatrix[i][j];
	}
	void refresh(int a,int b){
	if (this->tamx>=1){
		free_real_matrix(theMatrix,tamx);
		this->theMatrix=allocate_real_matrix(a,b,0);
		this->tamx=a;
		this->tamy=b;
	}
	else {
		this->theMatrix=allocate_real_matrix(a,b,0);
		this->tamx=a;
		this->tamy=b;
	}
	}
	Matrix& operator=(Matrix a);

	Matrix& operator+=(Matrix& b);
	Matrix& operator-=(Matrix& b);
	friend Matrix operator+(Matrix& a,Matrix& b);
	friend Matrix operator-(Matrix& a,Matrix& b);
	void fill(double **x, int tamx,int tamy);
	void Show(){
		see_matrix(this->theMatrix,this->tamx,this->tamy);
	}
	~Matrix(void){
		free_real_matrix(theMatrix,tamx);
	}

	int tamx;
	int tamy;
	double ** theMatrix;
};

