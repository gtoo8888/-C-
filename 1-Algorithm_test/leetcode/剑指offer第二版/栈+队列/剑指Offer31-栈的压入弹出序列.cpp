#include <algorithm> 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;// 使用一个栈模拟
        int n = pushed.size(); 
        int j = 0;
        for(int i = 0;i < n;i++){
            st.push(pushed[i]); // 入栈序列正常进入
            // 如果入栈序列，碰上出栈序列的第一个，可以弹出
            // 弹出以后还是相同的，说明就是一样的顺序进出
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                j++;
            }
            // PrintStack(st);
        }
        return st.empty();
    }
};

int main(){
	Solution sol;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};

	auto ans = sol.validateStackSequences(pushed,popped);
	
	PrintBool(ans);
	return 0;
}
