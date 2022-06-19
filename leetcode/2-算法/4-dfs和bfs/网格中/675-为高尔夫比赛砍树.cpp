#include <iostream> 
#include <vector>
#include <queue>
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


vector<vector<int>> forest_tmp;
bool cmp(const pair<int,int> a,const pair<int,int> b){
	return forest_tmp[a.first][a.second] < forest_tmp[b.first][b.second];
}
// void PrintVIector(vector<pair<int,int>> v){
// 	for(auto it : v){
// 		printf("%d %d %d\n",it.first,it.second,forest_tmp[it.first][it.second]);
// 		// printf("%d %d\n",it.first,it.second);
// 	}
// 	cout << endl; 
// }
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
class Solution {
public:
	int n,m;
	int ans = 0;
	int bfs(vector<vector<int>>& forest,int sx,int sy,int tx,int ty){
		if(sx == tx && sy == ty){
			return 0 ;
		}
		int step = 0;
		queue<pair<int,int>> que;
		vector<vector<bool>> visted(n,vector<bool>(m,false));
		que.emplace(sx,sy);
		visted[sx][sy] = true;
		while(!que.empty()){
			step++;
			int len = que.size(); // bfs 遍历一定要把当前的队列的长度取出
			//不然会不断的增长，不会结束循环
			for(int i = 0;i < len;i++){
				int cx = que.front().first;
				int cy = que.front().second;
				que.pop();
				for(int j = 0;j < 4;j++){
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					// printf("%d %d %d %d %d\n",nx,ny,tx,ty,step);
					if(nx >= 0 && ny >= 0 && nx < n && ny < m){
						if(!visted[nx][ny] && forest[nx][ny] > 0){
							if(nx == tx && ny == ty)
								return step;
							que.emplace(nx,ny);
							visted[nx][ny] = true;
						}
					}
				}
			}
		}
		return -1;
	}
    int cutOffTree(vector<vector<int>>& forest) {
		forest_tmp = forest;
		this->n = forest.size();
		this->m = forest[0].size();
		vector<pair<int,int>> trees;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++) {
				if(forest[i][j] > 1) {
					trees.emplace_back(i,j);
				}
			}
		}
		sort(trees.begin(),trees.end(),cmp);
		// PrintVIector(trees);
		int cx = 0,cy = 0,ans = 0;
		for(int i = 0;i < trees.size();i++){
			int step = bfs(forest,cx,cy,trees[i].first,trees[i].second);
			if(step == -1){
				return -1;
			}
			// printf("cx:%d cy:%d %d %d %d\n",cx,cy,trees[i].first,trees[i].second,step);
			// printf("%d\n",step);
			ans += step;
			cx = trees[i].first;
			cy = trees[i].second;
		}
		return ans;
    }
};

int main(){

	// freopen("out.out","w",stdout);

	Solution solution;
	// vector<vector<int>> forest = {{1,2,3},{0,0,4},{7,6,5}};
	vector<vector<int>> forest = {{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};
	PrintVVector(forest);

	auto ans = solution.cutOffTree(forest);
	
	cout << ans << endl;
	
	return 0;
}















