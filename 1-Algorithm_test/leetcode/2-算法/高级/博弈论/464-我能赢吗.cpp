#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_set>
using namespace std;



// �ù�ϣ�����������״̬
// class Solution {
// public:
// 	bool dfs(unordered_set<int> set,int sum,int maxChoosableInteger, int desiredTotal){
// 		printUnordered_Set(set);
// 		for(int x : set){
// 			if(sum + x > desiredTotal)
// 				return true;
// 			unordered_set<int> change_set = set;
// 			change_set.erase(x);
// 			if(!dfs(change_set,sum,maxChoosableInteger,desiredTotal))
// 				return true;
// 		}
// 		return false;
// 	}
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
// 		unordered_set<int> set;
// 		for(int i = 0;i < maxChoosableInteger;i++){
// 			set.insert(i);
// 		}
// 		printUnordered_Set(set);
// 		return dfs(set,0,maxChoosableInteger,desiredTotal);
//     }
// };

// ״̬ѹ��
// class Solution {
// public:
// 	bool dfs(int state,int sum,int maxChoosableInteger, int desiredTotal){
// 		PrintBit(state);
// 		for(int x = 1;x <= maxChoosableInteger;x++){
// 			if((1 << x) & state)
// 				continue;
// 			if(sum + x >= desiredTotal)
// 				return true;
// 			if(!dfs((1 << x) | state,sum + x,maxChoosableInteger,desiredTotal))
// 				return true;
// 		}
// 		return false;
// 	}
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
// 		return dfs(0,0,maxChoosableInteger,desiredTotal);
//     }
// };

// ���仯����
// ���ص��Ե�ʱ��visted[]����һ��Ҫstatic�����������棬��Ȼ�����޷�����
// ����LeetCode��һ��Ҫ�������ڲſ���û������
// static int visted[1<<21] = {0};
// class Solution {
// public:
// 	bool dfs(int state,int sum,int maxChoosableInteger, int desiredTotal){
// 		if(visted[state] == 1)
// 			return true;
// 		if(visted[state] == 2)
// 			return false;
// 		// PrintBit(state);
// 		for(int x = 1;x <= maxChoosableInteger;x++){
// 			if((1 << x) & state)
// 				continue;
// 			if(sum + x >= desiredTotal){
// 				visted[state] = 1;
// 				return true;
// 			}
// 			if(!dfs((1 << x) | state,sum + x,maxChoosableInteger,desiredTotal)){
// 				visted[state] = 1;
// 				return true;
// 			}
// 		}
// 		visted[state] = 2;
// 		return false;
// 	}
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
// 		return dfs(0,0,maxChoosableInteger,desiredTotal);
//     }
// };


// ��һЩ��ǰ�жϣ���ȥ�������ų�������
static int visted[1<<21] = {0};
class Solution {
public:
	bool dfs(int state,int sum,int maxChoosableInteger, int desiredTotal){
		if(visted[state] == 1)
			return true;
		if(visted[state] == 2)
			return false;
		// PrintBit(state);
		for(int x = 1;x <= maxChoosableInteger;x++){
			if((1 << x) & state)
				continue;
			if(sum + x >= desiredTotal){
				visted[state] = 1;
				return true;
			}
			if(!dfs((1 << x) | state,sum + x,maxChoosableInteger,desiredTotal)){
				visted[state] = 1;
				return true;
			}
		}
		visted[state] = 2;
		return false;
	}
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if(maxChoosableInteger > desiredTotal)
			return true;
		if((maxChoosableInteger+1)*maxChoosableInteger < desiredTotal * 2)
			return false;
		return dfs(0,0,maxChoosableInteger,desiredTotal);
    }
};

	
int main() {

	freopen("out.out","w",stdout);
	Solution solution;
	// int maxChoosableInteger = 10,desiredTotal = 11;
	// int maxChoosableInteger = 10,desiredTotal = 3;
	int maxChoosableInteger = 10,desiredTotal = 0;
	// int maxChoosableInteger = 20,desiredTotal = 210;

	auto ans = solution.canIWin(maxChoosableInteger,desiredTotal);
	PrintBool(ans);
	
	return 0;
}



