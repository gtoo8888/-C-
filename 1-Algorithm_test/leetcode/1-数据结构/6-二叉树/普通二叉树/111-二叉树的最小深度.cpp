#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int minDepth(TreeNode* root) {
    	if(root == nullptr)	
    		return 0;
    	
		queue<TreeNode*> que;
		que.push(root);
		int depth = 0;
		while(!que.empty()) {
			int size = que.size();
			depth++;
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				if(temp->left == nullptr && temp->right == nullptr)
					return depth;
				if(temp->left)   que.push(temp->left);
				if(temp->right)  que.push(temp->right);
			}
		}
		return depth;		
    }
};


int main() {
	Solution solution;
	int ans;
	vector<int> data = {2,null,3,null,4,null,5,null,6};
	TreeNode* root = CreateBinaryTree(data);
	
//	PrePrint(root);
	ans = solution.minDepth(root);
	
	cout << ans << endl;
	
	return 0;
}



