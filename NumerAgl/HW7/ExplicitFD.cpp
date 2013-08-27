#include "ExplicitFD.h"
double BC(double x,double t){
	return 0.0;
}
double IC(double x,double t){
	if (x>=0&&x<=.5)
		return x;
	else if (x>.5&&x<=1)
		return 1-x;
	else fprintf(stderr,"ERR: The x has a wrong range\n");
}

void Boundary(Matrix& Mat,double f(double x,double t),SpaceSpan Space,TimeSpan Time){
	int SpaceStep=Mat.tamy;
	int TimeStep=Mat.tamx;
	double spaceInterval=1.0*(Space.xEnd-Space.xStart)/(SpaceStep-1);
	double timeInterval=1.0*(Time.tEnd-Time.tStart)/(SpaceStep-1);
	for (int i=0;i<TimeStep;i++){
		Mat.theMatrix[i][0]=f(Space.xStart,timeInterval*i+Time.tStart);
		Mat.theMatrix[i][SpaceStep-1]=f(Space.xEnd,timeInterval*i+Time.tStart);
	}
}
void InitialC(Matrix& Mat,double f(double x,double t),SpaceSpan Space,TimeSpan Time,double rho){
	int SpaceStep=Mat.tamy;
	int TimeStep=Mat.tamx;
	double spaceInterval=1.0*(Space.xEnd-Space.xStart)/(SpaceStep-1);
	double timeInterval=1.0*(Time.tEnd-Time.tStart)/(SpaceStep-1);
	for (int i=1;i<SpaceStep-1;i++){
		Mat.theMatrix[TimeStep-1][i]=f(Space.xStart+spaceInterval*i,Time.tStart);
		Mat.theMatrix[TimeStep-2][i]=(rho/2)*
			(f(Space.xStart+spaceInterval*(i-1),timeInterval+Time.tStart)+
			f(Space.xStart+spaceInterval*(i+1),timeInterval+Time.tStart)
			)+(1-rho)*f(Space.xStart+spaceInterval*i,timeInterval+Time.tStart);
	}
}
void FDForward(Matrix& Mat,SpaceSpan Space,TimeSpan Time,double rho){
	int SpaceStep=Mat.tamy;
	int TimeStep=Mat.tamx;
	double spaceInterval=1.0*(Space.xEnd-Space.xStart)/(SpaceStep-1);
	double timeInterval=1.0*(Time.tEnd-Time.tStart)/(SpaceStep-1);
	for (int i=TimeStep-3;i>-1;i--)
		for (int j=1;j<SpaceStep-1;j++)
			Mat.theMatrix[i][j]=rho*(Mat.theMatrix[i+1][j-1]+Mat.theMatrix[i+1][j+1])+2*(1-rho)*
			Mat.theMatrix[i+1][j]-Mat.theMatrix[i+2][j];
}
void ExportEveryP(Matrix& Mat,int p){
	FILE* fpr=fopen("MatrixOutput.txt","w+");
	for (int i=0;i<Mat.tamx;i++){
		if (i%p==0){
		for (int j=0;j<Mat.tamy;j++)
			fprintf(fpr,"%f ",Mat.theMatrix[i][j]);
		fprintf(fpr,"\n");
		}
	}		
		fclose(fpr);
}