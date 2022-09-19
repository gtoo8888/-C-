#include<iostream>
#include<vector>
#include<string>
#include<queue>
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
void prePrint(TreeNode* Root) {//先序遍历
	if (Root == NULL) return;
	cout << Root->val << ',';
	prePrint(Root->left);
	prePrint(Root->right);
	return;
}
void postPrint(TreeNode* Root) {//后序遍历
	if (Root == NULL) return;
	postPrint(Root->left);
	postPrint(Root->right);
	cout << Root->val << ',';
	return;
}
void inPrint(TreeNode* Root) {//中序遍历
	if (Root == NULL) return;
	inPrint(Root->left);
	cout << Root->val << ',';
	inPrint(Root->right);
	return;
}
int main() {
	vector<int>Data = { 1,2,3,null,4,5,6,7,null };
	TreeNode* Root = NULL;
	Root = CreateTree(Data);
	cout << "PreOrder:" << endl;
	prePrint(Root);
	cout << endl << "InOrder:" << endl;
	inPrint(Root);
	cout << endl << "PostOrder:" << endl;
	postPrint(Root);

}
