#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int magicalString(int n) {
		if(n < 4)
			return 1;
		string str(n,'0');
		str[0] = '1';str[1] = '2';str[2] = '2';
		int i = 2;
		int j = 3;
		while(j < n){
			int count = str[i] - '0';
			int num = 3 - (str[j-1] - '0');
			printf("%d %d\n",count,num);
			while(count > 0 && j < n){
				str[j] = '0'+num;
				count--;
				j++;
			}
			++i;
			cout << str << endl;
		}
		return count(str.begin(),str.end(),'1');
    }
};

	
int main() {
	Solution solution;
	int n = 6;
	
	auto ans = solution.magicalString(n);
	cout << ans << endl;
	
	return 0;
}



