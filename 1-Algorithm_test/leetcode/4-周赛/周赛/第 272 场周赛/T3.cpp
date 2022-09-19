#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
	long long result = 0;
	bool isXiajiang(vector<int> temp) {
//		cout << temp.size() << endl;
		if(temp.empty())
			return false;
		if(temp.size() == 1)
			return false;
		for(int i = 1;i < temp.size();i++) {
			if(temp[i] != temp[i-1] - 1)
				return false;
		}
		return true;
	}
	
	
	void backtraing(vector<int> nums,int StartIndex) {
		if(isXiajiang(path)) {
//			ans.push_back(path);
			result++;
			PrintVector(path) ;
		}
		if(StartIndex >= nums.size()) {
			return;
		}
		
		for(int i = StartIndex;i < nums.size();i++) {
			path.push_back(nums[i]);
//			PrintVector(path) ;
			if(i >= 1 && nums[i] == nums[i-1]) {
				path.pop_back();
				continue;
			}
			backtraing(nums,i+1);
			path.pop_back();
		}
	}
	
    long long getDescentPeriods(vector<int>& prices) {
    	ans.clear();
//    	PrintBool(isXiajiang(prices));
    	
		backtraing(prices,0);
//		printVVector(ans);
		result += prices.size();
		return result;
    }
};


	
int main() {
	Solution solution;
	vector<int> prices = {8,6,7,7};
	
	auto ans = solution.getDescentPeriods(prices);
	
	cout << ans << endl;
	
	return 0;
}



