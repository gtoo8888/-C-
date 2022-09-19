#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;


void PrintVector(vector<int> v){for(auto it : v) cout << it << " ";cout << endl;}
void PrintVSector(vector<string> v){for(auto it : v)cout << it << endl;cout << endl;}
void PrintVVector(vector<vector<int>>& v){for(auto iter : v){auto it_tmp = iter;for(auto it : it_tmp)cout << it << " ";cout << endl;}cout << endl;}
void PrintBool(bool val){if(val == true)cout << "true" << endl;else cout << "false" << endl;cout << endl;}
void PrintMap(unordered_map<int,int> m) {for(auto it : m)printf("%d %d\n",it.first,it.second);cout << endl;}

void printarrary(int a[]){
	for(int i = 0;i < 26;i++)
		printf("%d ",a[i]);
}

void PrintSet(set<int> s) {
	for(auto it : s)
		printf("%d ",it);
	cout << endl;	
}

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
		int n = candidates.size();
        vector<int> pre(n+1);
		pre[0] = candidates[0];
		for(int i = 1;i <= n;i++){
			pre[i] = pre[i-1] & candidates[i];
		}
    }
};
	
int main() {
	Solution solution;
    // string num = "2300019";
	vector<int> candidates = {16,17,71,62,12,24,14};
	// vector<string> words = {"a","b","c","d","e"};
	// PrintVSector(words);

    auto ans = solution.largestCombination(candidates);

	cout << ans << endl;
	return 0;
}




