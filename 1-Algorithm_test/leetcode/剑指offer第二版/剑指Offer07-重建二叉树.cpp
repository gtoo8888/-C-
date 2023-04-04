#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
	//
    unordered_map<int,int> umap_inorder; // 后序遍历中，值->下标的关系

    // 递归
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,
    int pre_l,int pre_r,int in_l,int in_r){
		if(pre_l >= pre_r || in_l >= in_r)
			return nullptr;
        int root_index = pre_l;
        int root_val = preorder[pre_l];
        TreeNode* root = new TreeNode(root_val);

        int mid = umap_inorder[root_val];

        int tree_left = pre_l +1+ (mid-in_l);

        root->left = dfs(preorder,inorder,pre_l+1,tree_left,in_l,mid);
        root->right = dfs(preorder,inorder,tree_left,pre_r,mid+1,in_r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return nullptr;
        for(int i = 0;i < n;i++){
            umap_inorder[inorder[i]] = i;
        }
        TreeNode* root = dfs(preorder,inorder,0,n,0,n);
        return root;
    }
};


int main(){
	Solution sol;
	// vector<int> preorder = {3,9,20,15,7};
	// vector<int> inorder = {9,3,15,20,7};

	vector<int> preorder = {-1};
	vector<int> inorder = {-1};



	auto ans = sol.buildTree(preorder,inorder);
	
	PrintTreeLevelOrder(ans);
	return 0;
}
