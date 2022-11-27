#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> que;
		
		if(root != nullptr) {
			que.push(root->left);
			que.push(root->right);
		}
		while(!que.empty()) {
			TreeNode* left_node = que.front();que.pop();
			TreeNode* right_node = que.front();que.pop();
//			cout << left_node->val << " "  << right_node->val << endl;
			if((left_node == nullptr) && (right_node == nullptr))
				continue;	
				
			if(left_node == nullptr)
				return false;
			if(right_node == nullptr)
				return false;
			if(left_node->val != right_node->val)
				return false;
	
			que.push(left_node->left);
			que.push(right_node->right);
			
			que.push(left_node->right);
			que.push(right_node->left);
		}
		return true;
    }
};

void PrePrint(TreeNode* root) {
	if(root == nullptr) return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
	return;
}

int main(){
	Solution solution;
	bool ans;

	vector<int> data = {1,2,2,null,4,null,4};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
//	PrePrint(root);

	ans = solution.isSymmetric(root);
	
	PrintBool(ans);
	
	return 0;
}














