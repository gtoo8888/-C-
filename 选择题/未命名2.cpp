#include<iostream>
using namespace std;



class A{
private:
	int a;
public:
		A(){
			a = 0;
		}
		A(int n) {
			a = n;
		}
		A operator+(const A & obj) { //����+������ ������� 
			return this->a + obj.a;
		} 
		A operator+(const int b) { //����+������  �����������
			return A(a + b);
		}
//friend A operator+(const int b,A obj) ; //��Ԫ�������õڶ�������+�ĳ�Ա����  �൱�� obj.operator+(b); 

		void display(){
			cout << a << endl;
		}
};

//A operator+(const int b,A obj) {
//	return obj + b;
//}

int main ()
{
    A a1(1);
    A a2(2);
    A a3,a4,a5;
    
    a1.display();
    a2.display();
    
    int m = 4;
    
    a3 = a1 + a2;//���Խ���˳���൱��a3=a1.operator+(a2); 
//    a3 = a1.operator+(a2);
    a3.display();
    
    a4 = a1 + m;//��Ϊ���˸���Ԫ��������Ҳ���Խ���˳���ˡ�
    a4.display();
    
//    a5 = m + a1;
    a5.display();
}
