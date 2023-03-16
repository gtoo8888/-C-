#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     int maximalNetworkRank(int n, vector<vector<int>>& roads) {
// 		// vector<unordered_map<int,int>> vum(n,unordered_map<int,int>());
// 		unordered_map<int,unordered_set<int>> map;
// 		int rn = roads.size();
// 		for(auto iter : roads){
// 			auto it = iter;
// 			int fi = it[0];
// 			int se = it[1];
// 			if(map.find(fi) == map.end()){ // 如果没有这个元素
// 				unordered_set<int> tmp;
//                 tmp.emplace(se);
// 				map[fi] = tmp;
// 			}else{
// 				unordered_set<int> tmp = map[fi];
// 				tmp.emplace(se);
// 				map[fi] = tmp;
// 			}

//             if(map.find(se) == map.end()){ // 如果没有这个元素
// 				unordered_set<int> tmp;
//                 tmp.emplace(fi);
// 				map[se] = tmp;
// 			}else{
// 				unordered_set<int> tmp = map[se];
// 				tmp.insert(fi);
// 				map[se] = tmp;
// 			}
// 		}
//         int ans = INT32_MIN;
//         // for(auto iter : roads){
// 		// 	auto it = iter;
// 		// 	int fi = it[0];
// 		// 	int se = it[1];
//         //     int sum = map[fi].size() - 1 + map[se].size() - 1 + 1; 
//         //     ans = sum > ans ? sum : ans;
// 		// }
//         vector<int> zhi_sum(n,0);
//         for(int i = 0;i < n;i++){
//             zhi_sum[i] = map[i].size();
// 		}
//         sort(zhi_sum.begin(),zhi_sum.end(),greater<int>());
//         // PrintVector(zhi_sum);
// 		return zhi_sum[0]+zhi_sum[1];
//     }
// };


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		vector<vector<bool>> connect(n, vector<bool>(n,false));
		vector<int> degree(n, 0);
		for(auto it : roads){
			int fi = it[0];
			int se = it[1];
			connect[fi][se] = true;
			connect[se][fi] = true;
			degree[se]++;
			degree[fi]++;
		}
		int maxrank = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
				maxrank = max(maxrank,rank);
			}
		}
		return maxrank;
    }
};

	
int main() {
	Solution solution;
	// vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};int n = 4;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};int n = 8; // 城市并非直接相连
	
	auto ans = solution.maximalNetworkRank(n,roads);
	
	cout << ans << endl;
	
	return 0;
}



