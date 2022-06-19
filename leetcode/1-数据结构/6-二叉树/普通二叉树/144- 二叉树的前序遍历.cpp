#include <iostream> 
using namespace std;
#include <vector> 
#include <typeinfo> 
#include<queue>
#define null 0xffff

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


TreeNode* CreateTree(vector<int>Data) {
	vector<string>str_data(Data.size(), "");
	for (int i = 0; i < Data.size(); i++) {
		if (Data[i] != null)
			str_data[i] = to_string(Data[i]);
		else
			str_data[i] = "null";
	}
	queue<TreeNode*>q;
	TreeNode* head = new TreeNode(stoi(str_data[0]));
	q.push(head);
	int i = 1;
	while (i < str_data.size()) {
		TreeNode* tmp = q.front();
		q.pop();
		if (str_data[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			tmp->left = new_node;
			q.push(new_node);
		}
		i++;
		if (str_data[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			tmp->right = new_node;
			q.push(new_node);
		}
		i++;
	}
	return head;
}


class Solution {
public:
	void preorder(TreeNode* root,vector<int> &res){
		if(root == nullptr)
			return;
		res.push_back(root -> val);
		preorder(root -> left,res);
		preorder(root -> right,res);
	}
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> ret;
    	preorder(root,ret);
		return ret;
    }
};


int main(){
	Solution sol;
	vector<int> ans;

	vector<int>data = { 1,null,2,3,null};
	TreeNode* root = NULL;
	root = CreateTree(data);
		
//	ans = sol.preorderTraversal(root);
	printVector(data);
	
	return 0;
}



