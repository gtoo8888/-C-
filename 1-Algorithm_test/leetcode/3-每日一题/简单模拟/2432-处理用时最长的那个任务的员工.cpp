#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max_speed_time = logs[0][1];
		int ans_id = logs[0][0];
		int logs_n = logs.size();
		for(int i = 1;i < logs_n;i++){
			int speed_time = logs[i][1]-logs[i-1][1];
			if(speed_time > max_speed_time){
				max_speed_time = speed_time;
				ans_id = logs[i][0];
			}else if(speed_time == max_speed_time){
				if(logs[i][0] < ans_id)
					ans_id = logs[i][0];
			}
		}
		return ans_id;
    }
};

int main() {
	Solution solution;
	int n = 10;
	vector<vector<int>> logs;

	n = 10;logs = vector<vector<int>>{{0,3},{2,5},{0,9},{1,15}};
	cout << solution.hardestWorker(n,logs) << endl;

	n = 26;logs = vector<vector<int>>{{1,1},{3,7},{2,12},{7,17}};
	cout << solution.hardestWorker(n,logs) << endl;

	n = 2;logs = vector<vector<int>>{{0,10},{1,20}};
	cout << solution.hardestWorker(n,logs) << endl;

	n = 70;logs = vector<vector<int>>{{36,3},{1,5},{12,8},{25,9},{53,11},{29,12},{52,14}};
	cout << solution.hardestWorker(n,logs) << endl;
	return 0;
}



