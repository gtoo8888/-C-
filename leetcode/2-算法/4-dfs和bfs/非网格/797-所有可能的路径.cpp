#include <iostream> 
#include <vector>
#include <queue>
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

// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
// 		vector<vector<int>> ans;
// 		queue<int> que;
// 		que.push(0);
// 		int i = 0;
// 		while(!que.empty()){
// 			vector<int> tmp_ans;
// 			for(int i = 0;i < que.size();i++){
// 				int tmp = que.front();
// 				que.pop();
// 				tmp_ans.push_back(tmp);
// 				for(int j = 0;j < graph[i].size();j++){
// 				}
// 			}
// 		}
//     }
// };

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> ans_tmp;
	int target;
	void dfs(vector<vector<int>>& graph,int depth){
		if(depth == target){
			ans.push_back(ans_tmp);
			return;
		}
		for(auto y : graph[depth]){
			ans_tmp.push_back(y);
			dfs(graph,y);
			ans_tmp.pop_back();
		}
	}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		this->target = graph.size()-1;
		ans_tmp.push_back(0);
		dfs(graph,0);
		return ans;
    }
};



int main(){
	Solution solution;
	vector<vector<int>> graph =  {{1,2},{3},{3},{}};
	PrintVVector(graph);

	auto ans = solution.allPathsSourceTarget(graph);
	
	PrintVVector(ans);
	
	return 0;
}














