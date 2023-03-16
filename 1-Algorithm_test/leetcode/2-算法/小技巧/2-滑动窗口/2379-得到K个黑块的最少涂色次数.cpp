#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



class Solution {
public:
    int minimumRecolors(string blocks, int k) {
		int n = blocks.size();
        int black_num = 0,white_num = 0;
		for(int i = 0;i < k;i++){
			if(blocks[i] == 'W')
				black_num++;
		}
		int min_change = black_num;
		int left = 0;
		int right = k;
		while(right < n){
			if(blocks[left] == 'W')
				black_num--;
			if(blocks[right] == 'W')
				black_num++;
			right++;left++;
			min_change = min(min_change,black_num);
		}
		return min_change;
    }
};


	
int main() {
	Solution solution;
	// string blocks = "WBBWWBBWBW";
	// int k = 7;
	string blocks = "WBWBBBW";
	int k = 2;	
	auto ans = solution.minimumRecolors(blocks,k);
	cout << ans << endl;
	
	return 0;
}



