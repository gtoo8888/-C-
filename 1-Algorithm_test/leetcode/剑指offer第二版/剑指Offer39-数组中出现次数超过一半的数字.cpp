#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		unordered_map<int,int> umap;
		int n = nums.size();
		for(int i = 0;i < n;i++){
			umap[nums[i]]++;
			if(umap[nums[i]] > n/2)
				return nums[i];
		}
		return -1;
    }
};


int main(){
	Solution sol;
	
	vector<int> data;
	data = vector<int>{1, 2, 3, 2, 2, 2, 5, 4, 2};
	cout << sol.majorityElement(data) << endl;
	data = vector<int>{2,2,2,4,4,4};
	cout << sol.majorityElement(data) << endl;
	data = vector<int>{2,2,1,1,1,2,2};
	cout << sol.majorityElement(data) << endl;
	
	return 0;
}
