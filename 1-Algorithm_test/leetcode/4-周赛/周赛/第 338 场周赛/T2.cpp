#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int maxScore(vector<int>& nums) {
		long long n = nums.size();
        long long zhen_sum = 0;
		long long ans = 0;
		vector<long long> fu_v;
		
		for(long long i = 0;i < n;i++){
			if(nums[i] > 0){
				zhen_sum += nums[i];
				ans++;
			}else{
				fu_v.push_back(nums[i]);
			}
		}
		// printf("%d %d\n",ans,zhen_sum);
		sort(fu_v.begin(),fu_v.end(),greater<long long>());
		// PrintVector(fu_v);
		for(long long i = 0;i < fu_v.size();i++){
			zhen_sum += fu_v[i];
			if(zhen_sum > 0){
				ans++;
			}else
				break;
		}
		return ans;
    }
};


int main() {
	Solution solution;

	vector<int> nums = {2,-1,0,1,-3,3,-3};
	// vector<int> nums = {-2,-3,0};
	// vector<int> nums = {10};
	// vector<int> nums = {-10};
	// vector<int> nums = {0};

    auto ans = solution.maxScore(nums);

	cout << ans << endl;
	return 0;
}




