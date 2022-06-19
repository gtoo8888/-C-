#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         PrintVector(temperatures);
//         stack<int> st;
//         vector<int> ans(temperatures.size(),0);
//         st.push(0);
//         for(int i = 0;i < temperatures.size();i++) {
//             if(temperatures[i] < temperatures[st.top()])
//                 st.push(i);
//             else if(temperatures[i] == temperatures[st.top()])
//                 st.push(i);
//             else{
//                 while(!st.empty() && temperatures[i] > temperatures[st.top()]){
//                     ans[st.top()] = i - st.top();
//                     st.pop();
//                 }
//                 st.push(i);
//             }
//             PrintVector(ans);
//         }

//         return ans;
//     }
// };

//向右走，找出第一个比自己大的元素
//遍历顺序为从右开始
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         PrintVector(temperatures);
//         stack<int> st;
//         vector<int> ans(temperatures.size(),0);
//         for(int i = temperatures.size()-1;i >= 0;i--){
//             //!st.empty() && 就是栈中有值才满足
//             //栈中有值 && st.top()栈顶元素=刚刚被压入栈的也就是右边一个元素，比当前元素小
//             //空的进不了循环
//             while(!st.empty() && st.top() <= temperatures[i])   //需要对不单调的情况进行弹出
//                 st.pop();
//             ans[i] = st.empty() ? -1 : st.top();
//             st.push(temperatures[i]);
//             // PrintVector(ans);
//         }
//         return ans;
//     }
// };

//向右走，找出第一个比自己大的元素的下标
//遍历顺序为从右开始
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         PrintVector(temperatures);
//         stack<int> st;
//         vector<int> ans(temperatures.size(),0);
//         for(int i = temperatures.size()-1;i >= 0;i--){
//             //!st.empty() && 就是栈中有值才满足
//             //栈中有值 && st.top()栈顶元素=刚刚被压入栈的也就是右边一个元素，比当前元素小
//             while(!st.empty() && temperatures[st.top()] <= temperatures[i]){   //需要对不单调的情况进行弹出
//                 st.pop();
//             }
//             ans[i] = st.empty() ? -1 : st.top() - i;
//             st.push(i);
//             // PrintVector(ans);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        PrintVector(temperatures);
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0;i < temperatures.size();i++) {//从左边开始的话，弹出的时候就需要记录数据了
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){   //需要对不单调的情况进行弹出
                //用while把积压的东西都处理掉
                ans[st.top()] = i - st.top();// 这个赋值过程，会出现先赋值了后面几个
                //找到了前面的比自己大的值，再赋值的情况
                st.pop();//已经找到了比当前大的，所以直接弹出了
            }
            st.push(i);//如果没找到比当前值大的，这个栈会一直累加比当前值小的
            // 同时这个栈从下自上一定是递减的
            PrintVector(ans);
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    vector<int> temperatures = {30,40,50,60};
	
	auto ans = solution.dailyTemperatures(temperatures);
	
	PrintVector(ans);
	
	return 0;
}



