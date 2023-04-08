#include <iostream>
#include <string.h>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Trie{
public:
	bool isEnd;
	Trie* next[26];
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

bool mycompare(string s1,string s2){
	return s1.size() < s2.size();
}

// dfs+字典树
class Solution {
public:
    Trie* root = new Trie();
    bool dfs(string word,int start,vector<int>& memo){
		// 1. 如果到最末尾了，那就需要返回成功
        if(word.size() == start)
            return true;
		// 2. 
        if(memo[start])
            return false;
        memo[start] = true;
        Trie* node = root;
        for(int i = start;i < word.size();i++){
			// 3. 手动的向下搜索
            char ch = word[i];
            int index = ch-'a';
            node = node->next[index];
            if(node == nullptr)
                return false;
            if(node->isEnd){
				// 如果这个单词到结尾了，那就返回true
                if(dfs(word,i+1,memo)){
                    return true;
                }
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // 1.先将短的字母排在前面
		sort(words.begin(),words.end(),mycompare);
        vector<string> ans;
        // 2.通过字典树对所有数组进行处理
        for(auto word : words){
            // 2.1 大小等于0,直接忽略
            if(word.size() == 0)
                continue;
            // 2.2 memo做记忆化搜索
            vector<int> memo(word.size(),0);
            // 2.3 查看现在这个单词，是不是可由别的单词组成
            if(dfs(word,0,memo)){
                // 可以组成，放入答案
                ans.emplace_back(word);
            }else{
                // 不可以组成，放入字典树
                root->insert(word);
            }
        }
        return ans;
    }
};


int main()
{
	Solution solution;
	vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};

	auto ans = solution.findAllConcatenatedWordsInADict(words);
	PrintVector(ans);

	return 0;
}
