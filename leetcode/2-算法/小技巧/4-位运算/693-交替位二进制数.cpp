#include <iostream>
#include <vector>
using namespace std;

// void PrintVector(vector<int> v){
// 	for(auto it = v.begin();it != v.end();it++)
// 		cout << *it << " ";
// 	cout << endl; 
// }

//n & 1 == 1�ж���һλ�ǲ���1
//n | 0 == 0�ж���һλ�ǲ���0
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
        int test = n & 1; // ��������һλ��ʲô
        while(n != 0) {
            int pre = (n >> 1) & 1; //ȡ�������ڶ�λ
            if(pre == test) // �������λ��ȣ����Ǵ����
                return false;
            test = pre; //ÿ��ˢ�����һλ
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



