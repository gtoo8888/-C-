#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
		int m = words[0].size();
		vector<pair<vector<int>,int>> vpv;
		vector<pair<int,int>> vii;
		vector<int> difference(m-1,0);
		for(int i = 0;i < n;i++){
			int sum = 0;
			for(int j = 0;j < m-1;j++){
				// printf("%c %c %d\n",words[i][j+1] , words[i][j],words[i][j+1] - words[i][j]);
				difference[j] = words[i][j+1] - words[i][j];
				sum += abs(difference[j]);
			}
			vpv.emplace_back(difference,i);
			vii.emplace_back(sum,i);
			PrintVector(difference);
		}
		int biaozhun = 0;
		unordered_map<int,int> map;
		for(int i = 0;i < m;i++){
			printf("%d ",vii[i].first);
			map[vii[i].first]++;			
		}
		cout << endl;
		PrintUnorder_Map(map);
		int cuowu = -1;
		for(auto it : map){
			if(it.second == 1)
				cuowu = it.first; 
		}
		printf("%d\n",cuowu);
		for(int i = 0;i < m;i++){
			if(cuowu == vii[i].first)	
				return words[vii[i].second];		
		}
		return "";

    }
};

	
int main() {
	Solution solution;
	// vector<string> words = {"adc","wzy","abc"};
	// vector<string> words = {"aaa","bob","ccc","ddd"};
	vector<string> words = {"aaaa","bobc","cccc","dddd"};

    string ans = solution.oddString(words);

	cout << ans << endl;
	return 0;
}




