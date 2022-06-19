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
			for(int j = 0;j < min(words[i].size(),words[i+1].size());j++){	// ��ǰ���������ʽ��жԱ�
				if(words[i][j] != words[i+1][j]){	// ��������е���ĸ��һ��
					printf("%d %d\n",hash_map[words[i][j] - 'a'],hash_map[words[i+1][j] - 'a']);
					if(hash_map[words[i][j] - 'a'] > hash_map[words[i+1][j] - 'a'])	// ��һ�������ĸ���������ֵ��е�����
						return false;	// ���������ֵ���ǰ��Ⱥ����ֱ�ӽӷ��ش�����
					else{	// ֻҪ�Ƚϵ�һ���͹��ˣ�������������ֵ���ǰ��Ⱥ���С����ֱ�ӿ��Խ����ж��������ַ�
						flag = true;
						break;
					}
				}
			}
			// Ӧ��ǰ�涼��һ���ģ����Ǻ��泤�Ȳ�һ�µ����
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



