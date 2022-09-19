#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    	int ans = numBottles;
    	int total = numBottles;
    	int change = numExchange;
		while(total >= numExchange) {
			cout << total << " " << change << " "  << endl;
			total -= change;
			++ans;
			++total;			
			
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	int numBottles = 15;
	int numExchange = 4;
	
	auto ans = solution.numWaterBottles(numBottles,numExchange);
	
	cout << ans << endl;
	
	return 0;
}



