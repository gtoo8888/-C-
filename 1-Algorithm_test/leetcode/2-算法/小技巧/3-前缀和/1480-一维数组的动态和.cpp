#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// 暴力
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        for(int i = 0;i < n;i++) {
            int tmp_sum = 0;
            for(int j = 0;j <= i;j++) {
                tmp_sum += nums[j];
            }
            pre[i] = tmp_sum;
        }
        return pre;
    }
};

// 一维前缀和模板
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1;i < n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        return pre;
    }
};


int main() {
	Solution solution;
	vector<int> nums = {3,1,2,10,1};
	
	auto ans = solution.runningSum(nums);
	
	PrintVector(ans);
	
	return 0;
}



