#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintQueue(queue<string> q){
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
	cout << endl; 
}

// bfs解决
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
		int n = bank.size();
		unordered_set<string> map;	// 将结果储存成哈希表
		unordered_set<string> visited;	// 储存变化过的基因
		for(int i = 0;i < n;i++){
			map.emplace(bank[i]);
		}
		if(start == end)	// 两个一样，直接返回
			return 0;
		if(!map.count(end))	// 如果可变化序列中没有想要的结果
			return -1;
		char dis[4] = {'A','C','G','T'};
		queue<string> que;	// 用队列进行bfs
		que.push(start);
		int step = 1;
		while(!que.empty()){
			int len = que.size();
			for(int i = 0;i < len;i++){
				string cur = que.front();
				que.pop();
				for(int j = 0;j < 8;j++){	// 基因序列固定是8,也就是对每一个基因一个一个搜索一下
					for(int k = 0;k < 4;k++){	// 可以转换的四个基因						
						if(dis[k] != cur[j]){	// 如果变换出来的这个基因和原来的基因不一样，进行接下来的判断
							// printf("%c %c\n",cur[j],dis[k]);
							string next = cur;
							next[j] = dis[k];	// 新建一个字符串，用来储存变化后的，然后将这个字符替换掉
							// cout << next << endl;
							if(!visited.count(next) && map.count(next)){	
							// 如果变化后的字符串，没有被遍历过，并且在基因库里面，那么就存到队列里面
								if(next == end)	// 如果变化出来就是结果了，那就直接存下来了
									return step;
								que.emplace(next);
								visited.emplace(next);
							}
						}
					}
					// putchar('\n');
				}
				// putchar('\n');
			}
			// PrintQueue(que);
			step++;
		}
		return -1;
    }
};


	
int main() {
	Solution solution;
	string start = "AACCGGTT";
	string end = "AAACGGTA";
	vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
	
	auto ans = solution.minMutation(start,end,bank);
	
	cout << ans << endl;
	
	return 0;
}



