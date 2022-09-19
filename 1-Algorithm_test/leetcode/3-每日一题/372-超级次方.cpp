#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}


class Solution {
public:
    int superPow(int a, vector<int>& b) {
		if(a == 1) 
			return 1;
    }
};


	
int main() {
	Solution solution;
	int a = 1;
	vector<int> b = {1,0};
	int ans;
	
	
	ans = solution.superPow(a,b);
	
	cout << ans << endl;
	
	return 0;
}



