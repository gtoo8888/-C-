#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


void PrintVector(vector<int> &v) {
	for(auto it = v.begin();it != v.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> task(n);
    for(int i = 0; i < n; i++){
        scanf("%d",&task[i]);
    }
//    sort(task.begin(),task.end());
//    PrintVector(task);
    
    int ti;
    while(cin >> ti){
    	int ans = 0;
    	int task_i = 0;
        while(ti > 0 && task_i < task.size()){
        	ti = ti - task[task_i];
        	task_i++;
        	if(ti >= 0)
        		ans++;
//        	printf("%d %d %d\n",ti,task_i,ans);
		}
		printf("%d\n",ans);
    }
    return 0;
}

// ����n,m��n������ĸ���
// ����ti,1,2,3,4....tn
// ��������1��
//7 4
//1 2 3 1 2 3 1
//1
//8
//11
//14
// �������1��
//1
//4
//5
//7

// ��������2��
//5 4
//1 2 3 4 5
//1
//2
//3
//4
// �������2��
//1
//1
//2
//2
