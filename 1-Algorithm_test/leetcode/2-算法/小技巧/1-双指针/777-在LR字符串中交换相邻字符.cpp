#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



class Solution {
public:
    bool canTransform(string start, string end) {
		int n = start.size();
		vector<int> num_start(2,0);
		vector<int> num_end(2,0);
		for(int i = 0;i < n;i++){
			if(start[i] == 'L')	num_start[0]++;
			if(start[i] == 'R')	num_start[1]++;

			if(end[i] == 'L')	num_end[0]++;
			if(end[i] == 'R')	num_end[1]++;
		}
		// PrintVector(num_start);
		// PrintVector(num_end);

		if(num_start[0] != num_end[0] || num_start[1] != num_end[1])	// ���ж��ǲ���L��R���ܸ������
			return false;
		int i = 0,j = 0;
		while(i < n && j < n){	// ȫ����������
			while(i < n && start[i] == 'X')
				i++;
			while(j < n && end[j] == 'X')
				j++;
			// printf("%c %c %d %d\n",start[i],end[j],i,j);
			if(start[i] == 'R'){	// �������R����ô��β��Rһ�����ұ�
				if(end[j] != 'R')
					return false;
				if(i > j)
					return false;
				else{
					i++;j++;
				}
			}
			if(start[i] == 'L'){	// �������L����ô��β��Rһ�������
				if(end[j] != 'L')
					return false;
				if(i < j)
					return false;
				else{
					i++;j++;
				}
			}
		}
		return true;
    }
};


	
int main() {
	Solution solution;
	// string start = 	"RXXLRXRXL";
	// string end = 	"XRLXXRRLX";

	// string start = 	"RXLXRXRXL";
	// string end = 	"RXXLRXRXL";	// ����λ���෴

	string start = 	"RXLXRXRXL";
	string end = 	"RXLLRXRXL";	
	
	auto ans = solution.canTransform(start,end);
	PrintBool(ans);
	
	return 0;
}



