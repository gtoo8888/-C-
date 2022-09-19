#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
	cout << endl; 
}


void Printstack(stack<int> q){
	while(!q.empty()){
		printf("%d ",q.top());
		q.pop();
	}
	cout << endl; 
}


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int n = pushed.size();
		// printVector(pushed);
		stack<int> st;
		int i = 0,j = 0;
		for(int i = 0;i < n; i++){
			st.emplace(pushed[i]);
			// Printstack(st);
			while(!st.empty() && st.top() == popped[j]){
				st.pop();
				j++;
			}
		}
		return st.empty();
    }
};



int main(void){
	Solution sol;
	vector<int> pushed = {1,2,3,4,5};
	vector<int> popped = {4,5,3,2,1};

	auto res = sol.validateStackSequences(pushed,popped);
	cout << res;
	return 0;
}
