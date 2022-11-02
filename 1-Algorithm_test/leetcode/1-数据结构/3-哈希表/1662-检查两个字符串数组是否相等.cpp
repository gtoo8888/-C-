#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		string str1,str2;
		for(int i = 0;i < word1.size();i++){
			str1 += word1[i];
		}
		for(int i = 0;i < word2.size();i++){
			str2 += word2[i];
		}
		cout << str1 << endl;
		cout << str2 << endl;
		if(str1 == str2)
			return true;
		else
			return false;
    }
};

int main() {
	Solution solution;
	// vector<string> word1 = {"ab", "c"};
	// vector<string> word2 = {"a", "bc"};

	vector<string> word1 = {"a", "cb"};
	vector<string> word2 = {"ab", "c"};

	auto ans = solution.arrayStringsAreEqual(word1,word2);

	PrintBool(ans);
	return 0;
}



