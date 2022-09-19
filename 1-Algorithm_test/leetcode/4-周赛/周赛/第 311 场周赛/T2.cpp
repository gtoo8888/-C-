#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVCector(vector<char> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
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

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}


class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
		int ans = INT32_MIN;
		for(int i = 0;i < n ;i++){
			int size = 1;
			int pos = i;
			while(s[pos+1] == s[pos]+1 ){
				pos++;size++;
			}
			ans = size > ans ? size : ans;
		}
		return ans;
    }
};
	
int main() {
	Solution solution;
    string s = "abcde";

    auto ans = solution.longestContinuousSubstring(s);

	cout << ans << endl;
	return 0;
}




