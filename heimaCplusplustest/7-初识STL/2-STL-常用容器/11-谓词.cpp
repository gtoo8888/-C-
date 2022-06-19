#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//ν�ʸ���
//����bool���͵ķº�����Ϊν��
//���operator()����һ����������ô����һԪν��
//���operator()����������������ô������Ԫν��


//�º�������ֵ������bool�������ͣ���Ϊν��
//һԪν��
class GreaterFive{
public:
	bool operator()(int val){
		return val > 5;
	}
};

void test01(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);

	//���������� ��û�д���5������
	//GreaterFive()������������
	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
	if(it == v.end())
		cout << "NO" << endl;
	else
		cout << *it << endl;
}

//��Ԫν��
class MyCompare{
public:
	bool operator()(int val1,int val2){
		//bool����ν�ʣ������������ֶ�Ԫ 
		return val1 > val2;
	}
};

void test02(){
	vector<int>v;
	
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	
	sort(v.begin(),v.end());
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
	
	sort(v.begin(),v.end(),MyCompare());//�ṩһ���º������ı�������� 
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

int main(){
    test01();
    cout << endl;
 
    test02();
    cout << endl; 
    return 0;
}



















