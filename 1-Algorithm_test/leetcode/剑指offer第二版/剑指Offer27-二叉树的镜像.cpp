#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};


int main(){
	Solution sol;
	vector<int> data = {4,2,7,1,3,6,9};
	TreeNode* root = CreateBinaryTree(data);
	

	auto ans = sol.mirrorTree(root);
	
	PrintTreeLevelOrder(ans);
	return 0;
}
