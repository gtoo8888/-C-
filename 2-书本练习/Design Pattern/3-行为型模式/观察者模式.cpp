#include <iostream>
#include <vector>


// �۲���ģʽһ���������³����У�
// 1. ��һ������ĸı���Ҫͬʱ�ı���������ʱ������ʹ�ù۲���ģʽ�����磬��һ����������״̬�ı�ʱ����Ҫ֪ͨ������صĹ۲��߶�����и��¡�
// 2. ��һ������ĸı���Ҫ������һ������ĸı�ʱ������ʹ�ù۲���ģʽ�����磬��һ�����������״̬�ı�ʱ����Ҫ֪ͨ��صĿ�������и��¡�
// 3. ��һ��������Ҫ���Լ��ĸı�֪ͨ�������������ʱ������ʹ�ù۲���ģʽ�����磬��һ�����ŷ����߷�������ʱ����Ҫ֪ͨ���ж����߽��и��¡�
// 4. ��һ������ĸı���Ҫ����һϵ�е��¼�ʱ������ʹ�ù۲���ģʽ�����磬��һ����Ϸ�����λ�øı�ʱ����Ҫ����һϵ�е���ײ����¼���
// ��֮���۲���ģʽ�����ڶ������֮�����һ�Զ��������ϵ����һ�������״̬�ı�ʱ����Ҫ֪ͨ������صĶ�����и��¡������԰�������ʵ�ֶ���֮�������ϣ�����ߴ���ĸ����ԺͿ�ά���ԡ�

class Observer {
public:
    virtual void update(int data) = 0;
};

class Subject {
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyAll(int data) {
        for (auto observer : observers) {
            observer->update(data);
        }
    }

private:
    std::vector<Observer*> observers;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(int data) override {
        std::cout << name << " received data: " << data << std::endl;
    }

private:
    std::string name;
};

// �������ʾ���У����Ƕ�����һ�� Observer ���һ�� Subject �ࡣ
// Observer ���ǹ۲��ߵĳ�����࣬��������һ�� update() ���麯����������Ҫʵ�ָú�������Ӧ��������֪ͨ��Subject �����������
// ��ά����һ���۲����б����ṩ�� attach()��detach() �� notifyAll() ��������ӡ�ɾ����֪ͨ�۲��ߡ�
// ���ǻ�������һ�� ConcreteObserver �࣬���� Observer ��ľ���ʵ�֡��� main() �����У����Ǵ��������� ConcreteObserver ���󣬲���������ӵ� Subject ����Ĺ۲����б��С�
// Ȼ�����ǵ��� notifyAll() ������֪ͨ���й۲��ߣ�������Ǵ� Subject ����Ĺ۲����б���ɾ����һ���۲��ߣ����ٴε��� notifyAll() �������������Ƿ���Ч��
int main() {
    Subject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");
    ConcreteObserver observer3("Observer 3");

    subject.attach(&observer1);
    subject.attach(&observer2);
    subject.attach(&observer3);

    subject.notifyAll(123);

    subject.detach(&observer2);

    subject.notifyAll(456);

    return 0;
}
