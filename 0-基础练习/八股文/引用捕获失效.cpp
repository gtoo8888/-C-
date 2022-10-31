#include <iostream> 
#include <functional>
using namespace std;

using Func = std::function<void()>;

Func Getfunc(){
    int a = 1;
    return [&](){cout << a << endl;};
}

int main()
{
	std::function<void()> func = Getfunc();
    func();
    return 0;
}

