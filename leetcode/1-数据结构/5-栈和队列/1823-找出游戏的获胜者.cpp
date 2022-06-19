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

// 数组模拟 
//class Solution {
//public:
//    int findTheWinner(int n, int k) {
//		vector<bool> game(n,true);	// 用数组标记是否已经踢出去了，最开始，一个都没有踢掉 
//		vector<int> ans(n,0);		// 用来储存被踢出来的顺序 
//	
//		int count_num = 0; 	// 对应输入的k,报数的人数 
//		int now_pos = 0;	// 现在的位置 
//		int cnt = 0;		// 踢出去的人数 
//		int ansi = 0;		// 统计结果的数组下标 
//		while(cnt != n){
//			now_pos++;
//			if(now_pos > n)	// 数组到头了，循环一下 
//				now_pos = 1;	// 是从第一个数字开始走的 
//			if(game[now_pos] == true){	// 如果没有被踢出去 
//				count_num++;	// 继续报数 
//				if(count_num == k){	// 如果报数到k个人了 
//					game[now_pos] = false;	//当前位置的人踢出去 
//					cnt++; // 踢出去的人数增加一个 
//					ans[ansi++] = now_pos;	// 加入结果 
//					count_num = 0;	// 报数重新开始循环 
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

