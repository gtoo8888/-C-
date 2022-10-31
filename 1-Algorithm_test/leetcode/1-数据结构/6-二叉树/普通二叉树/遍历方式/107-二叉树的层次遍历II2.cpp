#include <iostream> 
#include <vector> 
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;
		
		if(root != nullptr)
			q.push(root);
		while(!q.empty()){
			int size = q.size();
			vector<int> vec;
			
			for(int i = 0;i < size;i++){
				TreeNode* temp = q.front();
				q.pop();
				vec.push_back(temp->val);
				if(temp->left != nullptr)
					q.push(temp->left);
				if(temp->right != nullptr)
					q.push(temp->right);
			}
			ans.push_back(vec);
		}
		reverse(ans.begin(),ans.end());
//			printVVector(ans);
		return ans;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> ans;
	
		
	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
	
	ans = solution.levelOrderBottom(root);
	
	PrintVVector(ans);
	
	return 0;
}





