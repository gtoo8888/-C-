#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printVVector(vector<vector<string>> v){
	vector<vector<string>>::iterator iter;
	vector<string>::iterator it;
	vector<string> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}




class Solution {
public:
	bool ispalindrome(string s,int start,int end) {
		for(int i = start,j = end;i < j;i++,j--) {
//			cout << i << " " << j << endl;
			if(s[i] != s[j])
				return false;
		}
		return true;
	}	
	
	vector<vector<string>> ans;
	vector<string> path;
	void backtraining(string s,int StartIndex) {
		if(StartIndex >= s.size()) {
			ans.push_back(path);
			return;
		}
		
		for(int i = StartIndex;i < s.size();i++) {
			string str;
			if(ispalindrome(s,StartIndex,i)) {
				str = s.substr(StartIndex,i - StartIndex + 1);
				path.push_back(str);
			}
			else
				continue;
			cout << str << endl;
			backtraining(s,i+1);
			path.pop_back();
		}
	}
	
	
    vector<vector<string>> partition(string s) {
    	ans.clear();
    	path.clear();
    	backtraining(s,0);
		return ans;
    }
};

	
int main() {
	Solution solution;
	string s = "aabcc"; 
	bool isp;

//	isp = ispalindrome(s);
	
	auto ans = solution.partition(s);
	
//	PrintBool(isp);

//	vector<vector<string>> test = {{"strig","dfs"},{"ad","cc"} };
	
	
	printVVector(ans);
	
	return 0;
}



