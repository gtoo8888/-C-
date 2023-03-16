#include<iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
#include "BPlusTree.h"

void BPlusTree::insert(int key){
    BPlusTreeNode* node = find_leaf_node(key);
}



int main(){
    BPlusTree bptree(4);
    bptree.insert(1);
    bptree.insert(2);
    bptree.insert(3);
    bptree.print();
	return 0;
}

