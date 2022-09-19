#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
using namespace std;


void PrintPriQueue_less( priority_queue<int> q){
    while(!q.empty()){
        printf("%d ",q.top());
        q.pop();
    }
	cout << endl; 
}

void PrintPriQueue_greater( priority_queue<int,vector<int>,greater<int> > q){
    while(!q.empty()){
        printf("%d ",q.top());
        q.pop();
    }
	cout << endl; 
}

void PrintPriQSueue_less( priority_queue<string> q){
    while(!q.empty()){
        cout << q.top() << endl;
        q.pop();
    }
	cout << endl; 
}

void test01(){
    priority_queue<int,vector<int>,less<int> >q2;       //降序队列，大顶堆
    priority_queue<int,vector<int>,greater<int> > q1;   //升序队列，小顶堆

    priority_queue<int> q3; //对于基础类型 默认是大顶堆
    priority_queue<int, vector<int>, greater<int> > q4;  //这样就是小顶堆
    priority_queue<string> b;

}

void test02(){
    priority_queue<int> q1; 
    priority_queue<int, vector<int>, greater<int> > q2;
    priority_queue<string> q3;
    for (int i = 0; i < 5; i++) {
        q1.push(i);
        q2.push(i);
    }
    PrintPriQueue_less(q1);
    PrintPriQueue_greater(q2);
    q3.push("abc");
    q3.push("abcd");
    q3.push("abefsfc");
    PrintPriQSueue_less(q3);
}

int main() {
    test01();
    test02();
    // test03();
    // test04();
    // test05();

	return 0;
}



