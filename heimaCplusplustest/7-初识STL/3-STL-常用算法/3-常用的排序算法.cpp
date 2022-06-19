#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string> 
#include <ctime>

//���������㷨
//ѧϰĿ��:
//���ճ��õ������㷨
//�㷨���:
//sort//��������Ԫ�ؽ�������
//random_shuffle//ϴ��,ָ����Χ�ڵ�Ԫ�������������
//merge//����Ԫ�غϲ������洢����һ������
//reverse//��תָ����Χ��Ԫ��

//sort
//��������:��������Ԫ�ؽ�������
//����ԭ��:
//sort(iterator beg, iterator end��_Pred);
////��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//// beg��ʼ������
//// end����������
//// _Pred ν��
void myPrint(int val){
	cout << val << " ";
}

void test01(){
	vector<int>v;
	v.push_back(10);	
	v.push_back(30);	
	v.push_back(50);	
	v.push_back(20);	
	v.push_back(40);	
	
	sort(v.begin(),v.end());//����sort��������
	for_each(v.begin(),v.end(),myPrint);//ͨ���������д�ӡ 
	cout << endl;
	
	sort(v.begin(),v.end(),greater<int>());//�ı�Ϊ����
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
}

//random_shuffle
//��������:
//ϴ��ָ����Χ�ڵ�Ԫ�������������
//����ԭ��:
//random_shuffle( iterator beg, iterator end) ;
//// ָ����Χ�ڵ�Ԫ�������������
//// beg��ʼ������
//// end����������
void test02(){
	srand((unsigned int)time(NULL));//��ʱ����������,������ʵ����� 
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);	
	
	random_shuffle(v.begin(),v.end());//����ϴ���㷨����˳��
	for_each(v.begin(),v.end(),myPrint);
}

//merge
//��������:��������Ԫ�غϲ������洢����һ������
//����һ���Ժ�������� 
//����ԭ��:
//merge(iterator beg1��iterator end1�� iterator beg2��iterator end2��iterator dest);
//����Ԫ�غϲ������洢����һ������
////ע��:�������������������
//// beg1����1��ʼ������
//// end1����1����������
//// beg2����2��ʼ������
//// end2����2����������
//// destĿ��������ʼ������
void test03(){
	
	vector<int>v1;
	vector<int>v2;
	for(int i = 0;i < 10;i++){ 
		v1.push_back(i);	
		v2.push_back(i+1);
	} 
	vector<int>vTarget;	
	vTarget.resize(v1.size()+v2.size());//��ǰ��Ŀ����������ռ�

	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(),vTarget.end(),myPrint);
}


//reverse
//��������:��������Ԫ�ؽ��з�ת
//����ԭ��:
//reverse(iterator beg, iterator end);
////��תָ����Χ��Ԫ��
//// beg��ʼ������
//// end����������
void test04(){
	vector<int>v;
	v.push_back(10);	
	v.push_back(30);	
	v.push_back(50);	
	v.push_back(20);	
	v.push_back(40);
	
	cout << "��תǰ:" ;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	
	reverse(v.begin(),v.end());
	cout << "��ת��:" ;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
}




int main(){
    test01();
    cout << endl;
 
    test02();
    cout << endl;
    
    test03();
    cout << endl;
    
    test04();
    cout << endl;
    return 0;
}



















