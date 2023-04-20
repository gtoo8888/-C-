#include <iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 仿照257-二叉树的所有路径的思路，先把所有路径都找出来，然后再求最大值
// 迭代+O(n2)居然过了
// 时间:击败5.17%，空间击败5.18%
// class Solution {
// public:
// 	int ans = -1;
// 	// path不能传引用，不然会被随意修改
// 	void dfs(TreeNode* root,vector<int> path) {
// 		if(root == nullptr) //
// 			return;
// 		path.push_back(root->val);
// 		if(root->left == nullptr && root->right == nullptr){
// 			// PrintVector(path);
// 			for(int i = 0;i < path.size();i++){
// 				for(int j = i+1;j < path.size();j++){
// 					ans = max(ans,abs(path[i]-path[j]));
// 				}
// 			}
// 		}else{
// 			dfs(root->left,path);
// 			dfs(root->right,path);
// 		}
// 	}
//     int maxAncestorDiff(TreeNode* root) {
// 		// PrintTreeLevelOrder(root);
// 		vector<int> path;
// 		dfs(root,path);
// 		return ans;
//     }
// };


// 找到差值，就是需要找到最大值和最小值，将节点的值求出和他们的差值
// 在递归的时候同时维护一个最大和最小值
// 时间:击败100%，空间击败99.14%
class Solution {
public:
	int ans = -1;
	// path不能传引用，不然会被随意修改
	void dfs(TreeNode* root,int all_min,int all_max) {
		if(root == nullptr) 
			return;
		int now_node = root->val;
		all_min = min(all_min,now_node);
		all_max	= max(all_max,now_node);
		ans = max(ans,max(all_max-now_node,now_node-all_min));
		dfs(root->left,all_min,all_max);
		dfs(root->right,all_min,all_max);
	}

    int maxAncestorDiff(TreeNode* root) {
		dfs(root,root->val,root->val);
		return ans;
    }
};



int main() {
	Solution solution;
	int ans;
	vector<int> data = {8,3,10,1,6,null,14,null,null,4,7,13,null};
	// vector<int> data = {1,null,2,null,0,3,null};
	TreeNode* root = CreateBinaryTree(data);
	cout << solution.maxAncestorDiff(root) << endl;
	

	
	return 0;
}



