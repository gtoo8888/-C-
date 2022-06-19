#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // PrintVector(nums2);
        stack<int> st;
        vector<int> tmp(nums2.size(),-1);
        unordered_map<int,int> m;
        for(int i = 0;i < nums2.size();i++){
            m[nums2[i]] = -1;
        }
        for(int i = 0;i < nums2.size();i++){
            while(!st.empty() &&  nums2[i] > nums2[st.top()]){
                tmp[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
            
        }
        // PrintVector(tmp);
        for(int i = 0;i < nums2.size();i++){
            if(tmp[i] == -1)
                continue;
            tmp[i] = nums2[i+tmp[i]];
            m[nums2[i]] = tmp[i];
        }
        // PrintVector(tmp);
        // PrintMap(m);
        vector<int> ans(nums1.size(),-1);
        for(int i = 0;i < nums1.size();i++){
            ans[i] = m[nums1[i]];
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {6,5,4,3,2,1,7};
	
	auto ans = solution.nextGreaterElement(nums1,nums2);
	
	PrintVector(ans);
	
	return 0;
}



