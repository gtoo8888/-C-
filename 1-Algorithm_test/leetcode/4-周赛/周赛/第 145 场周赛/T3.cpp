#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 1500 real 1908
class Solution {
public:
    int longestWPI(vector<int>& hours) {
		int n = hours.size();
		vector<int> tired(n,-1);
		int tn = 0;
		for(int i = 0;i < n;i++){
			if(hours[i] > 8)
				tired[i] = 1,tn++;
			else
				tired[i] = 0;
		}
		if(tn == 0)
			return 0;
		// PrintVector(tired);
		int l=0,r=0;
		int tired_day=0,no_tired_day=0;
		int ans = -1;
		while(r<n){
			if(tired[r] == 1){
				tired_day++;
			}else{
				no_tired_day++;
			}
			if(tired_day <= no_tired_day){
				ans = max(ans,r-l);
				l=r;
				tired_day = 0;
				no_tired_day = 0;
			}
			r++;
		}
		if(tired_day > no_tired_day)
			ans = max(ans,r-l);
		reverse(tired.begin(),tired.end());
		// PrintVector(tired);
		l=0,r=0;
		tired_day=0,no_tired_day=0;
		// ans = -1;
		while(r<n){
			if(tired[r] == 1){
				tired_day++;
			}else{
				no_tired_day++;
			}
			if(tired_day <= no_tired_day){
				ans = max(ans,r-l);
				l=r;
				tired_day = 0;
				no_tired_day = 0;
			}
			r++;
		}
		if(tired_day > no_tired_day)
			ans = max(ans,r-l);
		return ans;
    }
};



	
int main() {
	Solution solution;
	// vector<int> hours = {9,9,6,0,6,6,9};
	// vector<int> hours = {9,6,9,6,9,6,9,6,9,6,9,6,9,6,9,6};
	// vector<int> hours = {6,6,9};
	// vector<int> hours = {6,6,5};
	vector<int> hours = {6,6,9,9,9,9};
	
	auto ans = solution.longestWPI(hours);
	
	cout << ans << endl;
	
	return 0;
}



