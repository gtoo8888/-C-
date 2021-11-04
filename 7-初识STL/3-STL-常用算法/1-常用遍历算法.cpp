#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//�㷨��Ҫ����ͷ�ļ�<algorithm><functional> <numeric>��ɡ�
//<algorithm>������STLͷ�ļ�������һ������Χ�漰���Ƚϡ����������ҡ��������������ơ��޸ĵȵ�
//<numeric>�����С��ֻ��������������������м���ѧ�����ģ�庯��
//<functional>������һЩģ����,����������������

void print01(int val){//��ͨ���� 
	cout << val << " ";
}

class print02{//�º��� 
public:
	void operator() (int val){
		cout << val << " ";
	}
};
//���ñ����㷨for_each
void test01(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);
		
	for_each(v.begin(),v.end(),print01);//��ͨ�����ź����� 
	cout << endl;

	for_each(v.begin(),v.end(),print02());//�º����ź������� 
	cout << endl;
}

class Transform{
public:
	int operator() (int v){
		return v + 100;
	}
};
class myprint{
public:
	void operator() (int val){
		cout << val << " ";
	}
};
//���ñ����㷨transform
void test02(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);
		
	vector<int>vTarget;;//Ŀ������
	vTarget.resize(v.size());//Ŀ��������Ҫ��ǰ���ٿռ�
	
	transform(v.begin(),v.end(),vTarget.begin(),Transform());
	for_each(vTarget.begin(),vTarget.end(),myprint());
	cout << endl;
}







int main(){
    test01();
    cout << endl;
 
    test02();
    cout << endl;    
    return 0;
}



















