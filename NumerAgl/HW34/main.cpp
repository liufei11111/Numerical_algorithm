#include "RandomEngin.h"
#include <iostream>
#include "IntegrateCube.h"
using namespace std;
int main(){
	vector<MJArray> x(3);
		RandomEngin(3,19182719899,10000,x);
		limites theLimites;
		theLimites.x[0]=0;
		theLimites.x[1]=2;
		theLimites.y[0]=-1;
		theLimites.y[1]=1;
		theLimites.z[0]=1;
		theLimites.z[1]=1.5;

		ShowVectorMJArray(x);
		double result=FunctionEval(x);
		cout<<"The integration of the function over the limites is : "<<result<<endl;






//	for (int i=0;i<100;i++)
//		cout<<"The ith set: "<<x[i].bullet[0]<<" :: "<<x[i].bullet[1]<<" :: "<<x[i].bullet[2]<<" :: "<<endl;	
	double z;
	cin>> z;
	return 0;
}