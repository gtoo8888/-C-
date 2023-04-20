#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = 0;
        for(auto n : nums){
            if(n == target)
                ans++;
        }
        return ans++;
    }
};


	
int main() {
	Solution sol;
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;

	auto ans = sol.search(nums,target);
	cout << ans << endl;
	
	return 0;
}



