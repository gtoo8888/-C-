#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> graph[n];
        for(int i = 0;i < edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        // for(int i = 0;i < n;i++){
        //     for(auto it : graph[i])
        //         cout << it << " ";
        //     cout << endl; 
        // }
        int max_edge_num = -1,max_edge_pos = -1;
        for(int i = 0;i < n;i++){
            int tmp = graph[i].size();
            if(tmp > max_edge_num){
                max_edge_num = tmp;
                max_edge_pos = i;
            }
        }
        vector<int> jianshao = graph[max_edge_pos];
        // PrintVector(jianshao);
        for(int i = 0;i < jianshao.size();i++){
            price[jianshao[i]] /= 2;
        }
        PrintVector(price);
        return -1;
    }
};


int main() {
	Solution solution;
    int n; vector<vector<int>> edges; vector<int> price; vector<vector<int>> trips;
    n = 4;edges = {{0,1},{1,2},{1,3}};price = {2,2,10,6};trips = {{0,3},{2,1},{2,3}};
	cout << solution.minimumTotalPrice(n,edges,price,trips) << endl;
	return 0;
}




