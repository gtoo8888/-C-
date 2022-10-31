#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	void InOrder(TreeNode* root,vector<int> &ans){
		if(root == nullptr)
			return;
		InOrder(root->left,ans);
		ans.push_back(root->val);
		InOrder(root->right,ans);
	}
	
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> ans;
    	InOrder(root,ans);
    	return ans;
    }
};

int main(){
	Solution solution;
	vector<int> ans;

	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
			
	ans = solution.inorderTraversal(root);
	PrintVector(ans);
	
	return 0;
}



