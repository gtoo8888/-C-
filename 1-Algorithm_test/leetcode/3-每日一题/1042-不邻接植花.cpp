#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 邻接矩阵会超时
// class Solution {
// public:
//     vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
// 		vector<vector<int>> graph(n,vector<int>(n,0));
// 		for(int i = 0;i < paths.size();i++){
// 			graph[paths[i][0]-1][paths[i][1]-1] = 1;
// 			graph[paths[i][1]-1][paths[i][0]-1] = 1;
// 		}
// 		PrintVVector(graph);
// 		vector<int> ans(n,-1);
// 		for(int i = 0;i < n;i++){
// 			int flow = 1;
// 			if(ans[i] == -1){
// 				ans[i] = flow++;
// 			}else{
// 				continue;
// 			}
// 			for(int j = i+1;j < n;j++){
// 				if(graph[i][j] == 1)
// 					ans[j] = flow++;
// 			}						
// 		}
// 		return ans;
//     }
// };

// 使用邻接表
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<int> graph[n];
		for(int i = 0;i < paths.size();i++){
			graph[paths[i][0]-1].push_back(paths[i][1]-1);
            graph[paths[i][1]-1].push_back(paths[i][0]-1);
		}
        // for(int i = 0;i < n;i++){
        //     for(auto it : graph[i])
        //         cout << it << " ";
        //     cout << endl; 
        // }
		vector<int> ans(n,-1);
		for(int i = 0;i < n;i++){
            set<int> color{1,2,3,4};
            for(int j = 0;j < graph[i].size();j++){ // 遍历邻接表，把每个位置的对应关系都找出来
                int now_pos = graph[i][j]; // 根据邻接表找到对应关系
                int now_color = ans[now_pos];   // 找到这个位置有没有上颜色，如果没有颜色就是-1
                color.erase(now_color); // 把上过的颜色从集合中删除掉
            }
            ans[i] = *(color.begin()); // 将没有上的颜色赋值
		}
		return ans;
    }
};
	
int main() {
	Solution solution;
	vector<vector<int>> paths;
	int n;
	n=3,paths = vector<vector<int>>{{1,2},{2,3},{3,1}};
	PrintVector(solution.gardenNoAdj(n,paths));cout << endl;

	n=4,paths = vector<vector<int>>{{1,2},{3,4}};
	PrintVector(solution.gardenNoAdj(n,paths));cout << endl;

	n=4,paths = vector<vector<int>>{{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
	PrintVector(solution.gardenNoAdj(n,paths));cout << endl;

	n=5,paths = vector<vector<int>>{{4,1},{4,2},{4,3},{2,5},{1,2},{1,5}};
	PrintVector(solution.gardenNoAdj(n,paths));cout << endl;
	return 0;
}



