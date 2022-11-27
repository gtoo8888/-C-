#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <sstream>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
using namespace std;

class Trie{
	bool isEnd;
	Trie* next[26];
public:
	Trie(){
		isEnd = false;
		memset(next,0,sizeof(next));
	}
	void insert(string word){
		Trie* node = this;
		for(auto c : word){
			if(node->next[c-'a'] == NULL)
				node->next[c-'a'] = new Trie();
			node = node->next[c-'a'];
		}
		node->isEnd = true;
	}
	bool search(string word){
		Trie* node = this;
		for(auto c : word){
			node = node->next[c-'a'];
			if(node == NULL)
				return false;
		}
		return node->isEnd;
	}
	string startsWith(string prefix){
		Trie* node = this;
		string ans;
		for(auto c : prefix){
			if(node->isEnd)
				return ans;
			ans.push_back(c);
			node = node->next[c-'a'];
			if(node == NULL)
				return "";
		}
		return ans;
	}
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
		Trie* root = new Trie();
		for(auto word : dictionary){
			root->insert(word);
		}

		stringstream input(sentence);
		vector<string> res;
		string result;
		while(input >> result){
			// cout << result << endl;
			// cout << root->startsWith(result) << endl;
			if(root->startsWith(result) == ""){
				res.push_back(result);
				// res.push_back(" ");
			}else{
				res.push_back(root->startsWith(result));
				// res.push_back(" ");
			}
		}
		string ans;
		for(int i = 0;i < res.size();i++){
			ans += res[i];
			if(i < res.size()-1)
				ans += " ";
		}
		// PrintVSector(res);
		return ans;
    }
};

int main()
{
	Solution solution;
	vector<string> dictionary = {"cat","bat","rat"};
	string sentence = "the cattle was rattled by the battery";

	auto ans = solution.replaceWords(dictionary,sentence);
	cout << ans << endl;
	return 0;
}
