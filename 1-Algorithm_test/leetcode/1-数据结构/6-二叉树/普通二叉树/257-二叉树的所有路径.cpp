#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// path不能传引用，不然会被随意修改
class Solution {
public:
	void dfs(TreeNode* node,string path,vector<string>& vsp){
		if(node != nullptr){
			path += to_string(node->val);
			if(node->left == nullptr && node->right == nullptr){
				vsp.push_back(path);
			}else{
				path += "->";
				dfs(node->left,path,vsp);
				dfs(node->right,path,vsp);
			}
		}
	}
    vector<string> binaryTreePaths(TreeNode* root) {
		// PrintTreeLevelOrder(root);
		vector<string> ans;
		dfs(root,"",ans);
		return ans;
    }	
};


int main() {
	Solution solution;
	// vector<int> data = {1,2,3,null,5};
	// TreeNode* root = CreateBinaryTree(data);
	
	vector<int> data = {8,3,10,1,6,null,14,null,null,4,7,13,null};
	TreeNode* root = CreateBinaryTree(data);
	auto ans = solution.binaryTreePaths(root);
	
	PrintVector(ans);
	
	return 0;
}



