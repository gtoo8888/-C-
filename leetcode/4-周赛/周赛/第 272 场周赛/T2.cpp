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
    string addSpaces(string s, vector<int>& spaces) {
    	int len = spaces.size();
    	string add(len,'.');
    	string ans;
    	ans = s + add;
    	 		
//   	cout << ans << endl;
    	int j = ans.size() - 1;
    	int k = spaces.size() - 1;
    	for(int i = s.size()-1;i >= 0;i--) {
//			cout << ans[i+k] << " " << s[i] << endl;
//			cout << "----------" << i << " " << spaces[k] << endl;
    		if(k >= 0 && i == spaces[k]) {
    			ans[i + k + 1] = s[i];
    			ans[i + k] = ' ';
    			k--;
			}
    		else {
    			ans[i + k + 1] = s[i];
    		}
		}
        return ans;
    }
};


	
int main() {
	Solution solution;
	string s = "LeetcodeHelpsMeLearn";
	vector<int> spaces = {8,13,15};
	string ans;
	
	ans = solution.addSpaces(s,spaces);
	
	cout << ans << endl;
	
	return 0;
}



