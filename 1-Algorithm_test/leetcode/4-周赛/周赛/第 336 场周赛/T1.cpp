#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> yy;
        yy.insert('a');yy.insert('e');yy.insert('i');yy.insert('o');yy.insert('u');
        int ans = 0;
        for(int i = left;i <= right;i++){
            string tmp_str = words[i];
            
			// if(tmp_str.size() == 1 )
			// 	if(yy.find(tmp_str[0]) != yy.end())
            if(yy.find(tmp_str[0]) != yy.end() && yy.find(tmp_str[tmp_str.size()-1]) != yy.end())
                ans++;
        }
        return ans;
    }
};


	
int main() {
	Solution solution;
    // vector<string> words = {"are","amy","u"};
    // int left = 0,right = 2;

    vector<string> words = {"hey","aeo","mu","ooo","artro"};
    int left = 1,right = 4;

	auto ans = solution.vowelStrings(words,left,right);
	
	cout << ans << endl;
	
	return 0;
}







