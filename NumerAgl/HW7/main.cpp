#include "Matrix.h"
#include "ExplicitFD.h"
#include <iostream>
using namespace std;
int main(int argc,char** argv){
	double h=0.01;
	double k=0.01;
	double T=2.0;
	int p= 10;
	double Xspan=1.0;
	int spaceStep=(int)Xspan/h; 
	int timeStep=(int)T/k;
	double rho=(k*k)/(h*h);
	Matrix Mat(timeStep,spaceStep);
	TimeSpan Time;
	Time.tStart=0;
	Time.tEnd=T;
	SpaceSpan Space;
	Space.xStart=0;
	Space.xEnd=1;
	Boundary(Mat,BC,Space,Time);
	InitialC(Mat,IC,Space,Time,rho);
	FDForward(Mat,Space,Time,rho);
	ExportEveryP(Mat,p);
	
	double x;
	cin>>x;

return 0;
}
