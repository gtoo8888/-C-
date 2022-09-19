#include <iostream>
#include <vector>
using namespace std;

void printSVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << "PrintVVector(vector<vector<int>> v)"<< endl;
}

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int iii = 0;iii < strs.size();iii++){
            
            int oneNum = 0,zeroNum = 0;
            for(int i = 0;i < strs[iii].size();i++){
                if(strs[iii][i] == '0') zeroNum++;
                else oneNum++;
            }
            // cout << zeroNum <<" " << oneNum << endl;
            for(int i = m;i >= zeroNum;i--) {
                for(int j = n;j >= oneNum;j--) {
                    dp[i][j] = max(dp[i][j],dp[i - zeroNum][j - oneNum] + 1);
                    // PrintVVector(dp);
                }
                // cout << endl;
            }
        }
        return dp[m][n];
    }
};

int main() {
	Solution solution;
	vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
	// printSVector(strs);

	auto ans = solution.findMaxForm(strs,m,n);
	
	cout << ans << endl;
	return 0;
}



