#include <iostream> 
#include <vector>
#include <ctime>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
	ListNode* myList;

    Solution(ListNode* head) {
		srand((unsigned)time(NULL));
		myList = head;
    }
    
    int getRandom() {
		int list_len = 0;
		ListNode* tmp = myList;
		while(tmp != nullptr){
			tmp = tmp->next;
			list_len++;
		}
		// cout << list_len << endl;
		int random = rand()%list_len;
		ListNode* ans = myList;
		while(random--){
			ans = ans->next;
		}
		return ans->val;
	}
};

int main(){
	
	vector<int> v = {1,2,3,4,5};
	ListNode* head = new ListNode(v[v.size()-1]);
	for(int i = v.size()-1 - 1;i >= 0;i--){
		head = new ListNode(v[i],head);
	}

	PrintListNode(head);
	
 	Solution* obj = new Solution(head);

	vector<int> count(10,0);
	for(int i = 0;i < 10000;i++){
		count[obj->getRandom()]++;
		// cout << obj->getRandom() << endl;
	}

	PrintVector(count);
	return 0;
}
