#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



//class Solution {
//public:
//	vector<int> temp;
//	vector<int> ans;
//	int max_nums = INT32_MIN;
//	void backtraining(vector<int> nums,int k,int sum,vector<bool> used) {
//		if(temp.size() == k ){
//			if(sum > max_nums)
//				ans = temp;
//			return; 
//		}
//		
//		for(int i = 0;i < nums.size();i++) {
//			if(used[i] == true) continue;
//			sum += nums[i];
//			temp.push_back(nums[i]);
//			used[i] = true;	
//			printVector(temp);
//			backtraining(nums,k,sum,used);
//			temp.pop_back();
//			sum -= nums[i];
//			used[i] = false;
//		}
//	}
//	
//    vector<int> maxSubsequence(vector<int>& nums, int k) {
//    	ans.clear();
//    	vector<bool> used(nums.size(),false);
//    	backtraining(nums,k,0,used);
//        return ans;
//    }
//};


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    	vector<int> temp1(nums);
        sort(temp1.begin(),temp1.end());
        int len = temp1.size();
        vector<int> temp2(temp1.begin() + len - k,temp1.end()) ;
        
        
        vector<int> ans(k,0);
        
        for(int i = 0;i < temp2.size();i++) {
        	
		}
        
        
        return temp2;
    }	
};


	
int main() {
	Solution solution;
	vector<int> nums = {-1,-2,3};
	int k = 3;
	vector<int> ans;
	
	ans = solution.maxSubsequence(nums,k);
	
	printVector(ans);
	
	return 0;
}



