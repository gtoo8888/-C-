#include <iostream>
#include <vector>
using namespace std;

// 背包最大重量为4。
// 物品为：
//               重量	价值
//     物品0    1    15
//     物品1	3	20
//     物品2	4	30
// 问背包能背的物品最大价值是多少？
void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<int> dp(bagweight + 1,0) ;
    for(int i = 0;i < weight.size();i++) {
    	for(int j = bagweight;j >= weight[i];j--){//不正序因为会重复取物品 
    		int temp = dp[j - weight[i]];	//容量为j - weight[i]的背包所背的最大价值
    		dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
    		printVector(dp);
		}
		cout << endl; 
	}
    cout << dp[bagweight] << endl;
}
		
int main() {
	test_2_wei_bag_problem1();
	return 0;
}



