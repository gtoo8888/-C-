#include <iostream> 
#include <functional>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// root 是红黑树的根节点，node 是需要进行左旋操作的节点
// void Rb_tree::left_rotate(Rb_tree_node* &root, Rb_tree_node* node){
//     Rb_tree_node* rightChild = node->right; // 将当前节点的右子节点作为旋转后的根节点
//     node->right = rightChild->left;         // 将当前节点的右子节点的左子节点作为当前节点的右子节点
//     if (rightChild->left != nullptr) {
//         rightChild->left->parent = node;
//     }
//     rightChild->parent = node->parent;
//     if (node->parent == nullptr) {
//         root = rightChild;
//     } else if (node == node->parent->left) {
//         node->parent->left = rightChild;  // 如果当前节点是其父节点的左子节点，则将当前节点的右子节点替换当前节点的位置，并将当前节点作为其右子节点的左子节点
//     } else {
//         node->parent->right = rightChild;  // 如果当前节点是其父节点的右子节点，则将当前节点的右子节点替换当前节点的位置，并将当前节点作为其右子节点的右子节点
//     }
//     rightChild->left = node;
//     node->parent = rightChild;
// }


// 左旋
void left_rotate(TreeNode* &root, TreeNode* x){
    TreeNode* originRoot = root;
    TreeNode* newRoot = root->right;        // 取当前节点的右子节点为旋转后的根节点
    TreeNode* tempBranch = newRoot->left;   // 将当前节点的右子节点的左子节点作为当前节点的右子节点
    newRoot->left = originRoot;         // 将当前节点作为旋转后的根节点的左子节点
    originRoot->right = tempBranch;
    root = newRoot; // 旋转后的根节点替换当前节点的位置             
}


// 右旋
void right_rotate(TreeNode* &root, TreeNode* x){
    TreeNode* originRoot = root;
    TreeNode* newRoot = root->left;        // 取当前节点的右子节点为旋转后的根节点
    TreeNode* tempBranch = newRoot->right;   // 将当前节点的右子节点的左子节点作为当前节点的右子节点
    newRoot->right = originRoot;         // 将当前节点作为旋转后的根节点的左子节点
    originRoot->left = tempBranch;
    root = newRoot; // 旋转后的根节点替换当前节点的位置             
}



void test01(TreeNode* root){
    PrintTreeLevelOrder(root);
    left_rotate(root,root->right);
    PrintTreeLevelOrder(root);
}

void test02(TreeNode* root){
    PrintTreeLevelOrder(root);
    right_rotate(root,root->left);
    PrintTreeLevelOrder(root);
}


int main(){
    vector<int> data = {10,8,20,null,null,15,30};
	TreeNode* root = CreateBinaryTree(data);
    test01(root);

    vector<int> data2 = {10,20,8,15,30};
	TreeNode* root2 = CreateBinaryTree(data);
    test02(root2);
    return 0;
}

