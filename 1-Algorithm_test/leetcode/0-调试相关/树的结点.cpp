#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

TreeNode *ConstructBinaryTree(vector<int>& vec, int len, int i){
    if (vec.empty() || len < 1) return nullptr;
    TreeNode *root = NULL;
    if (i < len && vec[i] != 'null'){
        root = new TreeNode(0);
        if (root == nullptr) return nullptr;
        root->val = vec[i];
        root->left = ConstructBinaryTree(vec, len, 2 * i + 1);
        root->right = ConstructBinaryTree(vec, len, 2 * i + 2);
    }
    return root;
}

//LeetCode���
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size=que.size();//����һ��Ҫ�ù̶���С��size����Ҫʹ��que.size(),��Ϊque.size�ǲ��ϱ仯��
            vector<int> vec;
            for(int i=0; i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

//����
int main(){
    TreeNode *root;
    //��������
    vector<int> data{3, 9, 20, 'null', 'null',  15, 7};
    root = ConstructBinaryTree(data, data.size(), 0);
    
    //�����Է���
    Solution s;
    vector<vector<int>>result = s.levelOrder(root);
    
    //�����ӡ
    for(int i=0;i<result.size();i++){
        for(int j=0; j<result[i].size();j++){
            cout<<result[i][j]<< " ";
            if(j==result[i].size()-1)
                cout<<endl;
        }
    }
    return 0;
}

