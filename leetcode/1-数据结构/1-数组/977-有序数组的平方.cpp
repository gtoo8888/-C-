#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

	
//class Solution {//暴力排序 
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//    	vector<int> ans; 
//		for(int i = 0;i < nums.size();i++)
//			ans.push_back(nums.at(i) * nums.at(i));
//		sort(ans.begin(),ans.end());
//		return ans;
//    }
//};

class Solution {//双指针 
public:
    vector<int> sortedSquares(vector<int>& nums) {
    	vector<int> ans(nums.size(),0); //先扩容好速度就快了 
    	int n = nums.size() - 1;
		int i = 0,j = nums.size()-1;
		while(i <= j) { 
			int last = nums[j]*nums[j];
			int start = nums[i]*nums[i];
			if(last > start){
				ans[n--] = last;
				j--;//插入一个，移动一位	
			}
			else{ 
				ans[n--] = start;
				i++;
			} 
		} 
		return ans;
    }
};


		
int main() {
	Solution solution;
	int nums_test[]  = {-4,-1,0,3,10};
	vector<int> nums(nums_test,nums_test + sizeof(nums_test) / sizeof(int));
	vector<int> ans;
	
	ans = solution.sortedSquares(nums);
	
	printVector(ans);
	return 0;
}



