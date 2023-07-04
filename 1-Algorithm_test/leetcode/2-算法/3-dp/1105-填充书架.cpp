#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1,INT32_MAX);
        dp[0] = 0;
        for(int i = 0;i < n;i++){
            int maxHeight = 0,curWidth = 0;
            for(int j = i;j >= 0;j--){
                curWidth += books[j][0];
                if(curWidth > shelfWidth){
                    break;
                }
                maxHeight = max(maxHeight,books[j][1]);
                dp[i+1] = min(dp[i+1],dp[j]+maxHeight);
            }
        }
        PrintVector(dp);
        return dp[n];
    }
};

int main() {
	Solution solution;
	vector<vector<int>> nums = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelfWidth = 4;
	
	auto ans = solution.minHeightShelves(nums,shelfWidth);
	
	cout << ans << endl;
	return 0;
}



