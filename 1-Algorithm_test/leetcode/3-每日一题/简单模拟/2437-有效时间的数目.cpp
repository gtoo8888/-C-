#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
	int count_num(string time,int jinzhi){
		int ans = 0;
		for(int i = 0;i < jinzhi;i++){
			if((time[0] == '?' || i/10 == time[0]-'0') &&
			   (time[1] == '?' || i%10 == time[1]-'0'))
			   ans++;
		}
		return ans;
	}

    int countTime(string time) {
        return (count_num(time.substr(0,2),24) * count_num(time.substr(3,2),60));
    }
};

int main() {
	Solution solution;
	string time;

	time = "?5:00";
	cout << solution.countTime(time) << endl;cout <<"-------------"<< endl;

	time = "15:0?";
	cout << solution.countTime(time) << endl;cout <<"-------------"<< endl;

	time = "15:??";
	cout << solution.countTime(time) << endl;cout <<"-------------"<< endl;

	time = "1?:??";
	cout << solution.countTime(time) << endl;cout <<"-------------"<< endl;

	time = "??:??";
	cout << solution.countTime(time) << endl;cout <<"-------------"<< endl;

	return 0;
}



