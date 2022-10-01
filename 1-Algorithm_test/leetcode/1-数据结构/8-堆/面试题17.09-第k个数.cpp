#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

void PrintPriQueue(priority_queue<long,vector<long>,greater<long>> pri){
	while(!pri.empty()){
		cout << pri.top() << endl;
		pri.pop();
	}
}

// 最小堆
// 优先队列
class Solution {
public:
    int getKthMagicNumber(int k) {
		vector<int> factors = {3,5,7};
		unordered_set<long> seen;
		priority_queue<long,vector<long>,greater<long>> heap;
		seen.insert(1L);
		heap.push(1L);
		// PrintPriQueue(heap);
		int magic = 0;
		for(int i = 0;i < k;i++){	// 直到取出的元素数目达到要求的数量
			long curr = heap.top();
			heap.pop();			// 每次取出一个元素，就插入三个元素进去
			magic = (int)curr;
			// printf("magic:%d curr:%ld\n",magic,curr);
			for(int factor : factors){
				long next = curr * factor;
				// printf("          next:%ld factor:%d\n",next,factor);
				if(!seen.count(next)){
					seen.insert(next);
					heap.push(next);
				}
			}
			// PrintPriQueue(heap);
		}
		return magic;
    }
};




	
int main() {
	Solution solution;
	int k = 5;
	auto ans = solution.getKthMagicNumber(k);
	cout << ans << endl;
	return 0;
}


