#include <iostream> 
using namespace std;
#include <vector> 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
struct Person{
	int val;
	Person *left;
	Person *right;
	Person(int x, Person *left, Person *right) : val(x), left(left), right(right) {}
};


TreeNode* getTreeNode(vector<int>str){
	TreeNode* root = new TreeNode(str[0]);
	vector<TreeNode*> vecs;
	vecs.push_back(root);
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i]!=NULL)
		{
			TreeNode* n1 = new TreeNode(str[i]);
			if (i % 2 == 1) //left
			{
			 	vecs[(i - 1) / 2]->left = n1;
			}
			else
			{
				vecs[(i - 1) / 2]->right = n1;
			}
			vecs.push_back(n1);
		}
		else
		{
			vecs.push_back(nullptr);
		}
	}
	return root;
}


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> ans;
		return ans;
    }
};

void printVector(cons vector<int> &v){
	for(vector<int>::iterotor)
}

int main(){
	Solution sol;
	vector<int> v_sol;
	TreeNode* test;
	
	vector<int>s = { 1, 2, NULL, 3£¬4 };
	TreeNode* root=getTreeNode(s);
	
//	v_sol = sol.preorderTraversal(test);
	
	TreeNode TreeNode_test(1,NULL,NULL,3);
//	Person p1(1,NULL,NULL);
	return 0;
}



