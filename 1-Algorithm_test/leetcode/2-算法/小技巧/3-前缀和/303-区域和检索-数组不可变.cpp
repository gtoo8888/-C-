#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// 之前不知道怎么操作vector
// class NumArray {
// public:
//     vector<int> pre;
//     NumArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> tmp(n+1);
//         for(int i = 0;i < n;i++)
//             tmp[i+1] = tmp[i] + nums[i];
//         pre = tmp;
//         // PrintVector(pre);
//     }
//     int sumRange(int left, int right) {
//         return pre[right+1] - pre[left];
//     }
// };


class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre.resize(n+1);
        for(int i = 0;i < n;i++)
            pre[i+1] = pre[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return pre[right+1] - pre[left];
    }
};


int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    int param_1 = obj->sumRange(0,2);
    cout << param_1 << endl;
    param_1 = obj->sumRange(2,5);
    cout << param_1 << endl;
    param_1 = obj->sumRange(0,5);
    cout << param_1 << endl;

	return 0;
}



