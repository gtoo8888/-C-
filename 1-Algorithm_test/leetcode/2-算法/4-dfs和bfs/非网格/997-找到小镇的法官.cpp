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
    int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> rudu(n+1,0);
		vector<int> chudu(n+1,0);
		for(int i = 0;i < trust.size();i++) {
			rudu[trust[i][1]]++;
			chudu[trust[i][0]]++;
		}
		// printVector(rudu);
		// printVector(chudu);
		for(int i = 1;i < rudu.size();i++) {
			if(rudu[i] == n-1 && chudu[i] == 0)
				return i;
		}
		return -1;
    }
};

	
int main() {
	Solution solution;
	int n = 4;
	vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
	
	auto ans = solution.findJudge(n,trust);
	
	cout << ans << endl;
	
	return 0;
}



