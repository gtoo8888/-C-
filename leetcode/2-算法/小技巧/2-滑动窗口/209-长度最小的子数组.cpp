#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


//class Solution {//暴力计算 
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//		int ans = INT_MAX;//先标记了最大值 
//		int sumarray;
//		int sublength = 0;
//		for(int i = 0;i < nums.size();i++){//每个数都拉一遍 
//			sumarray = 0;
//			for(int j = i;j < nums.size();j++){//从每个数开始拉，看看什么时候能超过target 
//				sumarray += nums[j];
////				cout << sumarray << endl;
//				if(sumarray >= target){//只要大于目标值，都可以进入判断 
//					sublength =  j - i + 1;
//					ans = sublength < ans ? sublength : ans;
//					break;//算完后直接截断了这个循环 
//				}	
//			}
//		}
//		return ans == INT_MAX ? 0 : ans;
//    }
//};

class Solution {//滑动窗口，只需要一个for 
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int ans = INT_MAX;//先标记了最大值 
		int sublenght;
		int i = 0;//左边界需要在外面定义，因为需要内部进行边界移动 
		int sum = 0;
		for(int j = 0;j < nums.size();j++){
			sum += nums[j];
			while(sum >= target){
				sublenght = j - i + 1;
				ans = sublenght < ans ? sublenght : ans;
				sum -= nums[i++];//相当于两个for循环中的break
				//通过让i++也就是左边界向右移动的方式
				//同时减掉这个值，达到了缩减边界长度的效果 
			}
		}
		return ans == INT_MAX ? 0 : ans;
    }
};
		
int main() {
	Solution solution;
	int nums_test[]  = {2,3,1,2,4,3};
	int target = 7;
	vector<int> nums(nums_test,nums_test + sizeof(nums_test) / sizeof(int));
	int ans;
	
	ans = solution.minSubArrayLen(target,nums);
	
	cout << ans <<endl;
	return 0;
}



