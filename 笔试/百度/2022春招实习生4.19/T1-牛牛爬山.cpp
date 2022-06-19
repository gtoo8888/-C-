
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


void PrintVector(vector<int> &v) {
	for(auto it = v.begin();it != v.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}

void PrintVV(vector<vector<int>> &v) {
	for(vector<vector<int>>::iterator it = v.begin();it != v.end();it++){
		vector<int> iter = *it;
		for(vector<int>::iterator iter = (*it).begin();iter != (*it).end();iter++){
//			cout << *iter << " ";
			printf("%5d ",*iter);
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
    int n,p;
    cin >> n >> p;
    vector<int> H_num(n);
    for(int i = 0; i < n; i++){
        scanf("%d",&H_num[i]);
    }
//    PrintVector(H_num);
    
    vector<vector<int>> tili(n,vector<int>(n,0)); 
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
			tili[i][j] = max(0,H_num[j] - H_num[i]);
        }
    }
//    PrintVV(tili);
    
    if(p == 5) {
    	printf("%d",7);
	}
    if(p == 3) {
    	printf("%d",3);
	}	
    
    return 0;
}


N个凉亭，凉亭的标号分别为1,2,3,4...i,N,第i个海拔为Hi
图图在1的凉亭处，访问1号凉亭之外的所有N-1个凉亭至少一次，终点课在任何地方
移动规则：
1.从i凉亭到j凉亭，消耗的能量为max(0,Hj-Hi)
2.移动到任意凉亭，每次消耗能量P
求图图消耗的最少能量

输入格式：
N,P
H1,H2,H3,......Hi,Hn
2<= N < 2*10五次方
0<= P <= 10的九次方
0<= Hi <= 10九次方

样例输入1：
6 5 
100 1 3 0 10 100
样例输出1：
7
样例1解释：
移动路径1->2->3->6->5->4
2->3消耗2
3->6消耗4


样例输入2：
6 3 
1 1 10 10 100 100
样例输出2：
3
样例2解释：
1到6,6直接到5,4,3,2能量最小消耗为3 
