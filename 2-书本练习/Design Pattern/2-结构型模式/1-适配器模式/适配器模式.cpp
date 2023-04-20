#include <iostream>


// ������ģʽ��һ�ֽṹ�����ģʽ��������һ����Ľӿ�ת���ɿͻ�������������һ���ӿڡ�������ģʽ�Ĺؼ������������࣬���䵱�����������ݽӿ�֮���������


class Target {
public:
    virtual void request() = 0;
};

class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee specific request" << std::endl;
    }
};

class Adapter : public Target {
public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() override {
        adaptee->specificRequest();
    }

private:
    Adaptee* adaptee;
};




// �������ʾ���У����Ƕ�����һ�� Target ���һ�� Adaptee �ࡣ
// Target ���ǿͻ����������Ľӿڣ���������һ�� request() ���麯����
// Adaptee ������Ҫ��������࣬��������һ�� specificRequest() ������
// ���ǻ�������һ�� Adapter �࣬���̳��� Target �࣬������һ�� Adaptee �����ָ�룬���� request() ����ʵ���˽� Target �ӿ�ת���� Adaptee �ӿڵĹ��ܡ�


// �� main() �����У����Ǵ�����һ�� Adaptee �����һ�� Adapter ���󣬲��� Adaptee �����ָ�봫�ݸ� Adapter ����
// Ȼ�����ǵ��� Adapter ����� request() �������������Ƿ�ɹ��� Target �ӿ�ת������ Adaptee �ӿڡ�
// ������ģʽһ���������³����У�
// 1. ��һ���Ѿ����ڵ���Ľӿڲ����Ͽͻ��˵�����ʱ������ʹ��������ģʽ�����磬��һ�����������ṩ�Ľӿ���ͻ��˵Ľӿڲ�����ʱ����Ҫʹ��������ģʽ����ת����
// 2. ����Ҫ����һЩ�Ѿ����ڵ��࣬�������ǵĽӿ���ͻ����������Ľӿڲ�һ��ʱ������ʹ��������ģʽ�����磬��һ���ɵ� API ��Ҫ��һ���µ�ϵͳʹ��ʱ����Ҫʹ��������ģʽ����ת����
// ��֮��������ģʽ���԰�������ʵ�ֲ�ͬ�ӿ�֮���ת��������ߴ���ĸ����ԺͿ�ά���ԡ�

int main() {
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    adapter.request();

    return 0;
}

