#include <iostream>
using namespace std;
#include <queue>
//queue���� 
//Queue��һ���Ƚ��ȳ�(First ln First Out,FIFO)�����ݽṹ��������������
//ֻ�ж�ͷ�Ͷ�β���������ʣ���˲������б�����Ϊ

//���캯��:
//queue<T> que ;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
//queue(const queue &que);//�������캯��
//��ֵ����:
//queue& operator=(const queue &que);//���صȺŲ�����
//���ݴ�ȡ:
//push(elem);//����β���Ԫ��
//pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
//back();//�������һ��Ԫ��
//front();//���ص�һ��Ԫ��
//��С����:
//empty();//�ж϶�ջ�Ƿ�Ϊ��
//size();//����ջ�Ĵ�С

class Person{
public:
	Person(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};

void test01(){
	queue<Person>q;
	
	Person p1("��ɮ",30);
	Person p2("�����",1000);
	Person p3("��˽�",800);
	Person p4("ɳɮ",900);
	
	q.push(p1);//��� 
	q.push(p2);
	q.push(p3);
	q.push(p4);
	
	cout << q.size() << endl;	
	while(!q.empty()){
		cout << q.front().m_name << q.front().m_age << endl;
		cout << q.back().m_name << q.back().m_age << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int main(){
    test01();
    cout << endl;
      
    return 0;
}



















