#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
		// PrintVVector(nums);
		int n = nums.size();
		int m = nums[0].size();
		for(int i = 0;i < n;i++){
			vector<int>& tmp = nums[i];
			sort(tmp.begin(),tmp.end(),greater<int>());
		}
		// PrintVVector(nums);
		int ans = 0;
		for(int i = 0;i < m;i++){
			int tmp_max = nums[0][i];
			for(int j = 0;j < n;j++){
				
				if(nums[j][i] > tmp_max){
					tmp_max = nums[j][i];
				}
			}
			// printf("%d\n",tmp_max);
			ans += tmp_max;
		}
        return ans;
    }
};
		
int main() {
	Solution solution;
	
	vector<vector<int>> nums = {{2,7,1},{6,4,2},{6,5,3},{3,2,1}};
	
	auto ans = solution.matrixSum(nums);
	
	cout << ans << endl;
	return 0;
}



