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
    
    // �ݹ�汾
    int find(int x) {
        if(parent[x] == x) // ���ҵ�ֵ�ǵ�ǰ��
            return x;
        else    
            return parent[x] = find(parent[x]);  // ������ǵ�ǰֵ�������ĸ���
            // return find(parent[x]);
    }

    void merge(int x, int y) {
        int p1 = find(x); // �ֱ��ȡҪ�ϲ����������ĸ���
        int p2 = find(y);
        if(p1 == p2)    // ����������ϵĸ���һ�£���˵����ͬ�����ϣ�ֱ�Ӻϲ�
            return;
        else{
            if(rank[p1] < rank[p2])   // ���p2���ȱ�p1�Ĵ�Ҳ����p2��p1�࣬����һ��
                swap(p1,p2);    // p2��С�ģ�p1�Ǵ��
            parent[p2] = p1;    // ��Сp2�ĺϲ������p1����
            if(rank[p1] == rank[p2])
                rank[p1]++;    // ���ӽ�����
        }
    }
};



//������㷨1w��ʱ�򶥲�ס��
// �Ż��ϲ��ڵ��Ժ󣬿���ʹ��1000W��������
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



    // for(int i = 0;i < test.size();i++)  // ����ÿ���ڵ�ĸ�����˭
    //     cout << uf.find(test[i]) << " ";


	return 0;
}



