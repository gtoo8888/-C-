#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            if(i != nums[i])
                return i;
        }
        return nums.size();
    }
};


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n = nums.size() + 1;
//         for (int i = 0; i < n - 1; i++) {
//             if (nums[i] != i) {
//                 return i;
//             }
//         }
//         return n - 1;
//     }
// };




	
int main() {
	Solution sol;
	vector<int> nums = {0,1,3};

	auto ans = sol.missingNumber(nums);
	cout << ans << endl;
	
	return 0;
}



