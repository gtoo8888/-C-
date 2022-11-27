#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size();
        int n2 = n + 2;
        int now_sum = 0;
        for(int i = 0;i < n;i++){
            now_sum += nums[i];
        }
        int real_sum = (1+n2)*n2/2;
        int sub = real_sum - now_sum;   // 这个差是两个不在的数字的和
        int limit = sub/2;  // 两个不在的数字一定是一大一小的
        // printf("%d %d %d %d\n",real_sum,now_sum,sub,limit);
        int sum_tmp = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] <= limit)
                sum_tmp += nums[i];
        }
        int first = limit*(1+limit)/2 - sum_tmp;
        // printf("%d %d\n",first,sum_tmp);
        int second = sub - first;
        return {first,second};
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {2,3,4,5,6,7,8,9};
	
	auto ans = solution.missingTwo(nums);
	
	PrintVector(ans);
	
	return 0;
}



