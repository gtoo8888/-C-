#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <iomanip> 
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> que;
		
		if(root != nullptr)	
			que.push(root);
		
		while(!que.empty()){
			int size = que.size(); 
			// 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
			vector<int> temp;//为了存放每层的数据 
			
			for(int i = 0;i < size;i++){
				TreeNode* node_temp = que.front();//将需要的结点读取出来后就pop掉 
				que.pop();
				temp.push_back(node_temp->val);//节点的值输入每一层的向量中 
				
				if(node_temp->left != nullptr)
					que.push(node_temp->left);
				if(node_temp->right != nullptr)
					que.push(node_temp->right);
			}
			
			ans.push_back(temp);
		}
		return ans;		
    }
};




int main(){
	Solution solution;
	vector<vector<int>> ans;

	vector<int> data = {6,4,7,1,3,5,8};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
			
	ans = solution.levelOrder(root);
	PrintVVector(ans);
	
	return 0;
}



