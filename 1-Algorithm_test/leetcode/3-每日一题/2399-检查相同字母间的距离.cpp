#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
		vector<int> vec(26);
		int n = s.size();
		for(int i = 0;i < n;i++){
			int index = s[i] - 'a';
			if(vec[index] && i - vec[index] != distance[index])
				return false;
			vec[index] = i+1;
		}
		return true;
    }
};

	
int main() {
	Solution solution;
	string s = "abaccb";
	vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	auto ans = solution.checkDistances(s,distance);
	
	PrintBool(ans);
	
	return 0;
}



