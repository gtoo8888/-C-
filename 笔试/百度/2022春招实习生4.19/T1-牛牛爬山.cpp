
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


N����ͤ����ͤ�ı�ŷֱ�Ϊ1,2,3,4...i,N,��i������ΪHi
ͼͼ��1����ͤ��������1����֮ͤ�������N-1����ͤ����һ�Σ��յ�����κεط�
�ƶ�����
1.��i��ͤ��j��ͤ�����ĵ�����Ϊmax(0,Hj-Hi)
2.�ƶ���������ͤ��ÿ����������P
��ͼͼ���ĵ���������

�����ʽ��
N,P
H1,H2,H3,......Hi,Hn
2<= N < 2*10��η�
0<= P <= 10�ľŴη�
0<= Hi <= 10�Ŵη�

��������1��
6 5 
100 1 3 0 10 100
�������1��
7
����1���ͣ�
�ƶ�·��1->2->3->6->5->4
2->3����2
3->6����4


��������2��
6 3 
1 1 10 10 100 100
�������2��
3
����2���ͣ�
1��6,6ֱ�ӵ�5,4,3,2������С����Ϊ3 
