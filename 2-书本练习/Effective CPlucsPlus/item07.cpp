#include <iostream>
using namespace std;
class Parent{
public:
    Parent(){
        cout << "Parent construct function" << endl;
    };
    ~Parent(){
        cout << "Parent destructor function" <<endl;
    }
};
class Son : public Parent{
public:
    Son(){
        cout << "Son construct function" << endl;
    };
    ~Son(){
        cout << "Son destructor function" <<endl;
    }
};
int main()
{
    Parent* p = new Son();
    delete p;
    // p = NULL;
    return 0;
}