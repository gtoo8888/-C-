#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
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
	cout << endl;
}


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();		
		
		vector<int> shuiping;
		for(int i = 0;i < row;i++) {
			int max_temp = INT32_MIN;
			for(int j = 0;j < col;j++) {
				max_temp = grid[i][j] > max_temp ? grid[i][j] : max_temp;
			}
			shuiping.push_back(max_temp);
		}
		
		vector<int> chuzhi;
		for(int i = 0;i < col;i++) {
			int max_temp = INT32_MIN;
			for(int j = 0;j < row;j++) {
				max_temp = grid[j][i] > max_temp ? grid[j][i] : max_temp;
			}
			chuzhi.push_back(max_temp);
		}
//		PrintVector(chuzhi);
		vector<vector<int>> change_city(row,vector<int>(col,0));
		for(int i = 0;i < row;i++) {
			for(int j = 0;j < col;j++) {
				change_city[j][i] = 
				chuzhi[i] < shuiping[j] ? chuzhi[i] : shuiping[j];
			} 
		} 
//		PrintVVector(change_city);	
    	int ans = 0;		
		for(int i = 0;i < row;i++) 
			for(int j = 0;j < col;j++) 
				ans += change_city[i][j] - grid[i][j];		
		return ans;
    }
};



	
int main() {
	Solution solution;
	vector<vector<int>> grid = { 
	{3, 0, 8, 4}, 
	  {2, 4, 5, 7},
	  {9, 2, 6, 3},
	  {0, 3, 1, 0} };
	
	auto ans = solution.maxIncreaseKeepingSkyline(grid);
	
	cout << ans << endl;
	
	return 0;
}



