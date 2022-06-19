#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



// class Solution {
// public:
//     bool is_nature(int num) {
//         int temp_n = num;
//         vector<int> num_bit;
//         while(temp_n != 0) {
//             num_bit.push_back(temp_n%10);
//             temp_n = temp_n / 10;
//         }
//         // PrintVector(num_bit);
//         for(int i = 0;i < num_bit.size();i++) {
//             if(num_bit[i] == 0)
//                 return false;
//             if(num % num_bit[i] != 0){
//                 return false;
//             }
//         }
//         return true;
//     }

//     vector<int> selfDividingNumbers(int left, int right) {
//         // is_nature(52);
//         vector<int> ans;
//         for(int i = left;i <= right;i++) {
//             // cout << is_nature(i) << endl;
//             if(is_nature(i) == true)
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool is_nature(int num) {
        int temp_n = num;
        while(temp_n != 0) {
            int bijiao = temp_n%10;
            if(bijiao == 0 || num%bijiao != 0){ 
                //需要先判断取出的数是不是0，短路运算，防止后面除数为0
                return false;
            }
            temp_n = temp_n / 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left;i <= right;i++) {
            if(is_nature(i) == true)
                ans.push_back(i);
        }
        return ans;
    }
};


	
int main() {
	Solution solution;
	int left = 47, right = 85;
	
	auto ans = solution.selfDividingNumbers(left,right);
	
	PrintVector(ans);
	
	return 0;
}



