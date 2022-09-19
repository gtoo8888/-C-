#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <array>
#include <list>
using namespace std;


void PrintList(list<int> l) {
	for(auto it : l)
		printf("%d ",it);
	cout << endl;	
}

void test01(){
    list<int> l0; //������
    list<int> l1(3); //��һ��������Ĭ��ֵ��0��Ԫ�ص�����
    list<int> l2(5,2); //��һ�������Ԫ�ص�����ֵ����2
    list<int> l3(l2); //��һ��c2��copy����
    list<int> l4(l2.begin(),l2.end()); ////c5��c1һ�������Ԫ��[_First, _Last)��

    list<int> l5{12,3,5,5,6,7,7,85,2};   
    PrintList(l5);
    list<int> l6;
    l5.merge(l2);
    PrintList(l5);
    l5.remove(3);
    l5.reverse();
    PrintList(l5);
    l5.sort();
    PrintList(l5);   
    l5.unique();
    PrintList(l5);   
    l5.splice(l5.begin(),l1);
    PrintList(l5); 
    l5.push_back(3193);
    l5.pop_back();
    l5.push_front(123);
    l5.pop_front();
    l5.erase(l5.begin());
    PrintList(l5); 
}



int main() {
    test01();
    // test02();
 

	return 0;
}



