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
    int lengthOfLongestSubstring(string s) {
		int left=0,right=0;
		int length = 0;//可用的长度
		int ans = 0;
		for(;right < s.size();right++) {//对整个字符串的遍历
			char tempchar = s[right];
			for(int i = left;i < right;i++) {//对小区间的遍历
				if(tempchar == s[i]){//出现一样的就要跳出循环了
					left = i + 1;
					length = right - left;
					break;
				}
			}
			length++;
			ans = max(length,ans);

			string temp_s = s.substr(left,right-1);
			cout << length << " " << temp_s << endl;
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	string s = "pwwkewfsdfvsvsdfefwf";
	
	auto ans = solution.lengthOfLongestSubstring(s);
	cout << ans << endl;
	
	return 0;
}



