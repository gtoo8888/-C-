#include<iostream> 
using namespace std;

inline double square(double x) {return x*x; }

int main()
{
	
	double a,b;
	double c = 13.0;
	
	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << a << " " << b << "\n";
	cout << c << "\n";
	cout << square(c++) << "\n";
	cout << c << "\n";
	

	return 0;
}

