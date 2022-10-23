#include <iostream> 
#include <cfloat> 
using namespace std;

double hmean(double a,double b,double* ans){
	if(a == -b) {
		*ans = DBL_MAX;
		return false;
	}else{
		*ans = 2.0*1*b/(a+b);
		return true;
	}
}

int main()
{
	double x,y,z;
	while(cin >> x >> y){
		if(hmean(x,y,&z))	// 出现错误后还可以继续
			cout << x << " " << y << " " << z << endl;
		else
			cout << "error" << endl;
	}
	return 0;
}

