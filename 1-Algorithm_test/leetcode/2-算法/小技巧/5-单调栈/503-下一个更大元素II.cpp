#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> temp(nums);
		stack<int> st;
		
		for(int i = 0;i < nums.size();i++)
			temp.push_back(nums[i]);
		vector<int> ans_tmp(temp.size(),-1);
		// PrintVector(temp);	
		for(int i = 0;i < temp.size();i++) {
			while(!st.empty() && temp[st.top()] < temp[i]){
				ans_tmp[st.top()] = i - st.top();
				st.pop();
			}
			st.push(i);
		}
		// PrintVector(ans);
		vector<int> ans(nums.size(),-1);
		for(int i = 0;i < nums.size();i++){
            if(ans_tmp[i] == -1)
                continue;
            ans[i] = temp[i+ans_tmp[i]];
        }
		// PrintVector(ans);	
		return ans;
    }
};
	
int main() {
	Solution solution;
    vector<int> nums = {1,2,1};
	
	auto ans = solution.nextGreaterElements(nums);
	
	PrintVector(ans);
	
	return 0;
}



