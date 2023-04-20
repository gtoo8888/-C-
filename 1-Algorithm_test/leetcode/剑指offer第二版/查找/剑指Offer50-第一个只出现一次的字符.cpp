#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    char firstUniqChar(string s) {
		unordered_map<char,int> umap;
		for(auto c : s){
			umap[c]++;
		}
		set<char> vc;
		for(auto it : umap){
			if(it.second == 1)
				vc.insert(it.first);
		}
		for(auto c : s){
			if(vc.count(c))
				return c;
		}
		return ' ';
    }
};


int main() {
	Solution sol;
	int target = 23;
	// string s = "abaccdeff";
	string s = "";
	string s = "aabb";
	auto ans = sol.firstUniqChar(s);

	cout << ans << endl;
	
	return 0;
}



