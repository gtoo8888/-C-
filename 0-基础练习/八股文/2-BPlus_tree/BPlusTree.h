#include<iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 它在文件系统中很有用。它适合在磁盘等直接存取设备上进行动态表查找
// B+树(B+ Tree)采用平衡树结构，其中每个叶子结点到根的路径长度相同，每个非叶子结点有 m/2向下取整~m 个孩子结点，其中m为B+树的阶数。

// B+ 树是一种高效的数据结构，通常用于数据库、文件系统和操作系统等需要存储和查询大量数据的应用中。以下是 B+ 树的主要特点：
// 多路搜索树：B+ 树是一种多路搜索树，每个节点可以有多个子节点。相比于二叉搜索树，B+ 树可以在同样的高度下存储更多的数据，从而减少磁盘访问次数，提高查询效率。
// 度数：B+ 树的度数是一个重要的参数，它决定了每个节点可以存储的最大关键字数量。B+ 树的内部节点可以有多于两个子节点，叶子节点可以存储多个关键字和指向数据的指针。
// 叶子节点链表：B+ 树的所有叶子节点形成一个有序链表，可以用于快速范围查询。
// 高度平衡：B+ 树是一种自平衡树，可以保持树的高度相对平衡，从而保证查询效率。
// 数据顺序存储：B+ 树中的每个节点都按照一定的顺序存储数据，从而可以通过顺序访问磁盘上的数据块来提高查询效率。
// 总的来说，B+ 树具有高效的查询性能、范围查询能力、自平衡能力和顺序访问能力等特点，因此被广泛应用于需要存储和查询大量数据的应用中。


// 创建
// 查找
// 范围查询
// 插入
// 删除
// 旋转，重新平衡;
// 显示
// 检查

enum Node_Type{
    NODE_TYPE_ROOT = 1,
    NODE_TYPE_INTERNAL,     // 内部及诶单
    NODE_TYPE_LEAF,         // 叶子节点
};
#define MAX_KEYS 4 // 最多存储键值对个数

// B+树每个节点的数据结构
class BPlusTreeNode{
public:
    int key_count;
    int keys[MAX_KEYS];
    BPlusTreeNode* children[MAX_KEYS+1];
    bool is_leaf;
    BPlusTreeNode* next;

    BPlusTreeNode() : key_count(0),is_leaf(true),next(nullptr){
        for(int i = 0;i <= MAX_KEYS;i++)
            children[i] = nullptr;
    }

    bool is_full() const { // 不会修改成员变量
        return key_count == MAX_KEYS;
    }
};

class BPlusTree{
public:
    BPlusTree(int order) : m_order(order){
        m_root = new BPlusTreeNode();
    }

    void insert(int key);

    void print();
private:
    int m_order;
    BPlusTreeNode* m_root;

    BPlusTreeNode* find_leaf_node(int key);
    void insert_into_leaf()


};


