#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class LRUNode{
public:
    int key,val;
    LRUNode* prev;
    LRUNode* next;
    LRUNode() : key(0), val(0), prev(nullptr), next(nullptr){}
    LRUNode(int key,int val) : key(key), val(val), prev(nullptr), next(nullptr){}
    LRUNode(int key,int val,LRUNode* prev,LRUNode* next) : key(key), val(val), prev(prev), next(next){}
};
// 哈希表+双向链表
// LRU策略 按照访问的时序来淘汰页面
class LRUCache {
public:
    unordered_map<int, LRUNode*> cache;
    LRUNode* head;  // 虚节点
    LRUNode* tail;  // 实际的第一个节点
    int size; // cache当前有多少项
    int capaticy; // cache总共能存多少项


    LRUCache(int capacity):capaticy(capacity), size(0) {
        this->head = new LRUNode();
        this->tail = new LRUNode();
        head->next = tail;
        tail->prev = head;
    }
    
    // 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        LRUNode* node = cache[key];
        moveToHead(node);
        return node->val;         
    }
    
    // 如果关键字已经存在，则变更其数据值 value
    // 如果关键字不存在，则向缓存中插入该组 key-value 
    // 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){ // 关键字存在
            LRUNode* node = cache[key];
            node->val = value; // 修改数据
            moveToHead(node); // 移动到头部
        }else{ // 关键字不存在
            LRUNode* node = new LRUNode(key,value);
            cache[key] = node;
            addToHead(node);
            
            size++;
            if(size > capaticy){
                LRUNode* removed = deletTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
    }

    // 还需要强化
    void addToHead(LRUNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeToHead(LRUNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(LRUNode* node) {
        removeToHead(node);
        addToHead(node);
    }

    LRUNode* deletTail(){
        LRUNode* node = tail->prev;
        removeToHead(node);
        return node;
    }
};
//  get 和 put 必须以 O(1) 的平均时间复杂度运行。



// 缓存是 {1=1, 2=2}，右边的表示最新的
int main() {
	LRUCache* lrucache = new LRUCache(2);
	lrucache->put(1, 1); // 缓存是 {1=1}
    lrucache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lrucache->get(1) << endl;    // 返回 1,查询了1，缓存是 {2=2, 1=1}
    lrucache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lrucache->get(2) << endl;    // 返回 -1 (未找到)，缓存是 {1=1, 3=3}
    lrucache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lrucache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lrucache->get(3) << endl;    // 返回 3
    cout << lrucache->get(4) << endl;    // 返回 4
	
	return 0;
}



