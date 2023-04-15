#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     vector<bool> camelMatch(vector<string>& queries, string pattern) {
// 		int n = queries.size();
// 		vector<bool> ans(n,true);
// 		for(int i = 0;i < n;i++){
// 			string query = queries[i];
// 			int m = query.size();
// 			vector<bool> query_tmp(m,false);
// 			int index = 0;
// 			for(int j = 0;j < m;j++){
// 				if(query[j] == pattern[index]){
// 					query_tmp[j] = true;
// 					index++;
// 					continue;
// 				}
// 				if(query[j] >= 'a' && query[j] <= 'z'){
// 					query_tmp[j] = true;
// 					continue;
// 				}
// 			}
// 			// printf("%d\n",index);
// 			if(index < pattern.size()){
// 				ans[i] = false;
// 				continue;
// 			}
// 			// PrintVector(query_tmp);
// 			for(int j = 0;j < m;j++){
// 				if(query_tmp[j] == false){
// 					ans[i] = false;
// 					break;
// 				}
// 			}
// 		}
// 		return ans;
//     }
// };


// 双指针O(n)
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
		int n = queries.size();
		vector<bool> ans(n,true);
		for(int i = 0;i < n;i++){
			int q = 0;
			string query = queries[i];
			for(int j = 0;j < query.size();j++){
				if(pattern[q] == query[j]){
					q++;
				}
			}
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<string> queries;
	string pattern;
	queries = vector<string>{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},pattern = "FB";
	PrintVector(solution.camelMatch(queries,pattern));cout << endl;

	queries = vector<string>{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},pattern = "FoBa";
	PrintVector(solution.camelMatch(queries,pattern));cout << endl;

	queries = vector<string>{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},pattern = "FoBaT";
	PrintVector(solution.camelMatch(queries,pattern));cout << endl;

	return 0;
}



