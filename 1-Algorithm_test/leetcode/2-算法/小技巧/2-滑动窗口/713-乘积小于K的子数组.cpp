#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int n = nums.size();
		int left = 0,right = 0;
		int plus = 1;
		int sum = 0;
		for(;right < n;right++){
			plus *= nums[right];
			while(left <= right && plus >= k){
				plus /= nums[left];	// ³ýµô×ó±ßµÄ
				left++;
			}
			sum += right - left + 1;
			printf("%d %d %d %d\n",sum,plus,left,right);
		}
		return sum;
    }
};


// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size(), ret = 0;
//         int prod = 1, i = 0;
//         for (int j = 0; j < n; j++) {
//             prod *= nums[j];
//             while (i <= j && prod >= k) {
//                 prod /= nums[i];
//                 i++;
//             }
//             ret += j - i + 1;
// 			printf("%d %d %d %d\n",ret,prod,i,j);
//         }
//         return ret;
//     }
// };



int main() {
	Solution solution;
	vector<int> nums = {10,5,2,6};
	int k = 100;
	
	auto ans = solution.numSubarrayProductLessThanK(nums,k);
	cout << ans << endl;
	
	return 0;
}



