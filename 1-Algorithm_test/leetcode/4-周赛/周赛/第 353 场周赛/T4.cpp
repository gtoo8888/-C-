#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 最大质因数
int gcd(int a,int b) { return b?gcd(b,a%b):a;}


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i = 0;i < n-1;i++){
            if(gcd(nums[i],nums[i+1]) == 1){
                index = i;
                break;
            }
        }
        if(index == -1)
            return -1;
        else 
            return n;
    }
};


int main() {
	Solution solution;
    vector<int> nums;
    nums = vector<int>{2,6,3,4};
	cout << solution.minOperations(nums) << endl;cout <<"-------------"<< endl;

    nums = vector<int>{6,10,5};
	cout << solution.minOperations(nums) << endl;cout <<"-------------"<< endl;

	return 0;
}




