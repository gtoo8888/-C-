#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int countNodes(TreeNode* root) {
    	if(root == nullptr)	
    		return 0;
    		
    	queue<TreeNode*> que;
		que.push(root);
		int ans = 0;
		while(!que.empty()) {
			int size = que.size();
			for(int i = 0;i < size;i++) {
				ans++;
				TreeNode* temp = que.front();que.pop();
				if(temp->left)  que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		return ans;
    }
};


int main() {
	Solution solution;
	int ans;
	vector<int> data = {};
	TreeNode* root = CreateBinaryTree(data);
	
//	PrePrint(root);
	ans = solution.countNodes(root);
	
	cout << ans << endl;
	
	return 0;
}



