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

void printBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
		sort(arr.begin(),arr.end());

		unordered_map<int,int> cnt; 
		for(auto n : arr) {//把每个数取出来
			if(n%2 == 0 && n > 0 && cnt[n/2] ) {	//如果大于0,比如3登记了6，就把6划掉
				// cout << cnt[n/2] << endl;
				cnt[n/2]--;
			}else if(n < 0 && cnt[n*2] ) {	//如果小于0，并且登记过了，那就把登记的划掉
				// cout << cnt[n*2] << endl;
				cnt[n*2]--;
			}else{		//如果什么都没有登记过，那就登记一下
				cnt[n]++;
			}
			cout << n << endl;
			PrintMap(cnt);
		}
		for(unordered_map<int,int>::iterator it = cnt.begin();it != cnt.end();it++) {
			if(it->first == 0) {
				if(it->second%2 == 0)
					continue;
				return false;
			}
			if(it->second != 0)
				return false;
		}
		return true;
    }
};


	
int main() {
	Solution solution;
	vector<int> arr = {3,1,3,6};
	
	auto ans = solution.canReorderDoubled(arr);
	
	printBool(ans);
	
	return 0;
}



