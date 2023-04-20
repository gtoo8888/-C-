#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// O(n)����
// class MinStack {
// public:
//     vector<int> v_que;
//     int min_ele;
// 	int len;
//     MinStack() {
//         min_ele = INT32_MAX;
// 		len = 0;
//     }
    
//     void push(int x) {
//         v_que.emplace_back(x);
//         min_ele = x < min_ele ? x : min_ele;
// 		len++;
//     }
    
//     void pop() {
//         v_que.erase(v_que.end()-1);
//         min_ele = INT32_MAX;
//         for(auto n : v_que){        // �����Ծ�ʹ��O(n)
//             min_ele = n < min_ele ? n : min_ele;
//         }
// 		len--;
//     }
    
//     int top() {
//         return v_que[len-1];
//     }
    
//     int min() {
//         return min_ele;
//     }
// };

// ����ջ
class MinStack {
public:
    stack<int> sta;
    stack<int> min_sta;
    MinStack() {
        min_sta.emplace(INT32_MAX); // �����ȳ�ʼ��Ϊ��Сֵ
    }
    
    void push(int x) {
        sta.emplace(x);
        min_sta.emplace(::min(min_sta.top(),x));
    }
    
    void pop() {
        sta.pop();
        min_sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int min() {
        return min_sta.top();
    }
};


	
int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->min() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->min() << endl;

	return 0;
}



