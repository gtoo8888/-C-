#include <iostream>


// 适配器模式是一种结构型设计模式，它允许将一个类的接口转换成客户端所期望的另一个接口。适配器模式的关键在于适配器类，它充当了两个不兼容接口之间的桥梁。


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




// 在上面的示例中，我们定义了一个 Target 类和一个 Adaptee 类。
// Target 类是客户端所期望的接口，它定义了一个 request() 纯虚函数。
// Adaptee 类是需要被适配的类，它定义了一个 specificRequest() 函数。
// 我们还定义了一个 Adapter 类，它继承自 Target 类，并持有一个 Adaptee 对象的指针，它的 request() 函数实现了将 Target 接口转换成 Adaptee 接口的功能。


// 在 main() 函数中，我们创建了一个 Adaptee 对象和一个 Adapter 对象，并将 Adaptee 对象的指针传递给 Adapter 对象。
// 然后我们调用 Adapter 对象的 request() 函数来测试它是否成功将 Target 接口转换成了 Adaptee 接口。
// 适配器模式一般用在以下场景中：
// 1. 当一个已经存在的类的接口不符合客户端的需求时，可以使用适配器模式。例如，当一个第三方库提供的接口与客户端的接口不兼容时，需要使用适配器模式进行转换。
// 2. 当需要复用一些已经存在的类，但是它们的接口与客户端所期望的接口不一致时，可以使用适配器模式。例如，当一个旧的 API 需要被一个新的系统使用时，需要使用适配器模式进行转换。
// 总之，适配器模式可以帮助我们实现不同接口之间的转换，并提高代码的复用性和可维护性。

int main() {
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    adapter.request();

    return 0;
}

