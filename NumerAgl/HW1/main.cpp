
#include "Strassen.h"
#include <iostream>
using namespace std;
int main(){
	for (int z=2;z<=8;z=z*2){
cout<<"******************************************************************************/n";
cout<< " This is the result for "<<z<<" dimension: \n"<<endl;
		Strassen aa(z,1);
	aa.Show();
	Strassen c,f;
	c=(const Strassen&)(aa+aa);
	f=aa*c;
	f.Show();
	Strassen d;
	d=aa%(aa+aa);
	d.Show();

	Strassen e;
	e=f-d;
	e.Show();
	}

	

}