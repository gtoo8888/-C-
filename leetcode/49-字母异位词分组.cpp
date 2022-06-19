#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map> 
#include <algorithm>
using namespace std;

void printVVector(vector<vector<string>> str){
	vector<vector<string>>::iterator iter = str.begin();
	vector<string>::iterator it;
	vector<string> it_temp;
	
	for(iter ;iter != str.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin(); it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string,vector<string>> map;
		
		for(string str_temp : strs){
			string key = str_temp;
			sort(key.begin(),key.end());
			map[key].push_back(str_temp);
		}
		
		vector<vector<string>> ans;
		for(unordered_map<string,vector<string>>::iterator it = map.begin();it != map.end();it++){
			ans.push_back(it -> second) ;
		} 
		return ans;
    }
};
		
int main() {
	Solution solution;
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	
	vector<vector<string>> v;
	
	v = solution.groupAnagrams(strs);
	
	printVVector(v);
	
	return 0;
}



