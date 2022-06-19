#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
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

void PrintSMap(unordered_map<string,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int> test_string(s.size()+1);
        int n = s.size();
        for(int i = 1;i <= n;i++){
            string s_tmp(s.begin(),s.begin()+i);
            test_string[s_tmp] = 1;
        }
        // PrintSMap(test_string);
        int ans = 0;
        for(string w : words){
            // cout << w << " " << test_string[w] << endl;
            if(test_string[w] == 1)
                ans++;
        }
        return ans;
    }
};



	
int main() {
	Solution solution;
    vector<string> words = {"a","a"};
    string s = "aa";

    auto ans = solution.countPrefixes(words,s);

	cout << ans << endl;
	return 0;
}




