#include "Strassen.h"

Strassen  Strassen::operator=(Strassen a){
	if (this->tam==a.tam){
		
	}else
		this->tam=a.tam;

	this->matrix=a.matrix;
		return *this;

}

Strassen  Strassen::operator +=(Strassen  a){
	this->matrix+=a.matrix;	
	return *this;
}
Strassen  Strassen::operator -=(Strassen  a){
	this->matrix-=a.matrix;	
	return *this;
}
Strassen operator +(Strassen  a,Strassen  b){
Strassen temp(a);
temp+=b;
return temp;
}
Strassen operator -(Strassen  a,Strassen  b){
Strassen temp(a);
temp-=b;
return temp;
}
int Strassen::IsPowerTwo(){
	int temp=this->tam;
	while(temp%2==0){
	temp=temp/2;
	}
	if (temp==1)
		return 1;
	else return -1;
}
int Strassen::Closest2Power(int a){
	if (a==0)
		return 0;
	if (a==1||a==2)
		return 1;
	if (a>2){
		int temp=1;
		int i;
		for (i=0;temp<=a;i++)
			temp=temp*2;
		return temp;
	}
	return -1;
}


Strassen operator *(Strassen  f, Strassen  e){
	Strassen a(f);
	Strassen b(e);
	int OldestDim=a.tam;// in case there are non 2 power dimensions
	if (a.tam!=b.tam)
	{
		fprintf(stderr,"a and b have dismatched dimensions!");
		exit(2);
	}else if (a.tam!=1){
		// same dimension but may not be right 2 power so adjust to get a
	f.Padding(a);
	f.Padding(b);
	}
	Strassen c(a.tam,0);
	if (a.tam==1){
		c.matrix.theMatrix[0][0]=a.matrix.theMatrix[0][0]*b.matrix.theMatrix[0][0];
	}else{
	int dim=a.tam/2;
	Strassen a11(dim,0), a12(dim,0), a21(dim,0), a22(dim,0);
	a.Div4Piece(a11,a12,a21,a22);
	Strassen b11(dim,0), b12(dim,0), b21(dim,0), b22(dim,0);
	b.Div4Piece(b11,b12,b21,b22);
	Strassen c11(dim,0), c12(dim,0), c21(dim,0), c22(dim,0);
	c.Div4Piece(c11,c12,c21,c22);
	Strassen M1(dim,0),M2(dim,0),M3(dim,0),M4(dim,0),M5(dim,0),M6(dim,0),M7(dim,0);
	M1=(a11+a22)*(b11+b22);
	M2=(a21+a22)*b11;
	M3=a11*(b12-b22);
	M4=a22*(b21-b11);
	M5=(a11+a12)*b22;
	M6=(a21-a11)*(b11+b12);
	M7=(a12-a22)*(b21+b22);
	c11=M1+M4-M5+M7;
	c12=M3+M5;
	c21=M2+M4;
	c22=M1-M2+M3+M6;
	c.Collect4Piece(c11,c12,c21,c22);
	}
	Strassen d(OldestDim,0);
	d.matrix.fill(c.matrix.theMatrix,OldestDim);
	return d;
}
Strassen operator %(Strassen e,Strassen  b){
	Strassen c(e.tam,0);
	Strassen a(e);
	for (int i=0;i<c.tam;i++)
		for(int j=0;j<c.tam;j++){
			for(int m=0;m<c.tam;m++)
				c.matrix.theMatrix[i][j]+=a.matrix.theMatrix[i][m]*b.matrix.theMatrix[m][j];
		}
		return c;
}


void Strassen::Padding(Strassen& x){

	if (x.IsPowerTwo()<0){
		Strassen temp(x.Closest2Power(x.tam),0);
		temp.matrix.fill(x.matrix.theMatrix,x.tam);
		x=temp;
		//x.Show();
	}
}
	
void Strassen::Collect4Piece(Strassen& a,Strassen& b,Strassen& c,Strassen& d ){
	int dim= this->tam/2;
	for (int i=0;i<dim;i++)
		for (int j=0;j<dim;j++){
			this->matrix.theMatrix[i][j]=a.matrix.theMatrix[i][j];
			this->matrix.theMatrix[i][j+dim]=b.matrix.theMatrix[i][j];
			this->matrix.theMatrix[i+dim][j]=c.matrix.theMatrix[i][j];
			this->matrix.theMatrix[i+dim][j+dim]=d.matrix.theMatrix[i][j];
		}
}
void Strassen::Div4Piece(Strassen& a,Strassen& b,Strassen& c,Strassen& d ){
	int dim= this->tam/2;
	for (int i=0;i<dim;i++)
		for (int j=0;j<dim;j++){
			a.matrix.theMatrix[i][j]=this->matrix.theMatrix[i][j];
			b.matrix.theMatrix[i][j]=this->matrix.theMatrix[i][j+dim];
			c.matrix.theMatrix[i][j]=this->matrix.theMatrix[i+dim][j];
			d.matrix.theMatrix[i][j]=this->matrix.theMatrix[i+dim][j+dim];
		}
}
