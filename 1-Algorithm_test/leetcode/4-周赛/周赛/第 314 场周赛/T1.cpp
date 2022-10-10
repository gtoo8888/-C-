#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int m = logs.size();
        vector<int> spend(m,0);
        int max_id;
        int max_spend = 0;
        spend[0] = logs[0][1];
        if(spend[0] > max_spend){
            max_id = logs[0][0];
            max_spend = spend[0];
        }
        for(int i = 1;i < m;i++){
            spend[i] = logs[i][1] - logs[i-1][1];
            if(max_spend < spend[i]){
                max_id = logs[i][0];
                max_spend = spend[i];
            }
        }
        // PrintVector(spend);
        vector<int> ans;
        for(int i = 0;i < m;i++){
            if(max_spend == spend[i])
                ans.push_back(logs[i][0]);
        }
        sort(ans.begin(),ans.end());
        // PrintVector(ans);
        return ans[0];
    }
};
	
int main() {
	Solution solution;
    // int n = 10;
    // vector<vector<int>> logs = {{0,3},{2,5},{0,9},{1,15}};

    int n = 70;
    vector<vector<int>> logs = {{36,3},{1,5},{12,8},{25,9},{53,11},{29,12},{52,14}};    // 12



    // int a = 25;
    // int b = 30;

    auto ans = solution.hardestWorker(n,logs);

	cout << ans << endl;
	return 0;
}




