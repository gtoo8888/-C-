#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#define null 0xffff


void test01(){
    // ����򵥵�lambda���ʽ
    auto basicLambda = [] { cout << "Hello, world!" << endl; };
    // ����
    basicLambda();   // �����Hello, world! 
}

void test02(){
    // ָ����������
    auto add = [](int a, int b) -> int { return a + b; };
    // �Զ��ƶϷ�������
    auto multiply = [](int a, int b) { return a * b; };

    int sum = add(2, 5);   // �����7
    int product = multiply(2, 5);  // �����10
    cout << sum << " " << product << endl; 
}

void test03(){
    int x = 10;
    // ǰ��ķ����ž����������岶׽ģʽ�Լ������������ֽ����Ϊlambda��׽��
    auto add_x = [x](int a) { return a + x; };  // ���Ʋ�׽x
    auto multiply_x = [&x](int a) { return a * x; };  // ���ò�׽x
    
    cout << add_x(10) << " " << multiply_x(10) << endl;  
}

void test04(){
    int x = 10;
    auto add_x = [x](int a) mutable { x *= 2; return a + x; };  // ���Ʋ�׽x
    // ����mutable���ԸĶ������ֵ
    cout << add_x(10) << endl; // ��� 30
    cout << x << endl;    
}

void test05(){
    auto a = [] { cout << "A" << endl; };
    auto b = [] { cout << "B" << endl; };

    // a = b;   // �Ƿ���lambda�޷���ֵ
    auto c = a;   // �Ϸ�������һ������

    cout << a << endl; 
    b;
    c;
}

// []��Ĭ�ϲ������κα�����
// [=]��Ĭ����ֵ�������б�����
// [&]��Ĭ�������ò������б�����
// [x]������ֵ����x����������������
// [&x]���������ò���x����������������
// [=, &x]��Ĭ����ֵ�������б���������x�����⣬ͨ�����ò���
// [&, x]��Ĭ�������ò������б���������x�����⣬ͨ��ֵ����
// [this]��ͨ�����ò���ǰ������ʵ�Ǹ���ָ�룩��
// [*this]��ͨ����ֵ��ʽ����ǰ����

// ������Ĳ���ʽ�У�ע����ò�Ҫʹ��[=]��[&]Ĭ�ϲ������б���

int main() {
    test01();
    test02();
    test03();
    test04();
    test05();

	return 0;
}



