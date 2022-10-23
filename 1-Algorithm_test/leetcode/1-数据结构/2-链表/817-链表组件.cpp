#include <iostream> 
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



// 没写完的思路
// class Solution {
// public:
//     int numComponents(ListNode* head, vector<int>& nums) {
// 		vector<int> tmp;
// 		ListNode* tmp_list = head;
// 		while(tmp_list != nullptr){
// 			tmp.push_back(tmp_list->val);
// 			tmp_list = tmp_list->next;
// 		}
// 		int n = tmp.size();
// 		vector<bool> lianxu(n,false);
// 		for(int i = 0;i < nums.size();i++){
// 			for(int j = 0;j < n;j++){
// 				if(tmp[j] == nums[i])
// 					lianxu[j] = true;
// 			}
// 		}
// 		// PrintVector(tmp);
// 		PrintVector(lianxu);
// 		return -1;
//     }
// };


class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
		unordered_set<int> set(nums.begin(),nums.end());
		// PrintUnorder_Set(set);
		bool flag = false;
		int res = 0;
		while(head != nullptr){
			if(set.count(head->val)){
				if(!flag){
					flag = true;
					res++;
				}
			}else{
				flag = false;
			}
			head = head->next;
		}
		return res;
    }
};


int main(){
	Solution solution;
	// vector<int> value1 = {0,10,9,6};
	// ListNode* head = CreateListNode(value1);
	// vector<int> nums = {0,6,10};
	
	vector<int> value1 = {0,1,2,3,4};
	ListNode* head = CreateListNode(value1);
	vector<int> nums = {0,3,1,4};

	// vector<int> value1 = {0,1,2};
	// ListNode* head = CreateListNode(value1);
	// vector<int> nums = {0,2};
	auto ans = solution.numComponents(head,nums);
		
	cout << ans << endl;
	return 0;
}
