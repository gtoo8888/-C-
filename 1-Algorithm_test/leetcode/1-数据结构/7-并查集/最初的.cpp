#include <iostream> 
using namespace std;
#include <vector> 

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}
vector<int> parent(100,-1);

class UnionFind {
public:    
    vector<int> rank;

    UnionFind(vector<int>& test) {
        int n = test.size();
        vector<int> tmp(n);
        for(int i = 0;i < test.size();i++)
            tmp[i] = test[i];
        parent = tmp;
        // PrintVector(parent);
    }
    
    // 递归版本
    int find(int x) {
        if(parent[x] == x) // 查找的值是当前的
            return x;
        else    
            return find(parent[x]);  // 如果不是当前值，找他的父亲
    }

    // 非递归版本
    // int find(int x) {
    //     while(x != parent[x]) // 当x不是自己
    //         x = parent[x];  // 把x变为自己的父亲，也就是继续去找
    //     return x;
    // }

    // void merge(int x, int y) {
    //     int p1 = parent[x]; // 分别获取要合并的两个数的父亲
    //     int p2 = parent[y];
    //     for(int i = 0;i < parent.size();i++){
    //         if(parent[i] == p1) // 将第一个数的父亲改成第二个数的
    //             parent[i] = p2;
    //     }
    // }

    // 把y合并到x中去，把y的双亲设置为x
    void merge(int x,int y){// 对比上面的简化版的写法
        parent[find(y)] = find(x);
    }


};



//最初的算法1w的时候顶不住了
int main(){
	// vector<int> test = {0,1,2,3,4,5,6,7,8,9,10};
    int n = 100000;
    vector<int> test(n);
    for(int i = 0;i < n;i++)
        test[i] = i;
    // PrintVector(test);

    UnionFind uf(test);


    for(int i = 0;i < n-10;i++)
        uf.merge(i,i+1);



    // for(int i = 0;i < test.size();i++)  // 看看每个节点的父亲是谁
    //     cout << uf.find(test[i]) << " ";


	return 0;
}



