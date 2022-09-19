#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printBool(bool val){
	if(val == true)		cout << "YES" << endl;
	else				cout << "NO" << endl;
	cout << endl;
}


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> un_set;
		for(size_t i = 0;i < nums.size();i++) {
			pair<unordered_set<int>::iterator,bool> ret = un_set.insert(nums[i]);
			cout << ret.second << endl;
			if(ret.second == false) 
				return true;
		}
		return false;
    }
};
		
int main() {
	Solution solution;
	vector<int> date = {1,1,1,3,3,4,3,2,4,2};
	bool ans;
	
	ans = solution.containsDuplicate(date);
	
	printBool(ans);
	
	return 0;
}



