#include <iostream> 
#include <vector>
using namespace std;


void PrintVector(vector<char> v){
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


// dfs
class Solution {
public:
	int n,m;
	bool flag;
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	void dfs(vector<vector<int>> &grid,int x,int y){
		if(x < 0 || y < 0 || x >= n || y >= m ){	// �߽��뷵�������ֿ��ж�
		// ����Ǳ߽�Ļ����ͽ���־λȡ��������������
			flag = false;	// �������Ʊ�־λ����Ӱ��������dfs
			return;
		}
		if(grid[x][y] != 0)	// ͨ��ǰ���ɸѡ�����ж��Ա��Ǻ���ľͷ���
			return;
		grid[x][y] = 1;
		for(int i = 0;i < 4;i++){
			int cx = x + dx[i];
			int cy = y + dy[i];
			dfs(grid,cx,cy);
		}
	}

    int closedIsland(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		int ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				if(grid[i][j] == 0){
					flag = true;	// �ʼĬ���Ƿ�յģ���������ٷ񶨵�
					dfs(grid,i,j);
					// PrintVVector(grid);
					ans += flag;
				}
		return ans;
    }
};


int main(){
	Solution solution;
	vector<vector<int>> grid = {
	{1,1,1,1,1,1,1,0},
	{1,0,0,0,0,1,1,0},
	{1,0,1,0,1,1,1,0},
	{1,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,0}};

	auto ans = solution.closedIsland(grid);
	
	cout << ans << endl;
	
	return 0;
}














