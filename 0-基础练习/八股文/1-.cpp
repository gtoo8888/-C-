#include<iostream> 
using namespace std;

inline double square(double x) {return x*x; }


class Person{
public:
    int a;
    // operator new[]
};
int main()
{
	
    int *p0 = new int;

    int *p1 = new int[2];
    p1[0] = 1;
    p1[1] = 2;
    printf("%d %d\n",p1[0],p1[1]);

    int *p2 = (int*)malloc(2*sizeof(int));
    p2[0] = 3;
    p2[1] = 4;
    printf("%d %d\n",p2[0],p2[1]);	


    Person *p3 = new Person;
    p3->a = 5;

    Person *p4 = new Person[2];


	return 0;
}

