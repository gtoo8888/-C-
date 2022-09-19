#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    }
};

	
int main() {
	Solution solution;
	string start = "AACCGGTT";
	string end = "AAACGGTA";
	vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
	
	auto ans = solution.minMutation(start,end,bank);
	
	cout << ans << endl;
	
	return 0;
}



