#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// ����ģ�� 
//class Solution {
//public:
//    int findTheWinner(int n, int k) {
//		vector<bool> game(n,true);	// ���������Ƿ��Ѿ��߳�ȥ�ˣ��ʼ��һ����û���ߵ� 
//		vector<int> ans(n,0);		// �������汻�߳�����˳�� 
//	
//		int count_num = 0; 	// ��Ӧ�����k,���������� 
//		int now_pos = 0;	// ���ڵ�λ�� 
//		int cnt = 0;		// �߳�ȥ������ 
//		int ansi = 0;		// ͳ�ƽ���������±� 
//		while(cnt != n){
//			now_pos++;
//			if(now_pos > n)	// ���鵽ͷ�ˣ�ѭ��һ�� 
//				now_pos = 1;	// �Ǵӵ�һ�����ֿ�ʼ�ߵ� 
//			if(game[now_pos] == true){	// ���û�б��߳�ȥ 
//				count_num++;	// �������� 
//				if(count_num == k){	// ���������k������ 
//					game[now_pos] = false;	//��ǰλ�õ����߳�ȥ 
//					cnt++; // �߳�ȥ����������һ�� 
//					ans[ansi++] = now_pos;	// ������ 
//					count_num = 0;	// �������¿�ʼѭ�� 
//				}
//			}
//		}
////		PrintVector(ans);
//		return ans[n-1];
//    }
//};

void PrintQueue(queue<int> q){
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
	}
	cout << endl; 
}


class Solution {
public:
    int findTheWinner(int n, int k) {
		queue<int> q;
		for(int i = 1;i <= n;i++) 
			q.push(i);
		
		while(q.size() > 1){
			for(int i = 1;i < k;i++){
				q.push(q.front());
				q.pop();
			}
			q.pop(); 
			// PrintQueue(q);
		}
		return q.front();
    }
};


 
int main() {
	Solution solution;
	int n = 5;
	int k = 2;
	
	auto ans = solution.findTheWinner(n,k);
	
	cout << ans << endl;
	return 0;
}

