#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;

void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
		int n = prices.size();
		vector<int> ans(n);
		for(int i = 0;i < n;i++){
			ans[i] = prices[i];
			int tmp_index = INT32_MAX;
			for(int j = i+1;j < n;j++){
				if(prices[j] <= prices[i]){
					tmp_index = j < tmp_index ? j : tmp_index;
				}
			}
			if(tmp_index != INT32_MAX)
				ans[i] -= prices[tmp_index];
			// printVector(ans);
		}
		return ans;
    }
};

	
int main() {
	Solution solution;	
	// vector<int> prices = {8,4,6,2,3};		// 4,2,4,2,3
	// vector<int> prices = {2,3,4,5,6,7};		
	vector<int> prices = {7,6,5,4,3,2};		
	
	auto ans = solution.finalPrices(prices);
	
	printVector(ans);
	
	return 0;
}



