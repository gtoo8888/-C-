#include <iostream> 
using namespace std;
#include "18-5-somedefs.h"


double dub(double x) {return 2.0 * x;}
double square(double x) {return x*x;}

int main(void){
	double y = 1.21;
	cout << use_f(y,dub) << endl;
	cout << use_f(y,square) << endl;
	cout << use_f(y,Fp(5.0)) << endl;
	cout << use_f(y,Fq(5.0)) << endl;
	cout << use_f(y,[](double u) {return u*u;}) << endl;
	cout << use_f(y,[](double u) {return u+u/2.0;}) << endl;
 	return 0;
}

