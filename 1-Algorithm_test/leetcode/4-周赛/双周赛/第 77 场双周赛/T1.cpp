#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int> test_string(s.size()+1);
        int n = s.size();
        for(int i = 1;i <= n;i++){
            string s_tmp(s.begin(),s.begin()+i);
            test_string[s_tmp] = 1;
        }
        // PrintSMap(test_string);
        int ans = 0;
        for(string w : words){
            // cout << w << " " << test_string[w] << endl;
            if(test_string[w] == 1)
                ans++;
        }
        return ans;
    }
};



	
int main() {
	Solution solution;
    vector<string> words = {"a","a"};
    string s = "aa";

    auto ans = solution.countPrefixes(words,s);

	cout << ans << endl;
	return 0;
}




