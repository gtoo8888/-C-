#include <iostream>
using namespace std;
#include <list>
#include <map>

//map/multimap����
//���:
//map������Ԫ�ض���pair
//pair�е�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)��
//��Ч�� 
//����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
//����:
//map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�
//�ŵ�:
//���Ը���keyֵ�����ҵ�valueֵ
//map��multimap����:
//map���������������ظ�keyֵԪ��
//multimap�������������ظ�keyֵԪ��

void printMap(map<int,int> &m){
	for(map<int,int>::iterator it = m.begin();it != m.end();it++)
		cout << (*it).first <<" " << it -> second << endl;
	cout << endl; 
}
//map�Ĺ���͸�ֵ 
void test01(){
	map<int,int> m;
	
	m.insert(pair<int,int>(1,10));//���� 
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(4,40));//�����ʱ��ᰴ��key���� 
	
	printMap(m);
	
	map<int,int>m2(m) ;//�������� 
	printMap(m2);
	
	map<int,int>m3;//��ֵ 
	m3 = m2;
	printMap(m3); 
}

//map������С�ͽ���
//size();//����������Ԫ�ص���Ŀ
//empty();//�ж������Ƿ�Ϊ��
//swap(st);//����������������

//��С
void test02(){
	map<int,int> m;
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));	
	
	if(m.empty())
		cout << "YES" << endl;
	else{
		cout << "NO" << endl;
		cout << m.size() << endl;
	}
}
//����
void test03(){
	map<int,int> m1;
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));		

	map<int,int> m2;
	m2.insert(pair<int,int>(4,100));
	m2.insert(pair<int,int>(5,200));
	m2.insert(pair<int,int>(6,300));	
	
	cout << "after" << endl;
	printMap(m1); 	
	printMap(m2); 
	
	m1.swap(m2);
	cout << "before" << endl;
	printMap(m1); 	
	printMap(m2); 	
}


//map�����ɾ��
//insert( qlem);//�������в���Ԫ�ء�
//clear();//�������Ԫ��
//erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(beg, end);//ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(key ) ;//ɾ��������ֵΪkey��Ԫ�ء�
void test04(){
	map<int,int> m;
	//���� 
	m.insert(pair<int,int>(1,10));//��һ�� 
	m.insert(make_pair(2,20));//�ڶ���
	m.insert(map<int,int>::value_type(3,30));//������
	m[4] = 40;//������
	
	cout << m[4] << endl;//[]��������룬��; ��������key���ʵ�value
	cout << m[5] << endl;//�����ʹ�÷�������Ҫ��ӡ�����Ǵ�����һ��pair 
	printMap(m); 	
	//ɾ��
	m.erase(m.begin()) ;
	printMap(m); 

	m.erase(3) ;//����keyɾ��
	printMap(m); 
	
	m.erase(m.begin(),m.end());
//	m.clear();
	printMap(m); 		
}

//map���Һ�ͳ��
//find(key);//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�����;�������ڣ�����set.end();
//count(Fey);//ͳ��key��Ԫ�ظ���
void test05(){
	map<int,int> m;
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));	
	
	//���� 
	map<int,int>::iterator pos = m.find(3)	;	
	if(pos != m.end())
		cout << (*pos).first << " " << pos -> second << endl;
	else
		cout << "NO" << endl;
		
	//ͳ��
	//map����������ظ�keyԪ�أ�countͳ�ƶ��Խ��Ҫô��0Ҫô��1 
	//multimap��countͳ�ƿ��ܴ���1
	int num = m.count(3);
	cout << num << endl;	
}




int main(){
    test01();
    cout << endl;
  
    test02();
    test03();
    cout << endl;   
    
    test04();
    cout << endl;   
    
    test05();
    cout << endl;  
    return 0;
}



















