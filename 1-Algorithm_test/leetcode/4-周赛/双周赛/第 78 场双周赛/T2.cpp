#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;




class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
		int n = nums.size();
        vector<long long > pre(n+1);
		vector<long long > behen(n+1);
        for(int i = 0;i < n;i++) 
            pre[i+1] = pre[i] + nums[i];
		for(int i = n-1;i >= 0;i--) 
            behen[i] = behen[i+1] + nums[i];
		PrintVector(pre);
		PrintVector(behen);
		int ans = 0;
		for(int i = 0;i < n-1;i++){
			long long  qian = pre[i+1] - pre[0];
			long long  hou = behen[i+1] - behen[n];
			// for(int j = i+1;j < n;j++){
			// 	hou += nums[j];
			// }
			// printf("%d %d\n",qian,hou);
			if(qian >= hou)
				ans++;
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
	// vector<int> num = {2,3,1,0};
    vector<int> num = {10,4,-8,7};
	// vector<int> num = {10,4,-8,7,12,3,45,6,7,7,8};
	// vector<int> num = {0,0,0,0,0,0};

    auto ans = solution.waysToSplitArray(num);

	cout << ans << endl;
	return 0;
}




