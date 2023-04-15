#include <iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
class Solution {
public:
    bool isRobotBounded(string instructions) {
		int n = instructions.size();
		int dir = 0;
		int now_x = 0,now_y = 0;
		for(int i = 0;i < n;i++){
			if(instructions[i] == 'L'){
				dir += 3;
				dir %= 4;
				// dir = dir - 1 < 0 ? dir+2 : dir-1;
			}else if(instructions[i] == 'R'){
				dir += 1;
				dir %= 4;
				// dir = dir + 1 > 3 ? 0 : dir+1;
			}else {
				now_x += direction[dir][0];
				now_y += direction[dir][1];
			}
			printf("%d %d\n",now_x,now_y);
		}
		
		if(now_x == 0 && now_y == 0) // 位于原点，必定循环
			return true;
		if(dir == 0){	// 朝北，只有不是原点在不是循环
			if(now_x != 0 && now_y != 0)
				return false;
		}else if(dir == 2){ // 朝南，循环
			return true;
		}else if(dir == 1 || dir == 3){  // 朝东和西，都是循环
			return true;
		}
		return false;
		// return dir != 0 || (now_x != 0 && now_y != 0);
    }
};

int main(){
	Solution solution;
	// string instructions = "GGLLGG";
	string instructions = "GLRLLGLL";
	

	auto ans = solution.isRobotBounded(instructions);
	
	PrintBool(ans);
	return 0;
}














