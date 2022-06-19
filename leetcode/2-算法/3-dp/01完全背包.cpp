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



// 先遍历背包，再遍历物品
void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int> dp(bagWeight + 1, 0);

    for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
        for(int i = 0; i < weight.size(); i++) { // 遍历物品
            if (j - weight[i] >= 0) 
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			printVector(dp);
        }
		cout << endl;
    }
    cout << dp[bagWeight] << endl;
}


int main() {
    test_CompletePack();
}
		


