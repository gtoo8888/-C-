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

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtraining(int k,int n,int sum,int StartIndex) {
		if(sum > n)//剪枝 
			return;
		if(path.size() == k) {
//			int sum = accumulate(path.begin(),path.end(),0);	
			if(sum == n)
				ans.push_back(path);
			return;
		}
		for(int i = StartIndex;i <= 9;i++) {
			sum += i;
			if(sum > n)//里面可以再剪一次
				return;
			path.push_back(i);
			PrintVector(path);
			backtraining(k,n,sum,i+1);
			sum -= i;
			path.pop_back();
		}
	}
    vector<vector<int>> combinationSum3(int k, int n) {
		backtraining(k,n,0,1);
		return ans;
    }
};

	
int main() {
	Solution solution;
	int k = 3;//个数 
	int n = 7;//和 
	
	auto ans = solution.combinationSum3(k,n);
	
	printVVector(ans);
	
	return 0;
}



