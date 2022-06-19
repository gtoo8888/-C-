#include <iostream>
#include <vector>
using namespace std;

void printVV(vector<vector<int> > v){
	vector<vector<int> >::iterator iter;
	vector<int>::iterator it;
	vector<int> temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		temp = *iter;
		for(it = temp.begin();it != temp.end();it++){
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int row = obstacleGrid.size();
    	int line = obstacleGrid[0].size();
    	cout << row << ' ' << line <<endl;
   		printVV(obstacleGrid);

    	vector<vector<int> > dp(row,vector<int>(line,0));
		for(int i = 0;i < row;i++){
			if(obstacleGrid[i][0] == 1)
				break;
			dp[i][0] = 1;
		}
		for(int i = 0;i < line;i++){
			if(obstacleGrid[0][i] == 1)
				break;
			dp[0][i] = 1;
		}
		
		for(int i = 1;i < row;i++){
			for(int j = 1;j < line;j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if(obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
			}
		}			
		printVV(dp);
		return dp[row-1][line-1];
    }
};
		
int main() {
	Solution solution;
	
	
	int temp[][3] = { {0,0,0},
					  {0,1,0},
					  {0,0,0},};
	int row = (sizeof(temp) / sizeof(int)) / (sizeof(temp[0]) / sizeof(int));//行数 
	int line = sizeof(temp[0]) / sizeof(int);//列数
	vector<vector<int> > obstacleGrid(row,vector<int>(line,0));
	for(int i = 0;i < row;i++)
		for(int j = 0;j < line;j++)
			obstacleGrid[i][j] = temp[i][j];
	


	int ans = 0;
	
	ans = solution.uniquePathsWithObstacles(obstacleGrid);
	
	cout << ans << endl;
	return 0;
}



