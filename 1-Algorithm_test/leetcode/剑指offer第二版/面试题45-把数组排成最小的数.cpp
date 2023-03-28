#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 不能用数字的方式比较，会比long long 还大
// bool compare(int v1,int v2){
// 	string tmp1 = to_string(v1) + to_string(v2);
// 	string tmp2 = to_string(v2) + to_string(v1);
// 	if(atoll(tmp1.c_str()) > atoll(tmp2.c_str())){
// 		return false;
// 	}else{
// 		return true;
// 	}
// }

// 330
// 303
// 330 > 303 字符串比较的结果直接可以是这个
bool compare(int v1,int v2){
	string s1 = to_string(v1);
	string s2 = to_string(v2);
	if((s1 + s2) > (s2 + s1)){	// 直接使用字符串的比较
		return false;
	}else{
		return true;
	}
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end(),compare);
		// PrintVector(nums);
		string ans = "";
		for(int i = 0;i < nums.size();i++){
			ans += to_string(nums[i]);
		}
		return ans;
    }
};





int main(){
	Solution sol;
	// vector<int> nums = {10,2};	
	// vector<int> nums = {3,30,34,5,9};
	// vector<int> nums = {999999998,999999997,999999999};
	vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


	auto ans = sol.minNumber(nums);
	cout << ans;
	return 0;
}
