#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


int gcd(int a,int b) { return b?gcd(b,a%b):a;}

//求两个数的最小公倍数
int lcm(int m,int g)  {
     return m/gcd(m,g)*g;
}

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_sum = 0;
        for(int i = 0;i < n-2;i++){
            int tmp_sum = 0;
            for(int j = 0;j < m-2;j++){
                // printf("%d %d %d\n",grid[i][j] , grid[i][j+1] , grid[i][j+2]);
                // printf("   %d \n",grid[i+1][j+1]);
                // printf("%d %d %d\n",grid[i+2][j] , grid[i+2][j+1] , grid[i+2][j+2]);
                tmp_sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + 
                          grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                // printf("%d \n",tmp_sum); 
                if(tmp_sum > max_sum){
                    max_sum = tmp_sum;
                }       
            }
            // printf("%d %d\n",tmp_sum,max_sum); 
            

            // max_sum = tmp_sum > max_sum ? tmp_sum : max_sum;
            // printf("%d \n",max_sum); 
        }
        return max_sum;
    }
};
	
int main() {
	Solution solution;
    vector<vector<int>> grid = {{6,2,1,3},{4,2,1,5},{9,2,8,7},{4,1,2,9}};
    // vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};

    PrintVVector(grid);

    auto ans = solution.maxSum(grid);

	cout << ans << endl;
	return 0;
}




