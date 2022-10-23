#include <iostream>
#include <string>
#include <memory> // 包含智能指针
using namespace std;

// 会报错
void test1_error(void){
    auto_ptr<string> films[5] = {
        auto_ptr<string> (new string("fowl")),
        auto_ptr<string> (new string("duck")),
        auto_ptr<string> (new string("chicken")),
        auto_ptr<string> (new string("turkey")),
        auto_ptr<string> (new string("goose")),
    };
    auto_ptr<string> pwin;
    pwin = films[2];    // 所有权发生了转变，films[2]已经为空了

    for(int i = 0;i < 5;i++){
        cout << *films[i] << endl;
    }
    cout << *pwin << endl;
    cin.get();
}

void test2_ok(void){
    shared_ptr<string> films[5] = {
        shared_ptr<string> (new string("fowl")),
        shared_ptr<string> (new string("duck")),
        shared_ptr<string> (new string("chicken")),
        shared_ptr<string> (new string("turkey")),
        shared_ptr<string> (new string("goose")),
    };
    shared_ptr<string> pwin;
    pwin = films[2];

    for(int i = 0;i < 5;i++){
        cout << *films[i] << endl;
    }
    cout << *pwin << endl;
    cin.get();
}


int main() {
    // test1_error();
    test2_ok();
	return 0;
}



