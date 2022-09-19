#include <iostream> 
#include <vector>
#include <queue>
#include <string>
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

void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
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


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

    }
};

void PrePrint(TreeNode* root) {
    if(root == NULL) return;
    
    PrePrint(root->left);
	cout << root->val << " ";
    PrePrint(root->right);
	return;
}


int main(){
	Solution solution;
	vector<int> data = {2,1,3};
	TreeNode* root = NULL;
	root = CreateTree(data);
	// TreeNode* p = 1;
	PrePrint(root);
			
	// auto ans = solution.inorderSuccessor(root,p);
	// PrintBool(ans);
	
	return 0;
}



