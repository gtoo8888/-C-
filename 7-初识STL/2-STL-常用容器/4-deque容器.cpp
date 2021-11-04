#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
//deque����:˫�����飬���Զ�ͷ�˽��в���ɾ������
// deque��vector����:
// vector����ͷ���Ĳ��� ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
// deque��Զ���, ��ͷ���Ĳ���ɾ���ٶȻر�vector��
// vector����Ԫ��ʱ���ٶȻ��deque�죬��������ڲ�ʵ���й�

// deque�ڲ�����ԭ��:
// �ڲ���һ���п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
// �п���ά������ÿ���������ĵ�ַ,ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�
// deque�����ĵ�����Ҳ��֧��������ʵ�

// deque<T>deqT;//Ĭ�Ϲ�����ʽ
// deque(beg��end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
// deque(n, elem);//���캯����n��elem����������
// deque(const deque &deq);| //�������캯��

void printDeque(deque<int> &d){//Ϊ�˷�ֹ����������޸ģ���Ϊֻ����ʹ��
    for(deque<int>::const_iterator it = d.begin();it != d.end();it++)
        cout << *it << " ";//�����е����ݲ����Ա��޸���
    cout << endl;
}
//���캯�� 
void test01(){
    deque<int>d1;
    for(int i = 0;i < 10;i++)
        d1.push_back(i);
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,100);
    printDeque(d3);

    deque<int>d4(d3);
    printDeque(d4);
}

//deque��ֵ����
void test02(){
    deque<int>d1;
    for(int i = 0;i < 10;i++)
    	d1.push_back(i);
    printDeque(d1);
    
    deque<int>d2;
    d2 = d1;
    printDeque(d2);
    
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);
    
    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);  
}

//deque��С����
//deque.empty( );//�ж������Ƿ�Ϊ��
//deque.size();//����������Ԫ�صĸ���
//deque.resize(num ) ;//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á�//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//deque.resize(num��elem);//����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á�//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
void test03(){
    deque<int>d1;
    for(int i = 0;i < 10;i++)
    	d1.push_back(i);
    printDeque(d1);
	
	if(d1.empty())    
		cout << "YES" << endl;
	else{
		cout << "NO" << endl;
		cout << d1.size() << endl;
		// deque����û����������
	}
	d1.resize(15,1);
    printDeque(d1);	

	d1.resize(5);
    printDeque(d1);	
}

//deque�����ɾ��
//���˲������:
//push_back(elem);//������β�����һ������
//push_front(elem) ;//������ͷ������һ������
//pop_back();//ɾ���������һ������
//pop_front();//ɾ��������һ������
//ָ��λ�ò���:
//insert(pos ,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
//insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
//clear();//�����������������
//erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
//erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

//���˲���
void test04(){
    deque<int>d1;
    
    d1.push_back(10);//β�� 
    d1.push_back(20);
    
    d1.push_front(100);//ͷ�� 
    d1.push_front(200);
    printDeque(d1);	
    
    d1.pop_back();//βɾ 
	printDeque(d1);	 
	
	d1.pop_front();//ͷɾ 
	printDeque(d1);	
}
//ָ��λ�ò���
void test05(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);	

	d1.insert(d1.begin(),1000) ;//insert����
	printDeque(d1);	
	
	d1.insert(d1.begin(),2,10000);
	printDeque(d1);	
	
	deque<int>d2;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);	
    
    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);	
}
//ɾ������ 
void test06(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    
    deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);	

	d1.erase(d1.begin(),d1.end());//�����䷽ʽɾ��
//	d1.clear();
	printDeque(d1);	
}

//deque���ݴ�ȡ
//at(int idx);//��������idx��ָ������
//operator[];//��������idx��ָ������
//front();//���������е�һ������Ԫ��
//back();//�������������һ������Ԫ��
void test07(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    
    for(int i = 0;i < d1.size();i++)
    	cout << d1[i] << " ";
    cout << endl;

    for(int i = 0;i < d1.size();i++)
    	cout << d1.at(i) << " ";
    cout << endl;
    
    cout << d1.front() << endl;
    cout << d1.back() << endl;
}

//deque����
//sort(iterator beg, iterator end); //��beg��end������Ԫ�ؽ�������
void test08(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
	printDeque(d1);	
	
	//����Ĭ����������С��������
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ��������sort��������
	sort(d1.begin(),d1.end());
	printDeque(d1);   
}

int main(){
    test01();//���캯��
    cout << endl;
    
    test02();//deque��ֵ����
    cout << endl;
    
    test03();//deque��С����
    cout << endl;
    
    test04();//���˲��� 
    test05();//ָ��λ�ò��� 
    test06();//ɾ������ 
    cout << endl;
    
    test07();//deque���ݴ�ȡ
    cout << endl;
    
    test08();//deque����
    cout << endl;
    return 0;
}



















