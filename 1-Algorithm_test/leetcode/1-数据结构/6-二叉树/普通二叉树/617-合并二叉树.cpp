#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#define null 0xffff
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		queue<TreeNode*> que;
		vector<int> ans;

		if(root1 != nullptr)	que.push(root1);
		if(root2 != nullptr)	que.push(root2);

		while(!que.empty()) {
			TreeNode* temp1 =  que.front();que.pop();
			TreeNode* temp2 =  que.front();que.pop();
			temp1->val += temp2->val;
			
			if(temp1->left && temp2->left){
				que1.push(temp1->left);
				que2.push(temp2->left);
			}else if(temp1->left){
				que1.push(temp1->left);
			}
			else if(temp2->left){
				que2.push(temp2->left);
			}

			
		}
		


    }
};


int main() {
	Solution solution;
	vector<int> data1 = {1,3,2,5,null};
	TreeNode* root1 = CreateBinaryTree(data1);
	vector<int> data2 = {2,1,3,null,4,null,7};
	TreeNode* root2 = CreateBinaryTree(data2);	

	// PrePrint(root2);


	auto ans = solution.mergeTrees(root1,root2);
	
	// printVector(ans);
	
	return 0;
}



