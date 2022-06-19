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

class UnionFind{
public:
	vector<int> parent;
	vector<int> rank;	
	int setcout;
	UnionFind(int n){
		this->setcout = n;
		parent = vector<int>(n);
		rank = vector<int>(n);
		for(int i = 0;i < n;i++)
			parent[i] = i;
	}
	int find(int x){
		if(parent[x] == x)
			return x;
		else
			return parent[x] = find(parent[x]);
	}
	// bool merge(int x,int y){		// 原始合并，超时了
	// 	int p1 = parent[x];
	// 	int p2 = parent[y];
	// 	if(p1 == p2)
	// 		return false;
	// 	for(int i = 0;i < parent.size();i++){
	// 		if(parent[i] == p1)
	// 			parent[i] = p2;
	// 	}
	// 	setcout--;
	// 	return true;
	// }
	bool merge(int x,int y){	//改进后的按秩合并，可以通过
		int p1 = find(x);
		int p2 = find(y);
		if(p1 == p2)
			return false;
		else{
			if(rank[p1] < rank[p2])
				swap(p1,p2);
			parent[p2] = p1;
			if(rank[p1] == rank[p2])
				rank[p1]++;
		}
		setcout--;
		return true;
	}
	void PrintfUF(void){
		for(auto i : parent){
			printf("%d ",find(i));
		}
		cout << endl;
	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
		if(connections.size() < n-1)
			return -1;
		UnionFind uf(n);
		for(auto con : connections){
			uf.merge(con[0],con[1]);
		}
		// uf.PrintfUF();
		return uf.setcout - 1;
    }
};



	
int main() {
	Solution solution;	 								
	// vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
	// int n = 4;
	vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
	int n = 6;
	// vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
	// int n = 6;
	// vector<vector<int>> connections =  {{0,1},{0,2},{3,4},{2,3}};
	// int n = 5;


	PrintVVector(connections);

	auto ans = solution.makeConnected(n,connections);
	
	cout << ans << endl;
	
	return 0;
}


