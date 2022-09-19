#include <iostream>
#include <vector>
using namespace std;

// void PrintVector(vector<int> v){
// 	for(auto it = v.begin();it != v.end();it++)
// 		cout << *it << " ";
// 	cout << endl; 
// }

//n & 1 == 1判断这一位是不是1
//n | 0 == 0判断这一位是不是0
void printbit(int n) {
    while(n != 0 ) {
        if(n & 1 == 1)  
            cout << 1;
        else   
            cout << 0;
        n >>= 1;
    }
    cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int test = n & 1; // 先求出最后一位是什么
        while(n != 0) {
            int pre = (n >> 1) & 1; //取出倒数第二位
            if(pre == test) // 如果后两位相等，就是错误的
                return false;
            test = pre; //每次刷新最后一位
            n = n >> 1;
            // printbit(n);
        }
        return true;        
    }
};


	
int main() {
	Solution solution;
	int n = 10;
	
	int  ans = solution.hasAlternatingBits(n);
	
	PrintBool(ans);
	
	return 0;
}



