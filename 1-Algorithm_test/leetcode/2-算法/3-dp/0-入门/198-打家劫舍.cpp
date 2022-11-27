#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        vector<int> dp(n+1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);   // ����ж���2����ʱ�򣬲����ܾ�ֻ͵��һ����ѡȡ���ֵ
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);   // dp[i-1]�����һ��͵���ǶԵģ��Ǿͱ���
            PrintVector(dp);
        }
        // return max(dp[n-1],dp[n-2]);
        return dp[n-1];
    }
};



int main() {
	Solution solution;
    // vector<int> nums = {1};      // ֻ��һ��
    // vector<int> nums = {1,2};
    // vector<int> nums = {2,1};
    // vector<int> nums = {2,14,3};

	vector<int> nums = {1,2,3,1};    // ����
    // vector<int> nums = {1,2,3,1,9,7};
    // vector<int> nums = {2,7,9,3,1};

    // vector<int> nums = {2,1,1,2}; // ����������
    // vector<int> nums = {1,3,1,3,100}; // �����Ҳ���2��

	
	auto ans = solution.rob(nums);
	cout << ans << endl;
	return 0;
}



