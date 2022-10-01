#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#define null 0xffff
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// class Solution {
// public:
//     vector<int> goodIndices(vector<int>& nums, int k) {
// 		int n = nums.size();
// 		vector<int> ans;
// 		for(int i = k;i < n-k;i++){
// 			int len = k-1;
// 			int l=i-1,r=i+1;
// 			bool flag = true;
// 			while(len--){
// 				// printf("l:%d %d\n",nums[l-1],nums[l]);
// 				if(!(nums[l-1] >= nums[l])){
// 					flag = false;
// 					break;
// 				}
// 				// printf("r:%d %d\n",nums[r],nums[r+1]);
// 				if(!(nums[r] <= nums[r+1])){
// 					flag = false;
// 					break;
// 				}
// 				l--;r++;
// 			}
// 			printf("\n");
// 			if(flag == true){
// 				ans.emplace_back(i);
// 			}
// 		}
// 		return ans;
//     }
// };


class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> ans;
		vector<int> dijian(n,0);
		vector<int> dizeng(n,0);
		for(int i = 0;i < n;i++){
			if(nums[i] >= nums[i+1])
				dijian[i] = 1;
			if(nums[i] <= nums[i+1])
				dizeng[i] = 1;
		}
		PrintVector(dijian);
		PrintVector(dizeng);
		for(int i = k;i < n-k;i++){
			int len = k-1;
			int l=i-1,r=i+1;
			bool flag = true;
			while(len--){

				printf("l:%d %d\n",nums[l-1],nums[l]);
				if(!(dijian[l] == 1)){
					flag = false;
					break;
				}
				printf("r:%d %d\n",nums[r],nums[r+1]);
				if(!(dizeng[r] == 1)){
					flag = false;
					break;
				}
				l--;r++;
			}
			printf("\n");
			if(flag == true){
				ans.emplace_back(i);
			}
		}
		return ans;
    }
};

int main()
{
	Solution solution;

	// vector<int> nums = {2,1,1,1,3,4,1};
	// int k = 2;

	// vector<int> nums = {2,1,1,2};
	// int k = 2;

	vector<int> nums = {243655,573257,92104,932396,605975,645879,104190,325692};
	int k = 3;

	auto ans = solution.goodIndices(nums,k);

	PrintVector(ans);

	return 0;
}
