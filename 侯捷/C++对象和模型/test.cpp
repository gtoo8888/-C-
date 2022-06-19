#include "string.h"
#include <iostream>

using namespace std;

class complex{
public:
    complex(double r = 0,double i = 0) : re(r) ,im(i){}
    // complex& operator += {const complex&};
    double real() const {return re;}
    double imag() const {return im;}
private:
    double re,im;
};

int main()
{
    complex c1;
    cout << c1.real() << endl;
    cout << c1.imag() << endl;

    complex c2(1,2);
    cout << c2.real() << endl;
    cout << c2.imag() << endl;

    const complex c3(3,4);
    cout << c3.real() << endl;   
}
