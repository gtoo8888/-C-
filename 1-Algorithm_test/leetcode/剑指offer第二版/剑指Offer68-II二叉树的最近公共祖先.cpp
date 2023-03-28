#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == nullptr && right == nullptr) return nullptr;
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};


int main(){
	Solution sol;
	vector<int> nums = {3,5,1,6,2,0,8,null,null,7,4};
	TreeNode* root = CreateBinaryTree(nums);
	auto ans = sol.lowestCommonAncestor(root,root,root);
	return 0;
}
