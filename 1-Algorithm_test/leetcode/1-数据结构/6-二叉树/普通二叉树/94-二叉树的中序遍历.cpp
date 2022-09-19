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

//Êä³övector 
void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
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
	void InOrder(TreeNode* root,vector<int> &ans){
		if(root == nullptr)
			return;
		InOrder(root->left,ans);
		ans.push_back(root->val);
		InOrder(root->right,ans);
	}
	
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> ans;
    	InOrder(root,ans);
    	return ans;
    }
};

int main(){
	Solution solution;
	vector<int> ans;

	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateTree(data);
			
	ans = solution.inorderTraversal(root);
	printVector(ans);
	
	return 0;
}



