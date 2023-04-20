#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class MaxQueue {
	int que[200000];
	int begin = 0,end = 0;
public:
    MaxQueue() {

    }
    
    int max_value() {
		int ans = -1;
		for(int i = begin;i != end;i++){
			ans = max(ans,que[i]);
		}
		return ans;
    }
    
    void push_back(int value) {
		que[end++] = value;
    }
    
    int pop_front() {
		if(begin == end)
			return -1;
		que[++begin] = 0;
    }
};


int main(){
	MaxQueue* obj = new MaxQueue();
	obj->push_back(1);
	obj->push_back(2);
	printf("%d\n",obj->max_value());
	printf("%d\n",obj->pop_front());
	printf("%d\n",obj->max_value());
	return 0;
}
