#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void printMap(unordered_map<int,int> &m){
	for(unordered_map<int,int>::iterator it = m.begin();it != m.end();it++)
		cout << (*it).first <<" " << it -> second << endl;
	cout << endl; 
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> map;//用哈希map存，第一个存数，第二个存下标 
		for(int i = 0;i < nums.size();i++){
			
			unordered_map<int,int>::iterator it = map.find(target - nums[i]);
			
			if(it != map.end()) {
			 //对比一下哈希map中有没有这个数字，如果没有的话（正常情况 ） it == map.end()
			 //如果有这个要找的数字，不正常情况 it != map.end(),就将它返回 
				vector<int> ans; //要返回的是vector 
				ans.push_back((*it).second);//将 
				ans.push_back(i);
				return ans;
			} 
        
			map.insert(pair<int,int>(nums.at(i),i));//每次选择后都将刚刚计算过的对组塞入哈希Map 
		}
		return {};
    }
};


int main() {
	Solution solution;
	int nums[] = {3,2,4};
	vector<int> test_num(nums,nums + sizeof(nums)/sizeof(int));
	vector<int> returnSize;
	int target = 6;
	
	returnSize = solution.twoSum(test_num,target);
		
	printVector(returnSize);

	return 0;
}

