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
    int removeDuplicates(vector<int>& nums) {
    	int fast,slow;//设置了快慢指针 
    	int n = nums.size();
    	if(n == 0)//如果传入的是[]什么都没有，不应该有返回 
    		return 0;
    	fast = 1;
    	slow = 1;
    	while(fast < n){//快指针走到头，遍历就结束了 
    		if(nums.at(fast) != nums.at(fast - 1)){
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
	int len = 0;
	for_each(test_num.begin(),test_num.end(),printVector());
	cout << endl;
	len = sol.removeDuplicates(test_num);

	for_each(test_num.begin(),test_num.begin()+len,printVector());//返回vector中前几个元素 
	return 0;
}

