#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"




class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> umap;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(umap.count(nums[i])){
                vector<int> tmp = umap[nums[i]];
                tmp.push_back(i);
                umap[nums[i]] = tmp;
            }else{
                vector<int> tmp;
                tmp.push_back(i);
                umap[nums[i]] = tmp;
            }
        }
        vector<long long> ans(n,-1);
        for(int i = 0;i < n;i++){
            vector<int> tmp = umap[nums[i]];
            if(tmp.size() == 1)
                ans[i] = 0;
            else{
                long long tmp_sum = 0;
                for(int j = 0;j < tmp.size();j++){
                    if(tmp[j] != i){
                        tmp_sum += abs(tmp[j] - i);
                    }
                }
                ans[i] = tmp_sum;
            }
        }
        return ans;
    }
};


int main() {
	Solution solution;

	// vector<int> nums = {1,3,1,1,2};
    vector<int> nums = {0,5,3};

    auto ans = solution.distance(nums);

	PrintVector(ans);
	return 0;
}




