#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void printVector(vector<int> v){
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


class UnionFind {
public:
    vector<int> parent;

    UnionFind (int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) 
			parent[i] = find(parent[i]);
        return parent[i];
    }

    void merge(int i, int j) {
        parent[find(i)] = find(j);
    }

    bool question(int i, int j) {
        return find(i) == find(j);
    }

	void PrintfUF(void){
		for(auto i : parent){
			printf("%d ",i);
		}
		cout << endl;
	}

	void PrintfUF_plus(int m,int n){
		// printVector(parent);
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++)
				printf("%3d ",parent[i*n+j]);
			cout << endl;
		}
		cout << endl;
	}
};


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
		// PrintVVector(grid);

		int m = grid.size();
		int n = grid[0].size();
		
		UnionFind uf(m*n + 10);

		// printf("%d %d\n",m,n);
		// uf.PrintfUF_plus(m,n);
		for(int i = 0;i < m;i++){
			if(grid[i][0] == 1)
				uf.merge(i*n,m*n);
			if(grid[i][n-1] == 1)
				uf.merge(i*n+n-1,m*n);
		}
		
		for(int j = 0;j < n;j++){
			if(grid[0][j] == 1)
				uf.merge(j,m*n);
			if(grid[m-1][j] == 1)
				uf.merge((m-1)*n+j,m*n);
		}
		// uf.PrintfUF_plus(m,n);
		// cout << uf.find(16) << endl;
		int dx[4] = {0,-1,0,1};
		int dy[4] = {1,0,-1,0};
	    // int dx[4] = {1, -1, 0, 0};
        // int dy[4] = {0, 0, 1, -1};

		for(int i = 0;i < m;i++){	// 岛内自己连接
			for(int j = 0;j < n;j++){
				if(grid[i][j] == 0)
					continue;
				for(int d = 0;d < 4;d++){
					int ii = i + dx[d];
					int jj = j + dy[d];
					if(ii < 0 || jj < 0 || ii >= m || jj >= n || grid[ii][jj] == 0)
						continue;
					uf.merge(ii*n+jj, i*n+j);// 这个方向移动的这个点，和原来搜索的点，是同一个祖先
				}
			}
		}
		// uf.PrintfUF_plus(m,n);
		int cnt = 0;
		for(int i = 1;i < m-1;i++){
			for(int j = 1;j < n-1;j++){
				// printf("%d %d %d %d %d\n",i,j,i*n+j,uf.find(i*n+j),uf.find(m*n));
				if(grid[i][j] && !(uf.find(i*n+j) == uf.find(m*n)) ){
					// printf("%d %d %d %d %d\n",i,j,i*n+j,uf.find(i*n+j),uf.find(m*n));
					cnt++;
				}
			}
		}
		return cnt;
    }
};





	
int main() {
	Solution solution;
	// vector<vector<int>> grid  = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
	// vector<vector<int>> grid  = {{0,0,1,1,1,0,1,1,1,0,1},
	// 							{1,1,1,1,0,1,0,1,1,0,0},
	// 							{0,1,0,1,1,0,0,0,0,1,0},
	// 							{1,0,1,1,1,1,1,0,0,0,1},
	// 							{0,0,1,0,1,1,0,0,1,0,0},
	// 							{1,0,0,1,1,1,0,0,0,1,1},
	// 							{0,1,0,1,1,0,0,0,1,0,0},
	// 							{0,1,1,0,1,0,1,1,1,0,0},
	// 							{1,1,0,1,1,1,0,0,0,0,0},
	// 							{1,0,1,1,0,0,0,1,0,0,1}};


	vector<vector<int>> grid  =	{	{0,1,1,0,0,0,0,1,1,0,0,0},
									{1,0,1,1,1,0,1,0,1,1,1,0},
									{1,1,0,1,0,0,1,1,0,1,1,1},
									{1,0,0,1,1,0,1,0,1,0,1,0},
									{1,0,0,0,0,1,0,0,1,1,0,1},
									{1,1,1,0,0,0,1,0,0,1,1,1},
									{1,1,1,0,0,0,0,1,0,1,0,1},
									{0,1,1,1,1,0,0,1,1,0,0,0},
									{0,1,0,1,0,1,0,1,0,0,0,1},
									{0,0,1,0,1,1,0,0,0,1,1,1}};

	auto ans = solution.numEnclaves(grid);
	cout << ans << endl;;
	return 0;
}


