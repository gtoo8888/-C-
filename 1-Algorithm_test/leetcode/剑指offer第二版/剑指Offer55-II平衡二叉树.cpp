#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	int check(TreeNode* root){
		if(root == nullptr)
			return 0;
		return max(check(root->left),check(root->right)) + 1;
	}

    bool isBalanced(TreeNode* root) {
		if(root == nullptr)
			return true;
		else{
			int left_n = check(root->left);
			int right_n = check(root->right);
			return abs(left_n - right_n) <= 1 && isBalanced(root->left) 
							&& isBalanced(root->right); 
		}
    }
};


int main(){
	Solution sol;
	// vector<int> date = {3,9,20,null,null,15,7};
	// TreeNode* root = CreateBinaryTree(date);

	// vector<int> date = {1,2,2,3,3,null,null,4,4};
	// TreeNode* root = CreateBinaryTree(date);

	// vector<int> date = {1,null,2,null,3};
	// TreeNode* root = CreateBinaryTree(date);

	vector<int> date = {1,2,2,3,null,null,3,4,null,null,4}; // 还需要判断，每个节点是不是平衡的
	TreeNode* root = CreateBinaryTree(date);

	auto ans = sol.isBalanced(root);
	PrintBool(ans);
	return 0;
}
