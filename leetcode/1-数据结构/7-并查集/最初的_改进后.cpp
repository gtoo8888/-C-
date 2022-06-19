#include <iostream> 
#include <vector> 
#include <ctime>
using namespace std;


void PrintVector(vector<int> &v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}
vector<int> parent(100,-1);
vector<int> rank(10,0);
class UnionFind {
public:    
    UnionFind(vector<int>& test) {
        int n = test.size();
        vector<int> tmp(n);
        for(int i = 0;i < test.size();i++)
            tmp[i] = test[i];
        parent = tmp;

        vector<int> tmp1(n,0);
        rank = tmp1;
        // PrintVector(rank1);
    }
    
    // 递归版本
    int find(int x) {
        if(parent[x] == x) // 查找的值是当前的
            return x;
        else    
            return parent[x] = find(parent[x]);  // 如果不是当前值，找他的父亲
            // return find(parent[x]);
    }

    void merge(int x, int y) {
        int p1 = find(x); // 分别获取要合并的两个数的父亲
        int p2 = find(y);
        if(p1 == p2)    // 如果两个集合的父亲一致，就说明是同个集合，直接合并
            return;
        else{
            if(rank[p1] < rank[p2])   // 如果p2的秩比p1的大，也就是p2比p1多，交换一下
                swap(p1,p2);    // p2是小的，p1是大的
            parent[p2] = p1;    // 把小p2的合并到大的p1里面
            if(rank[p1] == rank[p2])
                rank[p1]++;    // 增加结点深度
        }
    }
};



//最初的算法1w的时候顶不住了
// 优化合并节点以后，可以使用1000W的数据量
int main(){
	// vector<int> test = {0,1,2,3,4,5,6,7,8,9,10};
    int n = 10000000;
    vector<int> test(n);
    for(int i = 0;i < n;i++)
        test[i] = i;
    // PrintVector(test);

    UnionFind uf(test);

    clock_t start,end;
    start = clock();
    for(int i = 0;i < n-10;i++)
        uf.merge(i,i+1);
    end = clock();
    printf("time = %.0fms\n",double(end-start)/CLOCKS_PER_SEC * 1000);

    start = clock();
    cout << uf.find(100) << endl;
    end = clock();
    printf("time = %.0fms\n",double(end-start)/CLOCKS_PER_SEC * 1000);



    // for(int i = 0;i < test.size();i++)  // 看看每个节点的父亲是谁
    //     cout << uf.find(test[i]) << " ";


	return 0;
}



