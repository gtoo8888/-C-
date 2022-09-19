#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int n = nums.size();
    	int ans[1000] = {0};
    	for(int i = 0;i < n;i++){
    		ans[nums[i]]++;
		}
		

    }
};
		
int main() {
	Solution solution;
	
	int nums_t[]  = {3,2,3}; 
	vector<int> nums(nums_t,nums_t + sizeof(nums_t) / sizeof(int));
	printVector(nums);
	
	int ans = 0;
	
	ans = solution.majorityElement(nums);
	
	cout << ans << endl;
	return 0;
}



