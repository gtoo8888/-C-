#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

// 字典树的变种
class Trie
{
public:
	int val; // 每个节点存储这个前缀经过了多少次
	Trie *next[26];
	Trie(){
		val = 0;
		memset(next,0,sizeof(next));
	}

	void insert(string word){
		Trie* node = this;
		for (auto c : word){
			if (node->next[c - 'a'] == NULL)
				node->next[c - 'a'] = new Trie();
			node->next[c-'a']->val++;
			node = node->next[c-'a'];
		}
	}

	int search(string word){
		Trie *node = this;
		int prefix_val = 0;
		for (auto c : word)
		{
			if(node->next[c-'a'] == NULL)
				return prefix_val;
			node = node->next[c - 'a'];
			prefix_val += node->val;
		}
		return prefix_val;
	}
};


class Solution{
public:
	vector<int> sumPrefixScores(vector<string> &words){
		Trie* root = new Trie();
		for (string word : words){
			root->insert(word);
		}
		vector<int> ans;
		for (auto word : words){
			ans.emplace_back(root->search(word));
		}
		return ans;
	}
};

int main()
{
	Solution solution;

	vector<string> words = {"abc", "ab", "bc", "b"};

	auto ans = solution.sumPrefixScores(words);
	printVector(ans);
	return 0;
}
