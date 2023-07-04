#include <iostream>
using namespace std;
#include <string.h>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int si, sj, bi, bj; // 初始化起点和终点
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    si = i, sj = j;
                } else if (grid[i][j] == 'B') {
                    bi = i, bj = j;
                }
            }
        }
        auto f = [&](int i, int j) { // 坐标变为一维
            return i * n + j;
        };
        auto check = [&](int i, int j) { // 检测坐标合法性
            return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#';
        };
        int dirs[5] = {-1, 0, 1, 0, -1};
        deque<tuple<int, int, int>> q;
        q.emplace_back(f(si, sj), f(bi, bj), 0);
        bool vis[m * n][m * n];
        memset(vis, false, sizeof(vis));
        vis[f(si, sj)][f(bi, bj)] = true;
        while (!q.empty()) {
            auto [s, b, d] = q.front();
            q.pop_front();
            si = s / n, sj = s % n;
            bi = b / n, bj = b % n;
            if (grid[bi][bj] == 'T') { // 到达终点返回
                return d;
            }
            for (int k = 0; k < 4; ++k) {
                int sx = si + dirs[k], sy = sj + dirs[k + 1];
                if (!check(sx, sy)) {
                    continue;
                }
                if (sx == bi && sy == bj) { // 如果人走到了箱子上
                    int bx = bi + dirs[k], by = bj + dirs[k + 1];
                    if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                        continue;
                    }
                    vis[f(sx, sy)][f(bx, by)] = true;
                    q.emplace_back(f(sx, sy), f(bx, by), d + 1);
                } else if (!vis[f(sx, sy)][f(bi, bj)]) { // 如果没有访问过
                    vis[f(sx, sy)][f(bi, bj)] = true;
                    q.emplace_front(f(sx, sy), f(bi, bj), d);
                }
            }
        }
        return -1;
    }
};


	
int main() {
	Solution solution;
	vector<vector<char>> grid =  {{'#','#','#','#','#','#'},
             {'#','T','#','#','#','#'},
             {'#','.','.','B','.','#'},
             {'#','.','#','#','.','#'},
             {'#','.','.','.','S','#'},
             {'#','#','#','#','#','#'}};
	
	auto ans = solution.minPushBox(grid);
	
	cout << ans << endl;
	
	return 0;
}



