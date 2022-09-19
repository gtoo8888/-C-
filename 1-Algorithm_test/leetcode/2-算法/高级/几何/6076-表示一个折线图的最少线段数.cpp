#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVVector(vector<vector<char>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintQueue(stack<char> st){
	while(!st.empty()){
		printf("%c ",st.top());
		st.pop();
	}
	cout << endl; 
}

// class Solution {
// public:
//     int minimumLines(vector<vector<int>>& stockPrices) {
//         // unordered_map<double,double> map;
//         sort(stockPrices.begin(),stockPrices.end());
//         int n = stockPrices.size();
//         // printf("%d\n",n);
//         double save_k = 0xfffff;
//         int ans =  0;
//         for(int i = 0;i < n-1;i++){
//             double yy = stockPrices[i+1][1] - stockPrices[i][1];
//             double xx = stockPrices[i+1][0] - stockPrices[i][0];
//             double kk = yy / xx;
//             if(save_k != kk){
//                 save_k = kk;
//                 ans++;
//             }   
//             printf("%f %f %f\n",kk,yy,xx);
//         }
//         return ans;  
//     }
// };


// prey/prex != yy/xx 两个斜率相同
// prey * xx != yy * prex 改变公式，用相乘来判断
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n == 1)
            return 0;
        sort(stockPrices.begin(),stockPrices.end());
        // printf("%d\n",n);
        long long prey = stockPrices[1][1] - stockPrices[0][1];
        long long prex = stockPrices[1][0] - stockPrices[0][0];
        int ans =  1;
        for(int i = 1;i < n;i++){
            long long yy = stockPrices[i][1] - stockPrices[i-1][1];
            long long xx = stockPrices[i][0] - stockPrices[i-1][0];
            // double kk = yy / xx;
            // if((double)prey/prex != (double)yy/xx){  // 用除法会导致精度问题
            if(prey * xx != yy * prex){ // 除法改成乘法能解决
                prey = yy;
                prex = xx;
                ans++;
            }   
            // printf("%lld %lld\n",yy,xx);
        }
        return ans;
    }
};



	
int main() {
	Solution solution;
    // vector<vector<int>> stockPrices = {{1,7},{2,6},{3,5},{4,4},{5,4},{6,3},{7,2},{8,1}};
    // vector<vector<int>> stockPrices = {{72,98},{62,27},{32,7},{71,4},{25,19},{91,30},{52,73},{10,9},{99,71},{47,22},{19,30},{80,63},{18,15},{48,17},{77,16},{46,27},{66,87},{55,84},{65,38},{30,9},{50,42},{100,60},{75,73},{98,53},{22,80},{41,61},{37,47},{95,8},{51,81},{78,79},{57,95}};
    // vector<vector<int>> stockPrices = {{1,3},{2,3},{3,3}} ;
    vector<vector<int>> stockPrices = {{1,1},{500000000,499999999},{1000000000,999999998}};

    auto ans = solution.minimumLines(stockPrices);

	cout << ans << endl;
	return 0;
}




