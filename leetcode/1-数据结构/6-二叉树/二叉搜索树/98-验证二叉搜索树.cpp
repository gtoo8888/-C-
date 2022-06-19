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
	vector<int> vec;
	void traversal(TreeNode* root) {
		if(root == NULL) return;
		traversal(root->left);
		vec.push_back(root->val);
		traversal(root->right);
	}

    bool isValidBST(TreeNode* root) {
		vec.clear();
		traversal(root);//前序遍历，转换成数组，需要是递增的

		// printVector(vec);

		for(int i = 1;i < vec.size();i++) {
			if(vec[i] <= vec[i-1])
				return false;
		}
        return true;
    }
};

void PrePrint(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    PrePrint(root->left);
    PrePrint(root->right);
	return;
}


int main(){
	Solution solution;
	vector<int> data = {5,1,4,null,null,3,6};
	TreeNode* root = NULL;
	root = CreateTree(data);
			
	auto ans = solution.isValidBST(root);
	PrintBool(ans);
	
	return 0;
}



