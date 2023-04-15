#include <iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 找到第一个比自己大的就可以了
// class Solution {
// public:
//     vector<int> nextLargerNodes(ListNode* head) {
// 		ListNode* tmp = head;
// 		vector<int> list_num;
// 		while(tmp != nullptr){
// 			list_num.push_back(tmp->val);
// 			tmp = tmp->next;
// 		}
// 		int n = list_num.size();
// 		vector<int> dp(n,0);
// 		for(int i = n-2;i >= 0;i--){
// 			if(dp[i+1] == 0){
// 				if(list_num[i+1] > list_num[i])	
// 					dp[i] = list_num[i+1];
// 				else
// 					dp[i] = 0;
// 			}else{
// 				if(dp[i+1] > list_num[i]){
// 					dp[i] = dp[i+1];
// 				}else{
// 					dp[i] = 0;
// 				}
// 			}
// 		}
// 		return dp;
//     }
// };

// 直接查找一下最大的 O(n2)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
		ListNode* tmp = head;
		vector<int> list_num;
		while(tmp != nullptr){
			list_num.push_back(tmp->val);
			tmp = tmp->next;
		}
		int n = list_num.size();
		vector<int> ans(n,0);
		for(int i = 0;i < n;i++){
			int mid_max = list_num[i];
			for(int j = i+1;j < n;j++){
				if(list_num[j] > mid_max){
					ans[i] = list_num[j];
					break;
				}
			}
		}
		return ans;
    }
};

// 单调栈的做法



int main(){
	Solution solution;
	
	// vector<int> value1 = {2,1,5};
	// vector<int> value1 = {4,4,5,5};
	// vector<int> value1 = {2,7,4,3,5};
	// vector<int> value1 = {2,9,7,4,3,5};
	vector<int> value1 = {1,7,5,1,9,2,5,1};		// 7,9,9,9,0,5,0,0
	ListNode* head = CreateListNode(value1);

	auto ans = solution.nextLargerNodes(head);
		
	PrintVector(ans);
	return 0;
}
