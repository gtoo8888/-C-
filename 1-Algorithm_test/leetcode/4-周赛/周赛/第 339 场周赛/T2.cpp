#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


bool mycompare(pair<int,int> p1,pair<int,int> p2){
	if(p1.second > p2.second)
		return true;
	// else if(p1.second < p2.second)
    else
		return false;
    return true;
}

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> umap;
		int n = nums.size();
		for(int i = 0;i < n;i++){
			umap[nums[i]]++;
		}
		// PrintUnorder_Map(umap);
		
		vector<pair<int,int>> vp;
		for(auto it : umap){
			vp.push_back(pair<int,int>(it.first,it.second));
		}

		sort(vp.begin(),vp.end(),mycompare);
        int max_hang = vp[0].second;
        int m = vp.size();
        vector<vector<int>> ans;
        for(int i = 0; i < max_hang; i++){
            vector<int> tmp;
            for(int j = 0;j < m;j++){
                if(vp[j].second == 0)
                    continue;
                tmp.push_back(vp[j].first);
                vp[j].second--;
            }
            ans.push_back(tmp);
        }
		return ans;
    }
};


int main() {
	Solution solution;

	vector<int> nums = {1,3,4,1,2,3,1};

    auto ans = solution.findMatrix(nums);

	PrintVVector(ans);
	return 0;
}




