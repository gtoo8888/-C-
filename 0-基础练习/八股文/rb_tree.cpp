#include <iostream> 
#include <functional>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
#include "rb_tree.h"


// 1. 将当前节点的右子节点作为旋转后的根节点。
// 2. 将当前节点的右子节点的左子节点作为当前节点的右子节点。
// 3. 如果当前节点是其父节点的左子节点，则将当前节点的右子节点替换当前节点的位置，并将当前节点作为其右子节点的左子节点。
// 4. 如果当前节点是其父节点的右子节点，则将当前节点的右子节点替换当前节点的位置，并将当前节点作为其右子节点的右子节点。
// void leftRotate(Node* &root, Node* node) {
//     Node* rightChild = node->right;  // 将当前节点的右子节点作为旋转后的根节点
//     node->right = rightChild->left;  // 将当前节点的右子节点的左子节点作为当前节点的右子节点
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

// root 是红黑树的根节点，node 是需要进行左旋操作的节点
void Rb_tree::left_rotate(Rb_tree_node* &root, Rb_tree_node* node){
    Rb_tree_node* rightChild = node->right; // 将当前节点的右子节点作为旋转后的根节点
    node->right = rightChild->left;         // 将当前节点的右子节点的左子节点作为当前节点的右子节点
    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;  // 如果当前节点是其父节点的左子节点，则将当前节点的右子节点替换当前节点的位置，并将当前节点作为其右子节点的左子节点
    } else {
        node->parent->right = rightChild;  // 如果当前节点是其父节点的右子节点，则将当前节点的右子节点替换当前节点的位置，并将当前节点作为其右子节点的右子节点
    }
    rightChild->left = node;
    node->parent = rightChild;
}






int main()
{
	freopen("RB_tree_test.txt", "r" , stdin);
    int n;
    cin >> n;
    int val;
    Rb_tree RbTree;
    for(int i = 0;i < n;i++){
        int val;
        cin >> val;
        // RbTree.insert(val);
    }

    Rb_tree_node testRBtree;
    printf("%d\n",testRBtree.color);

    cout << n << endl;
    return 0;
}

