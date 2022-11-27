#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
// class Solution {
// public:
// 	int n,m;	
// 	void dfs(vector<vector<int>>& matrix,int x,int y){
// 		if(x < 0 || x >= n || y < 0 || y >= m)
// 			return;
// 		printf("%d %d\n",x,y);
// 		matrix[x][y] = 0;
// 		PrintVVector(matrix);
// 		dfs(matrix,x+1,y);
// 		dfs(matrix,x-1,y);
// 		dfs(matrix,x,y+1);
// 		dfs(matrix,x,y-1);
// 		return;
// 	}
//     void setZeroes(vector<vector<int>>& matrix) {
// 		PrintVVector(matrix);
// 		n = matrix.size();
// 		m = matrix[0].size();
// 		for(int i = 0;i < n;i++){
// 			for(int j = 0;j < m;j++){
// 				if(matrix[i][j] == 0)
// 					dfs(matrix,i,j);
// 			}
// 		}
//     }
// };


class Solution {
public:
	int n,m;	
    void setZeroes(vector<vector<int>>& matrix) {
		// PrintVVector(matrix);
		n = matrix.size();
		m = matrix[0].size();
		vector<int> i_save;
		vector<int> j_save;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(matrix[i][j] == 0){
					i_save.push_back(i);
					j_save.push_back(j);
				}
			}
		}
		for(int i = 0;i < i_save.size();i++){
			for(int j = 0;j < n;j++){
				matrix[j][j_save[i]] = 0;
			}
		}
		for(int i = 0;i < i_save.size();i++){
			for(int j = 0;j < m;j++){
				matrix[i_save[i]][j] = 0;
			}
		}
    }
};


int main(){
	Solution solution;
	// vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
	vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

	solution.setZeroes(matrix);
	
	PrintVVector(matrix);
	
	return 0;
}














