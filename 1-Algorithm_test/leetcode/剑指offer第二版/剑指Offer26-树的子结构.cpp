#include <iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	bool help(TreeNode* A, TreeNode* B){
		if(B == nullptr)
			return true;
		if(A == nullptr || A->val != B->val)
			return false;
		return help(A->left,B->left) && help(A->right,B->right);
	}

    bool isSubStructure(TreeNode* A, TreeNode* B) {
		if(A == nullptr || B == nullptr)
			return false;
		return help(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};

int main(){
	Solution solution;
	// vector<int> data1 = {3,4,5,1,2,null,null};
	// TreeNode* rootA = NULL;
	// rootA = CreateBinaryTree(data1);	
	// vector<int> data2 = {4,1,null};
	// TreeNode* rootB = NULL;
	// rootB = CreateBinaryTree(data2);	


	// vector<int> data1 = {3,4,5,1,2,null,null};
	// TreeNode* rootA = NULL;
	// rootA = CreateBinaryTree(data1);	
	// vector<int> data2 = {3,1,null};
	// TreeNode* rootB = NULL;
	// rootB = CreateBinaryTree(data2);	


	// vector<int> data1 = {3,4,5,1,2,null,null};
	// TreeNode* rootA = NULL;
	// rootA = CreateBinaryTree(data1);	
	// vector<int> data2 = {};
	// TreeNode* rootB = NULL;
	// rootB = CreateBinaryTree(data2);	

	// vector<int> data1 = {4,2,3,4,5,6,7,8,9};
	// TreeNode* rootA = NULL;
	// rootA = CreateBinaryTree(data1);	
	// vector<int> data2 = {4,8,9};
	// TreeNode* rootB = NULL;
	// rootB = CreateBinaryTree(data2);	
	

	vector<int> data1 = {1,0,1,-4,-3};
	TreeNode* rootA = NULL;
	rootA = CreateBinaryTree(data1);	
	vector<int> data2 = {1,-4};
	TreeNode* rootB = NULL;
	rootB = CreateBinaryTree(data2);

	auto ans = solution.isSubStructure(rootA,rootB);
	PrintBool(ans);

	return 0;
}



