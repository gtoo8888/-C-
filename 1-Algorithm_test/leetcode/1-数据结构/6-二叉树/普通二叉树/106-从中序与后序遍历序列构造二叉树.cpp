#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0)
            return nullptr;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int post_last = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(post_last);

        // cout << post_last <<  endl;
        // 处理叶子节点，只有一个的时候就马上返回这个刚刚简历的结点了
        if(postorder.size() == 1)
            return root;

        // 在中序遍历中通过切割节点找到切割的位置
        int i = 0;
        for(;i < inorder.size();i++) {
            if(inorder[i] == post_last)
                break;
        }

        // 切割中序
        vector<int> leftInorder(inorder.begin(),inorder.begin() + i);
        vector<int> rightInorder(inorder.begin() + i + 1,inorder.end());

        // printVector(leftInorder);
        // printVector(rightInorder);

        // 舍弃后序最后一个
        postorder.resize(postorder.size() - 1);

        // 切割后序，由于舍弃了最后一个，所以.end()可以用了
        vector<int> leftPostorder(postorder.begin(),postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),postorder.end());
        
        // printVector(leftPostorder);
        // printVector(rightPostorder);
        // cout << endl;

        //进入遍历
        root->left = traversal(leftInorder,leftPostorder);
        root->right = traversal(rightInorder,rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        return traversal(inorder,postorder);
    }
};


int main() {
	Solution solution;
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder  = {9,15,7,20,3};

	TreeNode* ans = solution.buildTree(inorder,postorder);
	PrePrint(ans);
	
	return 0;
}



