#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0,r = k;
        vector<int> ans(n-k+1,0);
        while(r <= n){
            vector<int> tmp(nums.begin()+l,nums.begin()+r);
            sort(tmp.begin(),tmp.end());
            if(tmp[x-1] < 0)
                ans[l] = tmp[x-1];
            else
                ans[l] = 0;
            l++;r++;
        }
        return ans;
    }
};

int main() {
	Solution solution;
    vector<int> nums;int k=0,x=2;
    nums = vector<int>{1,-1,-3,-2,3};k=3;x=2;
    PrintVector(solution.getSubarrayBeauty(nums,k,x));cout <<"-------------"<< endl;

    nums = vector<int>{-1,-2,-3,-4,-5};k=2;x=2;
    PrintVector(solution.getSubarrayBeauty(nums,k,x));cout <<"-------------"<< endl;

    nums = vector<int>{-3,1,2,-3,0,-3};k=2;x=1;
    PrintVector(solution.getSubarrayBeauty(nums,k,x));cout <<"-------------"<< endl;

    nums = vector<int>{-3};k=1;x=1;
    PrintVector(solution.getSubarrayBeauty(nums,k,x));cout <<"-------------"<< endl;


	return 0;
}




