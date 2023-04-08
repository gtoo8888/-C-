#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// class Solution {
// public:
//     vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
// 		PrintVector(req_skills);
// 		cout << endl;
// 		PrintVVector(people);
// 		unordered_map<string,vector<int>> umap;
// 		int pn = people.size();
// 		for(int i = 0;i < pn;i++){
// 			for(auto it : people[i]){
// 				if(umap.find(it) != umap.end()){
// 					vector<int> tmp = umap[it];
// 					tmp.push_back(i);
// 					umap[it] = tmp;
// 				}else{
// 					vector<int> tmp;
// 					tmp.push_back(i);
// 					umap[it] = tmp;
// 				}
// 			}
// 		}
// 		return {};
//     }
// };

// 将元素 x 变成集合 {x}，即 1 << x。
// 判断元素 x 是否在集合 A 中，即 ((A >> x) & 1) == 1。
// 计算两个集合 A,,B 的并集 A∪B，即 A | B。例如 110 | 11 = 111。
// 计算 A∖B，表示从集合 A 中去掉在集合 B 中的元素，即 A & ~B。例如 110 & ~11 = 100。
// https://leetcode.cn/problems/smallest-sufficient-team/solutions/2214387/zhuang-ya-0-1-bei-bao-cha-biao-fa-vs-shu-qode/

// 状压dp+位运算
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		// PrintVector(req_skills);
		// cout << endl;
		// PrintVVector(people);
		unordered_map<string,int> skill_index;
		int n = req_skills.size();
		// 1. 将技能用下标表示
		for(int i = 0;i < req_skills.size();i++){
			skill_index[req_skills[i]] = i;
		}
		int pn = people.size();
		vector<vector<int>> dp(1 << n);
		for(int i = 0;i < pn;i++){
			int now_skill = 0;
			// 2. 求出每个人有的技能
			for(auto it : people[i]){
				now_skill |= (1 << skill_index[it]);
			}
			// string tmp = PrintBit(now_skill);
			for(int prev = 0;prev < dp.size();++prev){
				if(prev > 0 && dp[prev].empty()){
					continue;
				}
				// 3.通过或运算，求得之前的技能加上现在的技能
				int comb = prev | now_skill;
				if(comb == prev)
					continue;
				if(dp[comb].empty() || dp[prev].size() + 1 < dp[comb].size()){
					dp[comb] = dp[prev];
					dp[comb].push_back(i);
				}
			}
		}
		// PrintVVector(dp);
		// 4.获得最终结果
		return dp[(1 << n)-1];
    }
};


	
int main() {
	Solution solution;
	vector<string> req_skills = {"java","nodejs","reactjs"};
 	vector<vector<string>> people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};


	// vector<string> req_skills = {"algorithms","math","java","reactjs","csharp","aws"};
	// vector<vector<string>> people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};


	auto ans = solution.smallestSufficientTeam(req_skills,people);
	
	PrintVector(ans);
	return 0;
}



