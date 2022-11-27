#include <iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		TreeNode* left = root;
		TreeNode* right = root;
		queue<TreeNode*> que;
		que.push(left);
		que.push(right);
		while(!que.empty()){
			left = que.front();que.pop();
			right = que.front();que.pop();
			if(left == nullptr && right == nullptr)
				continue;
			if((left == nullptr || right == nullptr) ||
				(left->val != right->val))
				return false;
			que.push(left->left);
			que.push(right->right);
			
			que.push(left->right);
			que.push(right->left);
		}
		return true;
    }
};

// 递归方法
// class Solution {
// public:
// 	bool check(TreeNode* left,TreeNode* right){
// 		if(left == nullptr && right == nullptr)
// 			return true;
// 		if(left == nullptr || right == nullptr)
// 			return false;
// 		return left->val == right->val && check(left->left,right->right) 
// 				&& check(left->right,right->left);
// 	}

//     bool isSymmetric(TreeNode* root) {
// 		return check(root,root);
//     }
// };

int main(){
	Solution solution;
	// vector<int> data = {1,2,2,3,4,4,3};
	// TreeNode* root = NULL;
	// root = CreateBinaryTree(data);

	// vector<int> data = {1,2,2,null,3,null,3};
	// TreeNode* root = NULL;
	// root = CreateBinaryTree(data);	

	vector<int> data = {1,2,3};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);	

	auto ans = solution.isSymmetric(root);
	PrintBool(ans);

	return 0;
}



