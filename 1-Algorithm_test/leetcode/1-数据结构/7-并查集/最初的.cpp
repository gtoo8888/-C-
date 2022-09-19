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
    
    // �ݹ�汾
    int find(int x) {
        if(parent[x] == x) // ���ҵ�ֵ�ǵ�ǰ��
            return x;
        else    
            return find(parent[x]);  // ������ǵ�ǰֵ�������ĸ���
    }

    // �ǵݹ�汾
    // int find(int x) {
    //     while(x != parent[x]) // ��x�����Լ�
    //         x = parent[x];  // ��x��Ϊ�Լ��ĸ��ף�Ҳ���Ǽ���ȥ��
    //     return x;
    // }

    // void merge(int x, int y) {
    //     int p1 = parent[x]; // �ֱ��ȡҪ�ϲ����������ĸ���
    //     int p2 = parent[y];
    //     for(int i = 0;i < parent.size();i++){
    //         if(parent[i] == p1) // ����һ�����ĸ��׸ĳɵڶ�������
    //             parent[i] = p2;
    //     }
    // }

    // ��y�ϲ���x��ȥ����y��˫������Ϊx
    void merge(int x,int y){// �Ա�����ļ򻯰��д��
        parent[find(y)] = find(x);
    }


};



//������㷨1w��ʱ�򶥲�ס��
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



    // for(int i = 0;i < test.size();i++)  // ����ÿ���ڵ�ĸ�����˭
    //     cout << uf.find(test[i]) << " ";


	return 0;
}



