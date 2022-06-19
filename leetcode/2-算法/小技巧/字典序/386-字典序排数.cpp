#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int number = 1;
        for(int i = 0;i <= n;i++){
            res[i] = number;
            if(number * 10 <= n){
                number *= 10;
            }else{
                while(number % 10 == 9 || number + 1 > n){
                    number /= 10;
                }
                number++;
            }
            // cout << number << endl;
        }
        
        return res;
    }
};


	
int main() {
	Solution solution;
	int n = 139;
	
	auto ans = solution.lexicalOrder(n);
	
	printVector(ans);
	
	return 0;
}



