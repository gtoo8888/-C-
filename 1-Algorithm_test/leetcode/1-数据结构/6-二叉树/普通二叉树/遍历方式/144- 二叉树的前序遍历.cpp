#include <iostream> 
using namespace std;
#include <vector> 
#include <typeinfo> 
#include<queue>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	void preorder(TreeNode* root,vector<int> &res){
		if(root == nullptr)
			return;
		res.push_back(root -> val);
		preorder(root -> left,res);
		preorder(root -> right,res);
	}
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> ret;
    	preorder(root,ret);
		return ret;
    }
};


int main(){
	Solution sol;
	vector<int> ans;

	vector<int>data = { 1,null,2,3,null};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
		
//	ans = sol.preorderTraversal(root);
	PrintVector(data);
	
	return 0;
}



