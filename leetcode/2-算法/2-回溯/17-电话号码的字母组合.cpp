#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


void PrintSVector(vector<string> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << endl;
	cout << endl;
}



class Solution {
public:
	string m_ys[10] = {	" ",
						" ",
						"abc",
						"def",
						"ghi",
						"jkl",
						"mno",
						"pqrs",
						"tuv",
						"wxyz",};
	vector<string> ans;
	string path;
	void backtracking(string digits,int now_wei)	{//原来的字符串，现在处理的位数 
		if(now_wei == digits.size()) {
			ans.push_back(path);
			return;
		}
		
		int nums = digits[now_wei] - '0';
		string ys_str = m_ys[nums];
		
		for(int i = 0;i < ys_str.size();i++) {
			path.push_back(ys_str[i]);
//			cout << path << endl; 
			backtracking(digits,now_wei + 1);
			path.pop_back();
		}
	}
	
    vector<string> letterCombinations(string digits) {
    	ans.clear();
    	path.clear();
    	if(digits.size() == 0)
    		return  ans; 
    	backtracking(digits,0);//从第0位开始处理 
		return ans;
    }
};


	
int main() {
	Solution solution;
	string digits = "";
	
	auto ans = solution.letterCombinations(digits);
	
	cout << endl;	
	PrintSVector(ans);
	
	return 0;
}



