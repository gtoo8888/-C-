#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;


void PrintVector(vector<int> v){for(auto it : v) cout << it << " ";cout << endl;}
void PrintVSector(vector<string> v){for(auto it : v)cout << it << endl;cout << endl;}
void PrintVVector(vector<vector<int>>& v){for(auto iter : v){auto it_tmp = iter;for(auto it : it_tmp)cout << it << " ";cout << endl;}cout << endl;}
void PrintBool(bool val){if(val == true)cout << "true" << endl;else cout << "false" << endl;cout << endl;}
void PrintMap(unordered_map<int,int> m) {for(auto it : m)printf("%d %d\n",it.first,it.second);cout << endl;}

void printarrary(int a[]){
	for(int i = 0;i < 26;i++)
		printf("%d ",a[i]);
}

class Solution {
public:
	bool check_string(string a,string b){
		// unordered_map<int,int> map;
		int hash_map[26] = {0};
		for(int i = 0;i < a.size();i++)
			hash_map[a[i] - 'a']++;
		for(int i = 0;i < b.size();i++)
			hash_map[b[i] - 'a']--;
		// for(int i = 0;i < 26;i++)
		// 	printf("%d ",hash_map[i]);
		for(int i = 0;i < 26;i++)
			if(hash_map[i] != 0)
				return false;
		return true;
	}
    vector<string> removeAnagrams(vector<string>& words) {
		vector<string> ans;
		int n = words.size();
		int i = 1;
		// cout << check_string(words[1],words[0]) << endl;
		int iter = 0;
		while(i < n){
			// cout << words[i] << " " << words[i-1] ;
			// printf(" %d %d\n",i,n);
			// PrintVSector(words);
			
			if(words[i].size() == words[i-1].size())
				if(check_string(words[i],words[i-1]))
					words.erase(words.begin()+i);
				else
					i++;
			else
				i++;
			n = words.size();
		}
		return words;
    }
};
	
int main() {
	Solution solution;
    // string num = "2300019";
	// vector<int> num = {1,2,3,4,5};
	vector<string> words = {"abba","baba","bbaa","cd","cd"};
	// vector<string> words = {"a","b","c","d","e"};
	// vector<string> words = {"abbb","aaab"};
	PrintVSector(words);

    auto ans = solution.removeAnagrams(words);

	PrintVSector(ans);
	return 0;
}




