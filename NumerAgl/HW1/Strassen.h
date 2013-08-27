#pragma once
#include "Allocate.h"
#include "See_matrix.h"
#include "Matrix.h"
class Strassen
{
public:
	Strassen(){
	Matrix();
	tam=0;
	};
	Strassen(int tam1,int zero){
	double** x=allocate_real_matrix(tam1,zero);
	this->matrix.refresh(tam1);
	this->matrix.fill(x,tam1);
		
	this->tam=tam1;
	}

	Strassen(const Strassen&  a){
		this->matrix.refresh(a.tam);
		this->matrix=a.matrix;
		//fprintf(stderr,"test if the matrix is fine..\n");
		//this->matrix.Show();
		this->tam=a.tam;
    }
	Strassen  operator=(Strassen);

	void Show(){
		this->matrix.Show();
	}
	Strassen  operator+=( Strassen );
	Strassen  operator-=( Strassen );
	friend Strassen operator+( Strassen ,Strassen );
	friend Strassen operator-( Strassen ,Strassen );
	friend Strassen operator*( Strassen ,Strassen );// this is the Strassen multiplication
	friend Strassen operator % (Strassen , Strassen );// this is the classical multiplication
	//Strassen Multiply(Strassen& ,Strassen& );
	int IsPowerTwo();
	int Closest2Power(int);
	void Padding(Strassen&);
	void Div4Piece(Strassen& a,Strassen& b,Strassen& c,Strassen& d );
	void Collect4Piece(Strassen& a,Strassen& b,Strassen& c,Strassen& d );

private:
	Matrix matrix;
	int tam;
};

