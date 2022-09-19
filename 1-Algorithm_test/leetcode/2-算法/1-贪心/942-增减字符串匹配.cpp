#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// ?????
// ???"I",??perm[i] < perm[i + 1]????????????????????0??????
// ???"D",??perm[i] > perm[i + 1]????????????????????n??????
class Solution {
public:
    vector<int> diStringMatch(string s) {
		int n = s.size();
		vector<int> ans(n+1);
		int ii = 0,jj = n;
		for(int i = 0;i <= n;i++){
			if(s[i] == 'I')
				ans[i] = ii++;
			else
				ans[i] = jj--;
		}
		return ans;
    }
};

		
int main() {
	Solution solution;
	string s = "DDI";
	
	auto ans = solution.diStringMatch(s);
	
	printVector(ans);
	return 0;
}


