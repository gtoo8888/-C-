#include <iostream>
#include <vector>
#include <map>
using namespace std;


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



void printMap(map<int,int> &m){
	for(map<int,int>::iterator it = m.begin();it != m.end();it++)
		cout << (*it).first <<" " << it -> second << endl;
	cout << endl; 
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int size = nums.size();
		map<int,int> m;
		for(int i = 0;i < size;i++) {
			m[nums[i]]++;
		}
//		printMap(m);
		for(map<int,int>::iterator it = m.begin();it != m.end();it++) {
			if((*it).second == 1)
				return (*it).first;
		}	
		return 0;	
    }
};




	
int main() {
	Solution solution;
	vector<int> nums = {2,2,2,3,1,1,1,1,1};
	int ans;
	
	ans = solution.singleNumber(nums);
	
	cout << ans << endl;
	
	return 0;
}



