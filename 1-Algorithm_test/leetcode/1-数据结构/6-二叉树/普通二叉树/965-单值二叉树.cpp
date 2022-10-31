#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
		int num = root->val;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			int len = que.size();
			for(int i = 0;i < len;i++){
				TreeNode* tmp = que.front();
				que.pop();
				if(tmp->val != num)
					return false;
				if(tmp->left != nullptr)
					que.push(tmp->left);
				if(tmp->right != nullptr)
					que.push(tmp->right);
			}
		}
		return true;
    }
};


int main() {
	Solution solution;
	// vector<int> data = {1,1,1,1,1,null,1};
	vector<int> data = {1};
	TreeNode* root = CreateBinaryTree(data);
	
	PrePrint(root);
	cout << endl;
	auto ans = solution.isUnivalTree(root);
	
	cout << ans << endl;
	
	return 0;
}



