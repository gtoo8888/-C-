#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool is_leaf;
    vector<int> keys;
    vector<Node*> pointers;

    Node(bool is_leaf) {
        this->is_leaf = is_leaf;
    }
};

class BPlusTree {
private:
    Node* root;

    Node* find_leaf(int key) {
        Node* cur_node = root;
        while (!cur_node->is_leaf) {
            int i;
            for (i = 0; i < cur_node->keys.size(); i++) {
                if (key < cur_node->keys[i]) {
                    break;
                }
            }
            cur_node = cur_node->pointers[i];
        }
        return cur_node;
    }

    void insert_into_leaf(Node* leaf_node, int key) {
        int i;
        for (i = 0; i < leaf_node->keys.size(); i++) {
            if (key < leaf_node->keys[i]) {
                break;
            }
        }
        leaf_node->keys.insert(leaf_node->keys.begin() + i, key);
    }

    void insert_into_parent(Node* left_node, Node* right_node, int key) {
        Node* parent_node = left_node->pointers[0];
        if (parent_node == NULL) {
            parent_node = new Node(false);
            parent_node->pointers.push_back(left_node);
            left_node->pointers[0] = parent_node;
            root = parent_node;
        }
        int i;
        for (i = 0; i < parent_node->pointers.size(); i++) {
            if (parent_node->pointers[i] == left_node) {
                break;
            }
        }
        if (parent_node->keys.size() >= 2) {
            insert_into_parent(parent_node, new Node(false), parent_node->keys[1]);
        }
        Node* new_right_node = new Node(left_node->is_leaf);
        new_right_node->keys = vector<int>(right_node->keys.begin() + 1, right_node->keys.end());
        new_right_node->pointers = vector<Node*>(right_node->pointers.begin() + 1, right_node->pointers.end());
        right_node->keys.erase(right_node->keys.begin() + 1, right_node->keys.end());
        right_node->pointers.erase(right_node->pointers.begin() + 1, right_node->pointers.end());
        parent_node->keys.insert(parent_node->keys.begin() + i, key);
        parent_node->pointers.insert(parent_node->pointers.begin() + i + 1, new_right_node);
    }

public:
    BPlusTree() {
        root = new Node(true);
    }

    void insert(int key) {
        Node* leaf_node = find_leaf(key);
        insert_into_leaf(leaf_node, key);
        if (leaf_node->keys.size() >= 2) {
            insert_into_parent(leaf_node, new Node(true), leaf_node->keys[1]);
        }
    }

    void print() {
        vector<Node*> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            Node* cur_node = nodes.front();
