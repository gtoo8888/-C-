#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n < 4)
            return false;
    }
};

int main() {
	Solution solution;
    string num = "112358";
	
	auto ans = solution.isAdditiveNumber(num);
	
	cout << ans << endl;
	
	return 0;
}



