#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// class Solution {
// public:
//     int minimumAverageDifference(vector<int>& nums) {
// 		int n = nums.size();
//         vector<int> pre(n+1);
// 		for(int i = 0;i < n;i++)
// 			pre[i+1] = pre[i] + nums[i];
// 		// PrintVector(pre);
// 		vector<int> avg_sub(n);
// 		for(int i = 0;i < n;i++){
// 			int front = i + 1;
// 			int behind = n - i - 1;
// 			int tmp1 = (pre[i+1] - pre[0])/front;
// 			int tmp2;
// 			if(i == n-1)
// 				tmp2 = 0;
// 			else
// 				tmp2 = (pre[n] - pre[i+1])/behind;
// 			// printf("%d %d \n",pre[n],pre[i+1]);
// 			// printf("%d %d %d %d\n",front,behind,tmp1,tmp2);
// 			avg_sub[i] = abs(tmp1 - tmp2);
// 		}
// 		// PrintVector(avg_sub);
// 		int tmp_min = INT32_MAX;
// 		int ans = -1;
// 		for(int i = 0;i < n;i++) {
// 			if(avg_sub[i] < tmp_min){
// 				tmp_min = avg_sub[i];
// 				ans = i;
// 			}
// 		}
// 		// printf("%d\n",tmp_min);
// 		return ans;
//     }
// };


class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
		int n = nums.size();
        vector<long long> pre(n+1);
		for(int i = 0;i < n;i++)
			pre[i+1] = pre[i] + nums[i];
		long long tmp_min = INT64_MAX;
		int ans = -1;
		for(int i = 0;i < n;i++){
			long long tmp3;
			if(i == n-1)
				tmp3 = abs((pre[i+1] - pre[0])/(i + 1) - 0);
			else
				tmp3 = abs((pre[i+1] - pre[0])/(i + 1) - 
							(pre[n] - pre[i+1])/(n - i - 1) );
			if(tmp3 < tmp_min){
				tmp_min = tmp3;
				ans = i;
			}
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
    vector<int> nums = {2,5,3,9,5,3};

    auto ans = solution.minimumAverageDifference(nums);

	cout << ans << endl;
	return 0;
}




