#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> 
#include <set> 
using namespace std;


void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << endl;
	cout << endl;
}

void PrintSet(set<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << endl;
	cout << endl;
}

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
    	set<int> ans;//这是已经排序好了所以不用排序了 
    	int len = digits.size();
    	for(int i = 0;i < len;i++) {
    		if(digits[i] == 0)	continue;
    		
    		for(int j = 0;j < len;j++) {
    			if(j == i) continue;
    			if(digits[i] == 0 && digits[j] == 0)	continue;
    			
    			for(int k = 0;k < len;k++) {
    				if((k == i) || (k == j)) continue;
//    				cout << i << " " << j << " " << k << " " << endl;
//    				cout << "         " << digits[i] << " " << digits[k] << " " << digits[j] << " " << endl;
    		
    				int num = digits[i]*100 + digits[j]*10 + digits[k];
    				if(num%2 == 1)
    					continue;
    				ans.insert(num);
    			}
    		}
    	}
//    	PrintSet(ans);
		    	
    	vector<int> temp(ans.begin(),ans.end());
        return temp;
    }
};


	
int main() {
	Solution solution;
	vector<int> digits = {2,1,3,0};
	
	auto ans = solution.findEvenNumbers(digits);
	
	
	PrintVector(ans);
	
	return 0;
}



