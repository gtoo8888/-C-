#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
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

class myclass{
public:
	bool operator() (int i,int j) {
		return i < j;
	}
};

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
		int n = order.size();
		vector<int> hash_map(26);
		for(int i = 0;i < n;i++)
			hash_map[order[i] - 'a'] = i;
		// PrintVector(hash_map);
		for(int i = 0;i < words.size()-1;i++){
			int flag = false;
			for(int j = 0;j < min(words[i].size(),words[i+1].size());j++){	// 对前后两个单词进行对比
				if(words[i][j] != words[i+1][j]){	// 如果单词中的字母不一样
					printf("%d %d\n",hash_map[words[i][j] - 'a'],hash_map[words[i+1][j] - 'a']);
					if(hash_map[words[i][j] - 'a'] > hash_map[words[i+1][j] - 'a'])	// 看一下这个字母在外星人字典中的排序
						return false;	// 按外星人字典序，前面比后面大，直接接返回错误了
					else{	// 只要比较第一个就够了，如果按外星人字典序，前面比后面小，就直接可以结束判断这两个字符
						flag = true;
						break;
					}
				}
			}
			// 应对前面都是一样的，但是后面长度不一致的情况
			if(!flag && words[i].size() > words[i+1].size())
				return false;
		}
		return true;
    }
};


	
int main() {
	Solution solution;
	// vector<string> words  = {"hello","leetcode"};
	// string order = "hlabcdefgijkmnopqrstuvwxyz";

	// vector<string> words  = {"word","world","row"};
	// string order = "worldabcefghijkmnpqstuvxyz";

	vector<string> words  = {"apple","app"};
	string order = "abcdefghijklmnopqrstuvwxyz";	
	auto ans = solution.isAlienSorted(words,order);
	
	PrintBool(ans);
	
	return 0;
}



