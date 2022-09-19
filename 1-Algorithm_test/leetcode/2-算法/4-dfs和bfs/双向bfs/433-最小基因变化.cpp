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

// bfs���
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
		int n = bank.size();
		unordered_set<string> map;	// ���������ɹ�ϣ��
		unordered_set<string> visited;	// ����仯���Ļ���
		for(int i = 0;i < n;i++){
			map.emplace(bank[i]);
		}
		if(start == end)	// ����һ����ֱ�ӷ���
			return 0;
		if(!map.count(end))	// ����ɱ仯������û����Ҫ�Ľ��
			return -1;
		char dis[4] = {'A','C','G','T'};
		queue<string> que;	// �ö��н���bfs
		que.push(start);
		int step = 1;
		while(!que.empty()){
			int len = que.size();
			for(int i = 0;i < len;i++){
				string cur = que.front();
				que.pop();
				for(int j = 0;j < 8;j++){	// �������й̶���8,Ҳ���Ƕ�ÿһ������һ��һ������һ��
					for(int k = 0;k < 4;k++){	// ����ת�����ĸ�����						
						if(dis[k] != cur[j]){	// ����任��������������ԭ���Ļ���һ�������н��������ж�
							// printf("%c %c\n",cur[j],dis[k]);
							string next = cur;
							next[j] = dis[k];	// �½�һ���ַ�������������仯��ģ�Ȼ������ַ��滻��
							// cout << next << endl;
							if(!visited.count(next) && map.count(next)){	
							// ����仯����ַ�����û�б��������������ڻ�������棬��ô�ʹ浽��������
								if(next == end)	// ����仯�������ǽ���ˣ��Ǿ�ֱ�Ӵ�������
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



