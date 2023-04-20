#include <iostream>
#include <vector>


// 观察者模式一般用在以下场景中：
// 1. 当一个对象的改变需要同时改变其他对象时，可以使用观察者模式。例如，当一个主题对象的状态改变时，需要通知所有相关的观察者对象进行更新。
// 2. 当一个对象的改变需要引起另一个对象的改变时，可以使用观察者模式。例如，当一个订单对象的状态改变时，需要通知相关的库存对象进行更新。
// 3. 当一个对象需要将自己的改变通知给其他多个对象时，可以使用观察者模式。例如，当一个新闻发布者发布新闻时，需要通知所有订阅者进行更新。
// 4. 当一个对象的改变需要触发一系列的事件时，可以使用观察者模式。例如，当一个游戏对象的位置改变时，需要触发一系列的碰撞检测事件。
// 总之，观察者模式适用于多个对象之间存在一对多的依赖关系，当一个对象的状态改变时，需要通知所有相关的对象进行更新。它可以帮助我们实现对象之间的松耦合，并提高代码的复用性和可维护性。

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

// 在上面的示例中，我们定义了一个 Observer 类和一个 Subject 类。
// Observer 类是观察者的抽象基类，它定义了一个 update() 纯虚函数，子类需要实现该函数以响应主题对象的通知。Subject 类是主题对象，
// 它维护了一个观察者列表，并提供了 attach()、detach() 和 notifyAll() 函数来添加、删除和通知观察者。
// 我们还定义了一个 ConcreteObserver 类，它是 Observer 类的具体实现。在 main() 函数中，我们创建了三个 ConcreteObserver 对象，并将它们添加到 Subject 对象的观察者列表中。
// 然后我们调用 notifyAll() 函数来通知所有观察者，最后我们从 Subject 对象的观察者列表中删除了一个观察者，并再次调用 notifyAll() 函数来测试它是否生效。
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
