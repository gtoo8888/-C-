#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

// 数组模拟一个哈希表
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         int a[n+1];
//         for(int i = 0;i <= n;i++){
//             a[i] = 0;
//         }
//         for(int i = 0;i < n;i++){
//             a[nums[i]]++;
//         }
//         vector<int> ans;
//         for(int i = 0;i <= n;i++){
//             if(a[i] > 1)
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i < n;i++){
            int t = nums[i];
            printf("%d t:%d nums[t-1]:%d\n",i,t,nums[t-1]);
            printVector(nums);
            if(t < 0 || t - 1 == i)
                continue;;
            if(nums[t-1] == t){
                ans.push_back(t);
                nums[i] *= -1;
            }else{
                int c = nums[t-1];
                nums[t-1] = t;
                nums[i--] = c;
            }
            printVector(nums);
            
        }
        return ans;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {4,3,2,7,8,2,3,1};
	
	auto ans = solution.findDuplicates(nums);
	
	printVector(ans);
	
	return 0;
}



