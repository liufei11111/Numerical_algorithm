#include "IntegrateCube.h"
/*void Scale_Cube(std::vector<MJArray>& vol,limites theLimits){
	double intervalX=theLimits.x[1]-theLimits.x[0];
	double intervalY=theLimits.y[1]-theLimits.y[0];
	double intervalZ=theLimits.z[1]-theLimits.z[0];
	MJArray tempx(vol[0].size());
	for (int i=0;i<vol[0].size();i++){
		tempx[i]=intervalX*vol[0][i]+theLimits.x[0];
	}
	MJArray tempy(vol[1].size());
	for (int i=0;i<vol[1].size();i++){
		tempy[i]=intervalY*vol[1][i]+theLimits.y[0];
	}
	MJArray tempz(vol[2].size());
	for (int i=0;i<vol[2].size();i++){
		tempz[i]=intervalZ*vol[2][i]+theLimits.z[0];
	}
	vol[0]=tempx;
	vol[1]=tempy;
	vol[2]=tempz;
}*/
void ShowVectorMJArray(std::vector<MJArray>& Array){
	/*for (int i=0;i<Array[0].size();i++){
		fprintf(stdout,"The %d th element in the array: %f %f %f \n",i,Array[0][i],Array[1][i],Array[2][i]);
	}*/
		FILE* fpr1;
	fpr1=fopen("Random.txt","w+");
	for (int i=0;i<Array[0].size();i++)
		fprintf(fpr1,"%f %f %f\n",Array[0][i],Array[1][i],Array[2][i]);
	fclose(fpr1);
}
double FunctionEval(std::vector<MJArray>& cube){
	double sum=0;
	for (int i=0;i<cube[0].size();i++)
		sum+=pow(cube[0][i]/2.0+1.0,2)*(2*cube[1][i]-1)+exp(-2.0*cube[2][i]);
	return sum=2*sum/cube[0].size();
}