#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printVector(vector<bool> v){
	for(vector<bool>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size(),false);
        dp[0] = true;
        for(int i = 0;i <= s.size();i++) {  //��s�ĵ�һ����ĸ��ʼ���з�
            for(int j = 0;j < i;j++) { // 
                string word = s.substr(j,i-j);
                cout << i << " " << j << endl << word << endl;
                if(wordset.find(word) != wordset.end() && dp[j]) {// ���������ĵ��ʣ����ֵ����ҵ���
                    dp[i] = true;
                 }
                printVector(dp);
            }
            cout << endl;
        }

        return dp[s.size()];
    }
};



int main() {
	Solution solution;
    string s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	
	auto ans = solution.wordBreak(s,wordDict);
	
	PrintBool(ans);
	return 0;
}



