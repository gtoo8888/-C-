#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
//		printVector(nums);
		
		for(int i = 0;i < nums.size();i++) {
			if(nums[i] <= 0 && k > 0) {//k耗尽或者负数反转完了，都马上退出循环 
				nums[i] = -nums[i];
				k--;
			}
			else
				break;
		}
//		printVector(nums);
		cout << k << endl;
		
		if(k > 0) { 
			sort(nums.begin(),nums.end());//重新排序 
			if((k % 2) == 1)//如果是奇数 
				nums[0] = -nums[0];//就把最小的那个数反转一次 
			else {}//如果是偶数那就什么都不用做了 
		} 
//		printVector(nums);
		
		int sum = accumulate(nums.cbegin(),nums.cend(),0);//库里面的求和函数 
		return sum;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {-4,-2,-3};
	int k = 4;
	int ans;
	
	ans = solution.largestSumAfterKNegations(nums,k);
	
	cout << ans << endl;
	
	return 0;
}



