#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class printVector{
public:
	void operator ()(int val){
		cout << val << " ";
	}
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int fast = 0,slow = 0;
		int n = nums.size();
		if(n == 0)
			return 0;
		while(fast < n) {
			if(nums.at(fast) != val){
				nums.at(slow) = nums.at(fast);
    			slow++;
			}
			fast++;
		}
		return slow;
    }
};


int main() {
	Solution sol;
	int nums[] = {1};
	vector<int> test_num(nums,nums + sizeof(nums)/sizeof(int));	
	int val = 1;
	int len = 0;
	for_each(test_num.begin(),test_num.end(),printVector());
	cout << endl;
	len = sol.removeElement(test_num,val);

	for_each(test_num.begin(),test_num.begin()+len,printVector());//返回vector中前几个元素 
	return 0;
}

