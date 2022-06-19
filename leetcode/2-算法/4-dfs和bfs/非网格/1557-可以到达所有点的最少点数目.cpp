#include <iostream> 
#include <vector>
#include <queue>
#include <set>
#include <cstring>
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

void PrintSet(set<int> s) {
	for(auto it : s)
		printf("%d ",it);
	cout << endl;	
}


// 只要入度为0，那就是无法到达的点
// 但是用set只击败了7.59%
// class Solution {
// public:
//     vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
// 		set<int> s;
// 		for(auto e : edges){
// 			s.insert(e[1]);
// 		}
// 		// PrintSet(s);
// 		vector<int> ans;
// 		for(int i = 0;i < n;i++){
// 			if(s.find(i) == s.end()){
// 				ans.push_back(i);
// 			}
// 		}
// 		return ans;
//     }
// };

// vector<int> 存储哈希表，击败45%
// int save_edges[n]; 存储哈希表，击败55.02%
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		// vector<int> save_edges(n);
		int save_edges[n];
		memset(save_edges,0,sizeof(save_edges));
		for(auto e : edges){
			save_edges[e[1]]++;
		}
		// PrintVector(save_edges);
		vector<int> ans;
		for(int i = 0;i < n;i++){
			if(save_edges[i] == 0){
				ans.push_back(i);
			}
		}
		return ans;
    }
};



int main(){
	Solution solution;
	vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
	int n = 6;

	// vector<vector<int>> edges =  {{0,1},{2,1},{3,1},{1,4},{2,4}};
	// int n = 5;
	PrintVVector(edges);

	auto ans = solution.findSmallestSetOfVertices(n,edges);
	
	PrintVector(ans);
	
	return 0;
}














