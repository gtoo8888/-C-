#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include<numeric>
using namespace std;
typedef list<int> iList;


void printlist(iList &list1)  {
	for(iList::iterator i=list1.begin();i!=list1.end();i++)
		cout<<(*i)<<" ";
	cout<<endl;	
}

class A
{
	int i;
public:
	A(int n=0):i(n) { }
	void f()const{cout<<i<<"_";}
	void f(){cout<<i<<"#";}
};

int mult(int x, int y)
{  
return x*y;
}



class D
{
  int a,b;
  public:
   D(int i=0,int j=0):a(i),b(j){}
   D(D&p){a=p.a;b=p.a;}
   void show(){cout<<a<<" "<<b<<endl;}
};

D f(D p)
{  
	D d1(p);
	p.show();
	return d1;
}



class CBase {
public:
	CBase() { foo(); }
	virtual void foo() {
	printf("Base\n");
	}
};

class CDerive : public CBase {
public:
	CDerive() {}
	virtual void foo() {
		printf("Derive\n");
	}
};



struct S1
{
int a;
static int b;
};
struct S2
{
int a;
bool b;
char c;
};

struct S3
{
float a;
int b;
char c;
};

struct S4
{
double a;
float b;
int c;
char d;
};


int main()
{
	if(0) {
		iList list1;  
		iList::iterator i;
		list1.push_back(2);
		list1.push_back(4);
		
		printlist(list1);
		
		list1.insert(++list1.begin(),3,9);
		printlist(list1);
		list1.pop_front();
		printlist(list1);
		list1.pop_back();
		printlist(list1);
		list1.erase(++list1.begin());
		printlist(list1);
		
		
		int a[3][3]={{3},{2},{1}};
		int b[3][3]={1,2,3};
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++)
				printf("%d ", b[i][j]);	
			cout << endl;
		}
		printf("%d %d\n", a[3][0],b[0][0]);
		
		
		A o1(5);
		const A o2;
		o1.f();
		o2.f();
		
		
		int a1[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
   		cout<<*(*(a1+2)+3)<<endl;
   		
   		
	   	deque<int>A2(5,3);
	 	cout<< accumulate(A2.begin(), A2.end(),1,mult)<< endl; //累加，最后一个普通函数 
   	
	   	// D o1,o2(2,3);

		// o2=f(o1);
		// o2.show();

		CDerive cd;

		cout << sizeof(S1) << endl;
		cout << sizeof(S2) << endl;
		cout << sizeof(S3) << endl;
		cout << sizeof(S4) << endl;
		
		int *p = NULL;
		printf("bool:		sizeof(%d)\n",sizeof(bool));
		printf("char:		sizeof(%d)\n",sizeof(char));
		printf("int:		sizeof(%d)\n",sizeof(int));
		printf("short:		sizeof(%d)\n",sizeof(short));
		printf("short int:	sizeof(%d)\n",sizeof(short int));
		printf("long:		sizeof(%d)\n",sizeof(long));
		printf("long int:	sizeof(%d)\n",sizeof(long int));
		printf("long long:	sizeof(%d)\n",sizeof(long long));
		printf("float:		sizeof(%d)\n",sizeof(float));
		printf("double:		sizeof(%d)\n",sizeof(double));
		printf("double:		sizeof(%d)\n",sizeof(p));

		// 1. 结构体的第一个成员永远放在结构体起始位置偏移量为0的地址处。
		// 2. 第二个成员开始，总是放在偏移量为对齐数整数倍的地址处。
		// 对齐数 == 编译器默认的对齐数 与 变量自身大小的较小值 (vs的默认值为8)
		// 3. 结构体的总大小必须是各成员的对齐数中最大对齐数的整数倍。

		string str1 = "\2018";
		printf("%s",str1);
		
		// int x;
		// int a1 = (x=4*5, x*5), x+25;
		// cout << a1 << endl;

		int a2[2][2][3] = {{{1, 2, 3}, {4, 5, 6}}, 
						{{7, 8, 9}, {10, 11, 12}}};
		int *ptr = (int *)(&a2 + 1);
		printf("%d\n", *(&a2 + 1));
		printf("%d %d", *(int*)(a2 + 1), *(ptr - 1));
	}

		int *p_int = NULL;
		double *p_double = NULL;
		printf("bool:		sizeof(%d)\n",sizeof(bool));
		printf("char:		sizeof(%d)\n",sizeof(char));
		printf("int:		sizeof(%d)\n",sizeof(int));
		printf("short:		sizeof(%d)\n",sizeof(short));
		printf("short int:	sizeof(%d)\n",sizeof(short int));
		printf("long:		sizeof(%d)\n",sizeof(long));
		printf("long int:	sizeof(%d)\n",sizeof(long int));
		printf("long long:	sizeof(%d)\n",sizeof(long long));
		printf("float:		sizeof(%d)\n",sizeof(float));
		printf("double:		sizeof(%d)\n",sizeof(double));
		printf("p_int:		sizeof(%d)\n",sizeof(p_int));
		printf("p_double:	sizeof(%d)\n",sizeof(p_double));


	

  	return 0;
}




