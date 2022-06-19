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
    int trap(vector<int>& height) {
        PrintVector(height);
        stack<int> st;
        vector<int> ddz_W(height.size(),0);
        vector<int> ddz_H(height.size(),0);
        int ans = 0;
        for(int i = 0;i < height.size();i++) {
            while(!st.empty() && height[i] > height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty())
                    break;
                int left = st.top();
                int width = i - left - 1;
                
                int heigh = min(height[i],height[left]) - height[top];
                ddz_W[st.top()] =  i - left - 1;
                ddz_H[st.top()] =  min(height[i],height[left]) - height[top];
                ans += width * heigh;
            }
            st.push(i);
        }
    
        PrintVector(ddz_W);
        PrintVector(ddz_H);
        return ans;
    }
};
	
int main() {
	Solution solution;
    vector<int> height = {4,2,0,3,2,5};
	
	auto ans = solution.trap(height);
	
	cout << ans << endl;
	
	return 0;
}



