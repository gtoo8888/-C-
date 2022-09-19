#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> 
#include <set> 
using namespace std;

class printVector{
public:
	void operator ()(int val){
		cout << val << " ";
	}
};

// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
// 		int hash_map[10005] = {0};
// 		for(int i = 0;i < nums.size();i++){
// 			hash_map[nums[i]]++;
// 			if(hash_map[nums[i]] > 1)
// 				return nums[i];
// 		}
// 		return -1;
//     }
// };


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
		set<int> s;
		for(int i = 0;i < nums.size();i++){
			if(s.find(nums[i]) != s.end())
				return nums[i];
			s.insert(nums[i]);
		}
		return -1;
    }
};


int main() {
	Solution sol;
	vector<int> nums = {1,2,3,3};

	auto ans = sol.repeatedNTimes(nums);
	cout << ans << endl;

	return 0;
}


