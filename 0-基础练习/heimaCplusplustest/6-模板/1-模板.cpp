#include <iostream> 
using namespace std;

// C++˼�룺������󣬷��ͱ��
// C++��߱�̣�C++���ͱ�̺�STL��������ϸ���⣬̽��C++������ʹ��
// ���ͱ�̾�����ģ�弼��
// ģ����ǽ���ͨ�õ�ģ�ߣ������߸�����
// ע�⣺
// ģ�岻��ֱ��ʹ�ã���ֻ��һ�����
// ģ���ͨ�õ��������ܵ�

// C++�ṩ����ģ�����:����ģ�����ģ��
// ����ģ������:���Ͳ�����
// ����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
template<typename T>//����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}
void test01(){
    int a = 10;
    int b = 20;
    //���ú���ģ�彻��
    //���ַ�ʽʹ�ú���ģ��
    //1���Զ������Ƶ�
    mySwap(a,b);
    //2����ʾָ������
    mySwap<int>(a,b);
    cout << a << endl;
    cout << b << endl;
}


//����ģ��ע������
//1���Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
template<class T>//typename�����滻��class,����ģ�壬��ģ��
void mySwap2(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}
void test02(){
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a,b);
    // mySwap(a,c);//�Ƶ�����һ�µ�T����

    cout << a << endl;
    cout << b << endl;
}
//2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func(){
    cout << "func�ĵ���" << endl;
}
void test03(){
    func<int>(); 
}

int main(){

    test01();

    test02();
    test03();
    return 0;
}
