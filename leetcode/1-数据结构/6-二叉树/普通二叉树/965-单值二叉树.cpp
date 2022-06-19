#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#define null 0xffff



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

TreeNode* CreateTree(vector<int> data) {
	vector<string> str_date(data.size());
	for(int i = 0;i < data.size();i++) {
		if(data[i] != null) str_date[i] = to_string(data[i]);
		else str_date[i] = "null";
	}
	
	queue<TreeNode*> que;
	TreeNode* root = new TreeNode(stoi(str_date[0]));
	que.push(root);
	int i = 1;
	while(i < str_date.size()) {
		TreeNode* temp = que.front();que.pop();
		if(str_date[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_date[i]));
			temp->left = new_node;
			que.push(new_node);
		}i++;
		if(str_date[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_date[i]));
			temp->right = new_node;
			que.push(new_node);
		}i++;
	}
	return root;
	
}

void PrePrint(TreeNode* root) {
	if(root == nullptr)	return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
}

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
	TreeNode* root = CreateTree(data);
	
	PrePrint(root);
	cout << endl;
	auto ans = solution.isUnivalTree(root);
	
	cout << ans << endl;
	
	return 0;
}



