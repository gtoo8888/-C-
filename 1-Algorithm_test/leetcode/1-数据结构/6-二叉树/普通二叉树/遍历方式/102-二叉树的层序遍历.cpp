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
			// ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()����Ϊque.size�ǲ��ϱ仯��
			vector<int> temp;//Ϊ�˴��ÿ������� 
			
			for(int i = 0;i < size;i++){
				TreeNode* node_temp = que.front();//����Ҫ�Ľ���ȡ�������pop�� 
				que.pop();
				temp.push_back(node_temp->val);//�ڵ��ֵ����ÿһ��������� 
				
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



