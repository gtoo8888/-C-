#include <iostream>
using namespace std;
#include <stack>

//ջ�������б�����Ϊ����Ϊֻ��ջ��Ԫ�ز��ܱ������ʵ� 
//ջ�����ж������Ƿ�Ϊ��
//ջ���Է���Ԫ�ظ���

//stack���ýӿ�
//���캯��:
//stack<T> stk;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ
//stack( const stack &stk);//�������캯��
//��ֵ����:
//stack& operator=( const stack &stk);//���صȺŲ�����
//���ݴ�ȡ:
//push(elem);//��ջ�����Ԫ��
//pop();//��ջ���Ƴ���һ��Ԫ��
//top();//����ջ��Ԫ��
//��С����:
//empty( );//�ж϶�ջ�Ƿ�Ϊ��
//size();//����ջ�Ĵ�С


void test01(){
 	stack<int> s;
	 
	s.push(10);//��ջ 
	s.push(20);
	s.push(30);
	s.push(40);
	cout << s.size() << endl;//ջ�Ĵ�С 
	while(!s.empty()) {//ֻҪջ��Ϊ�գ��鿴ջ��������ִ�г�ջ����
		 cout << s.top() << endl;//�鿴ջ��Ԫ��
		 s.pop();//��ջ 
	}
	cout << s.size() << endl;//ջ�Ĵ�С 
}

 
int main(){
    test01();
    cout << endl;

    return 0;
}







