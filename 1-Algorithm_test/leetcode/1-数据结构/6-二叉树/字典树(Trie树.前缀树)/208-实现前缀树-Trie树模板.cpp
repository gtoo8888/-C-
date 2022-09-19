#include <iostream> 
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define null 0xfffff 


void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}


class Trie {
private:
    bool isEnd;
    Trie* next[26];

public:
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }

    // 向 Trie 中插入一个单词 word    
    void insert(string word) {
        Trie* node = this;
        for(auto c : word){
            if(node->next[c-'a'] == NULL)
                node->next[c-'a'] = new Trie();
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }

    // 查找 Trie 中是否存在单词 word
    bool search(string word) {
        Trie* node = this;
        for(auto c : word){
            node = node->next[c-'a'];
            if(node == NULL)
                return false;
        }
        return node->isEnd;
    }
    
    // 判断 Trie 中是或有以 prefix 为前缀的单词
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto c : prefix){
            node = node->next[c-'a'];
            if(node == NULL)
                return false;
        }
        return true;
    }
};

int main(){
	Trie* obj = new Trie();
    obj->insert("apple");
    PrintBool(obj->search("apple"));
    PrintBool(obj->search("app"));
    PrintBool(obj->startsWith("app")); 
    obj->insert("app");
    PrintBool(obj->search("app"));
	
	return 0;
}



