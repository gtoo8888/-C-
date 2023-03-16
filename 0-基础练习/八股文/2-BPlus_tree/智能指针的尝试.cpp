#include <iostream>
#include <memory>

class MyResource {
public:
    MyResource() { std::cout << "MyResource constructor" << std::endl; }
    ~MyResource() { std::cout << "MyResource destructor" << std::endl; }
};

int main() {
    std::unique_ptr<MyResource> ptr1(new MyResource()); // 创建unique_ptr对象，传入资源指针
    std::unique_ptr<MyResource> ptr2 = std::move(ptr1); // 移动所有权到ptr2
    // std::unique_ptr<MyResource> ptr3 = ptr1; // 编译错误，unique_ptr不支持拷贝构造
    // std::unique_ptr<MyResource> ptr4 = ptr2; // 编译错误，unique_ptr不支持拷贝赋值操作

    // std::unique_ptr<MyResource> ptr3(new MyResource(), [](MyResource* ptr){ // 使用Lambda表达式作为删除器函数
    //     std::cout << "Custom deleter called" << std::endl;
    //     delete ptr;
    // });

    // std::unique_ptr<MyResource, void(*)(MyResource*)> ptr4(new MyResource(), [](MyResource* ptr){ // 使用函数指针作为删除器函数
    //     std::cout << "Custom deleter called" << std::endl;
    //     delete ptr;
    // });

    return 0; // unique_ptr会自动释放资源
}
