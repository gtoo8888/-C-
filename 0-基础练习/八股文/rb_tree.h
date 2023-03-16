#include <iostream> 
#include <functional>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 红黑树有几种特性：
// 1.每个节点只能是红色或者黑色。
// 2.根节点必须是黑色。
// 3.红色的节点，它的叶节点只能是黑色。
// 4.从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点。



// 1. 根节点是黑色,叶节点是不存储数据的黑色空节点
// 2. 任何相邻的两个节点不能同时为红色
// 3. 任意节点到其可到达的叶节点间包含相同数量的黑色节点

// 没有一条路径的长度超过其他路径长度的2倍，红黑树是我们整个内存中最优的数据结构
// 插入和查找时候性能都很好


// 每个节点初始化为红色



// 左旋
// 右旋
// 删除

enum Rb_tree_color{
    _Rb_red = 0,
    _Rb_balck = 1
};


struct Rb_tree_node {
	int val;
    Rb_tree_color color;
	Rb_tree_node *left;
	Rb_tree_node *right;
    Rb_tree_node *parent;
	Rb_tree_node() : val(-1), color(_Rb_red), left(nullptr), right(nullptr) ,parent(nullptr){}
};


class Rb_tree {
public:
    Rb_tree_node *root;  //树根
    Rb_tree_node *nil; //外部节点, color: 黑色
    Rb_tree() {
        nil = new Rb_tree_node();
        root = nil;
    };

    void insertion(int val);    // 插入操作
    void deletion();    // 删除操作
    void search();  // 查找操作
    void maximum(); // 最大值操作
    void minimum(); // 最小值操作
    void predecessor(); // 前驱操作
    void successor(); // 后继操作
private:
    void left_rotate(Rb_tree_node* &root, Rb_tree_node* node);
    void right_rotate();
};




