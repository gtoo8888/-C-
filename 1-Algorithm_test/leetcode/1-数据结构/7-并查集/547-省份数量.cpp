#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
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


class UnionFind {
public:
    vector<int> parent;

    UnionFind (int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) 
			parent[i] = find(parent[i]);
        return parent[i];
    }

    void merge(int i, int j) {
        parent[find(i)] = find(j);
    }

	void PrintfUF(void){
		for(auto i : parent){
			printf("%d ",find(i));
		}
		cout << endl;
	}

	void PrintfUF_plus(int m,int n){
		// printVector(parent);
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++)
				printf("%3d ",parent[i*n+j]);
			cout << endl;
		}
		cout << endl;
	}

	int UF_count(){
		unordered_map<int,int> map;
		for(int i = 0;i < parent.size();i++){
			map[find(parent[i])]++;
		}
		int ans = 0;
		for(auto m : map){
			ans++;
		}
		return ans;
	}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size(),m = isConnected[0].size();
		UnionFind uf(n);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++){
				if(isConnected[i][j] == 1){
					// printf("%d %d\n",i,j);
					uf.merge(i,j);
				}
			}
		// uf.PrintfUF();
		return uf.UF_count();
    }
};



	
int main() {
	Solution solution;	 								
	// vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
	// vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
	vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};

	PrintVVector(isConnected);

	auto ans = solution.findCircleNum(isConnected);
	
	cout << ans << endl;
	
	return 0;
}


