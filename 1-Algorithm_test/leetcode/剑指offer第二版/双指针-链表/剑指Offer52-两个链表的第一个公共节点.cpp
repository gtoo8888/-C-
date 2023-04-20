#include <algorithm> 
#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* tmpA = headA;
//         ListNode* tmpB = headB;
//         int lenA = 0,lenB = 0;
//         while(tmpA != nullptr){
//             tmpA = tmpA->next;
//             lenA++;
//         }
//         while(tmpB != nullptr){
//             tmpB = tmpB->next;
//             lenB++;
//         }
//         int sub = max(lenA,lenB) - min(lenA,lenB);
//         if(lenA < lenB){
//             tmpA = headB;
//             tmpB = headA;
//         }else{
//             tmpA = headA;
//             tmpB = headB;
//         }
//         // printf("%d %d %d\n",sub,lenA,lenB);
//         while(sub--){
//             tmpA = tmpA->next;
//         }
        
//         // PrintListNode(tmpA);
//         // PrintListNode(tmpB);
//         while(tmpA != nullptr || tmpB != nullptr){
//             if(tmpA == tmpB)
//                 return tmpA;
//             tmpA = tmpA->next;
//             tmpB = tmpB->next;
//         }
//         return nullptr;        
//     }
// };



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while(tmpA != tmpB){
            tmpA = tmpA != nullptr ? tmpA->next : tmpB;
            tmpB = tmpB != nullptr ? tmpB->next : tmpA;
        }
        return tmpA;        
    }
};


int main(){
	Solution sol;
	vector<int> value1 = {4,1,8,4,5};
	ListNode* headA = CreateListNode(value1);
	vector<int> value2 = {5,0,1,8,4,5};
	ListNode* headB = CreateListNode(value2 );
	
    // 需要自己构造相交的链表，实际是无法测试的
    // 仅仅做保存代码使用
	auto ans = sol.getIntersectionNode(headA,headB);
	
	PrintListNode(ans);
	return 0;
}
