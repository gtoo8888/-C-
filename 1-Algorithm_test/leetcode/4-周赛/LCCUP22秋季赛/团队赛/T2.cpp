#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <iomanip> 
#include <algorithm>
using namespace std;
#define null 0xfffff 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//输出vector 
void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}




TreeNode* CreateTree(vector<int> data){
	vector<string> str_data(data.size()," ");
	for(int i = 0;i < data.size();i++){
		if(data[i] != null)
			str_data[i] = to_string(data[i]);
		else
			str_data[i] = "null";
	}
	
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(stoi(str_data[0]));
	q.push(root);
	int i = 1;
	while(i < str_data.size()){
		TreeNode* temp = q.front();
		q.pop();
		if(str_data[i] != "null"){
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->left = new_node;
			q.push(new_node);
		}
		i++;
		if(str_data[i] != "null"){
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->right = new_node;
			q.push(new_node);
		}
		i++;
	}
	return root;
}


class Solution {
public:
    TreeNode* expandBinaryTree(TreeNode* root) {
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
				
				if(node_temp->left != nullptr){
					if(node_temp->val != -1){
						TreeNode* zhuangshi = new TreeNode(-1,node_temp->left,nullptr);
						node_temp->left = zhuangshi;
						que.push(zhuangshi);
					}else{
						que.push(node_temp->left);
					}
				}
				if(node_temp->right != nullptr){
					if(node_temp->val != -1){
						TreeNode* zhuangshi = new TreeNode(-1,nullptr,node_temp->right);
						node_temp->right = zhuangshi;
						que.push(zhuangshi);
					}else{
						que.push(node_temp->right);
					}
				}
			}
			
		}
		return root;		
    }
};




int main(){
	Solution solution;

	vector<int> data = {7,5,6};
	TreeNode* root = NULL;
	root = CreateTree(data);
			
	auto ans = solution.expandBinaryTree(root);
	// printVVector(ans);
	
	return 0;
}



