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

        // ��������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
        int post_last = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(post_last);

        // cout << post_last <<  endl;
        // ����Ҷ�ӽڵ㣬ֻ��һ����ʱ������Ϸ�������ոռ����Ľ����
        if(postorder.size() == 1)
            return root;

        // �����������ͨ���и�ڵ��ҵ��и��λ��
        int i = 0;
        for(;i < inorder.size();i++) {
            if(inorder[i] == post_last)
                break;
        }

        // �и�����
        vector<int> leftInorder(inorder.begin(),inorder.begin() + i);
        vector<int> rightInorder(inorder.begin() + i + 1,inorder.end());

        // printVector(leftInorder);
        // printVector(rightInorder);

        // �����������һ��
        postorder.resize(postorder.size() - 1);

        // �и�����������������һ��������.end()��������
        vector<int> leftPostorder(postorder.begin(),postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),postorder.end());
        
        // printVector(leftPostorder);
        // printVector(rightPostorder);
        // cout << endl;

        //�������
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



