#include <iostream>
#include <string>
#include <memory> // 包含智能指针
using namespace std;

class Report{
private:
    string str;
public:
    Report(const string s) : str(s){
        cout << "Report create!" << endl;
    }
    ~Report(){
        cout << "~~~Report delete!" << endl;
    }
    void comment() const {
        cout << str << endl;
    }
};
	
int main() {
    shared_ptr<int> ps ;


    // auto_ptr<Report> ps1 (new Report("using auto_ptr"));    // 使用这个会报警告
    // ps1->comment();

    shared_ptr<Report> ps2(new Report("using share_ptr"));
    ps2->comment();
	
    unique_ptr<Report> ps3(new Report("using unique_ptr"));
    ps3->comment();
	return 0;
}



