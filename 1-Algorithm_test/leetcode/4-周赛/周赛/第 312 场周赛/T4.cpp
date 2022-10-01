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

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
		
		int n = words.size();
		for(auto word : words){
			vector<string> qianzhui;
			int nw = word.size();
			string qianzhui = word[0];
			for(int i = 1;i < nw;i++){
				qianzhui = qianzhui + word[i];
				qianzhui.emplace_back(qianzhui)
			}
		}
        
    }
};
	
int main() {
	Solution solution;
    vector<string> words = {"abc","ab","bc","b"};

    auto ans = solution.sumPrefixScores(words);

	PrintVector(ans);
	return 0;
}




