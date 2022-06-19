#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

//����:�����ݽ�����ʽ�洢
//����(list)��һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
//��������:������һϵ�н�����
//�������:һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
//STL�е�������һ��˫��ѭ������

//�����ŵ�:���Զ�����λ�ý��п��ٲ����ɾ��Ԫ��
//����ȱ��:���������ٶȣ�û�н���죬ռ�ÿռ�������
//��������Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������

//list���ŵ�:
//���ö�̬�洢���䣬��������ڴ��˷Ѻ����
//����ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��
//list��ȱ��:
//���������ǿռ�(ָ����)��ʱ��(����)����ķѽϴ�
//List��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ������ġ�
//�ܽ�:STL��List��vector���������ʹ�õ�������������ȱ��


//list���캯��
//��������:����list����
//����ԭ��:
//list<T> lst;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ:
//list(beg,end) ;//���캯����[beg, end)�����е�Ԫ�ؿ���������
//list(n,elem);//���캯����n��elem����������
//list(const list &lst);//�������캯����

void printList(list<int> &l){
	for(list<int>::iterator it = l.begin();it != l.end();it++)
		cout << *it << " ";
	cout << endl;
}

void test01(){
	//����list����
	list<int>L1;//Ĭ�Ϲ���
	
	L1.push_back(10);//β�巨 
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	
	printList(L1); 
	
	list<int>L2(L1.begin(),L1.end() );//���䷽ʽ����
	printList(L2);
		
	list<int>L3(L2);//��������
	printList(L3);
		
	list<int>L4(10,1000);//n��elem
	printList(L4);
}

//list��ֵ�ͽ���
//��������:
//��list�������и�ֵ���Լ�����list��������ԭ��:
//assign( beg, end );//��[beg, end)�����е����ݿ�����ֵ������
//assign(n,eiem);//��n��elem������ֵ������
//list& operator=(const list &lst);//���صȺŲ�����
//swap(lst);//��lst�뱾���Ԫ�ػ�����
//list��ֵ
void test02(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1); 
	
	list<int>L2;
	L2 = L1; //operator=��ֵ
	printList(L2);
	
	list<int>L3;
	L3.assign(L2.begin(),L2.end());
	printList(L3);
	
	list<int>L4;
	L4.assign(10,100);
	printList(L4);
}
//list����
void test03(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1); 
	
	list<int>L2;
	L2.assign(10,100);
	
	printList(L1); 
	printList(L2); 	
	
	L1.swap(L2);
	printList(L1); 
	printList(L2); 	
}

//list��С����
//��������:��list�����Ĵ�С���в���
//����ԭ��:
//size();//����������Ԫ�صĸ���
//empty();//�ж������Ƿ�Ϊ��
//resize( num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//resize(num��elem) ;//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
void test04(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1); 
	
	if(L1.empty())
		cout << "YES"  << endl;
	else{
		cout << "NO" << endl; 
		cout << L1.size() << endl;
	}
	
	L1.resize(10,10000);//����ָ����С
	printList(L1); 	
	
	L1.resize(2);
	printList(L1); 
}

//list�����ɾ��
//��������:��list�����������ݵĲ����ɾ��
//����ԭ��:
//push_back(elem);//������β������һ��Ԫ��
//pop_back();//ɾ�����������һ��Ԫ��
//push_front(elem);//��������ͷ����һ��Ԫ��
//pop_front();//��������ͷ�Ƴ���һ��Ԫ��
//
//insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
//insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
//clear();//�Ƴ���������������
//erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
void test05(){
	list<int>L1;
	L1.push_back(10);//β�� 
	L1.push_back(20);
	L1.push_back(30);
	
	L1.push_front(100);//ͷ�� 
	L1.push_front(200);
	L1.push_front(300);
	printList(L1); 
	
	L1.pop_back();//βɾ 
	printList(L1); 	
	
	L1.pop_front();//ͷɾ 
	printList(L1); 	
	
	L1.insert(L1.begin(),1000);//insert���� 
	list<int>::iterator it = L1.begin();
	L1.insert(++it,99);//�õ�������ƫ�� 
	printList(L1); 	
	
	it = L1.begin();
	L1.erase(++it);//ɾ�� 
	printList(L1); 	
	
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList(L1); 	
	L1.remove(10000);//�Ƴ� 
	printList(L1); 	
	
	L1.clear();//��� 
	printList(L1); 		 
}

//list���ݴ�ȡ
//��������:��list���������ݽ��д�ȡ
//����ԭ��:
//front();//���ص�һ��Ԫ�ء�
// back();//�������һ��Ԫ�ء�
void test06(){
	list<int>L1;
	L1.push_back(10);//β�� 
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//L1[0] ��������[]����list�����е�Ԫ��
	//L1.at(0) ��������at��ʽ����list�����е�Ԫ��
	//ԭ����list���������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�
	
	cout << L1.front() << endl;
	cout << L1.back() << endl;
	
	//��֤�������ǲ�֧��������ʵ�
	list<int> ::iterator it = L1.begin() ;
	it++;//֧��˫��
	it--;
	//it = it + 1;//��֧���������,����ܼ�1�����ܼ�2�ˣ��������������������ŷ��� 	 
}


//list��ת������
//��������:
//�������е�Ԫ�ط�ת���Լ��������е����ݽ�������
//����ԭ��:
//reverse();//��ת����
//sort();//��������
void test07(){
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout <<"��תǰ:" ;
	printList(L1);		
	
	L1.reverse();
	cout <<"��ת��:" ;
	printList(L1); 		
}
//list����
bool myCompare(int v1,int v2){
	return v1 > v2;//������õ�һ����>�ڶ�����
}
void test08(){
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout <<"����ǰ:" ;
	printList(L1);	
		
	//���в�֧��������ʵ��������������������ñ�׼�㷨
	//��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
//	sort(L1.begin(),L1.end());
	L1.sort();//Ĭ����������С��������
	cout <<"�����:" ;
	printList(L1); 	
	
	L1.sort(myCompare);
	printList(L1);	
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
    
    test06();
    cout << endl; 
    
    test07();
    test08();
    cout << endl; 
    return 0;
}



















