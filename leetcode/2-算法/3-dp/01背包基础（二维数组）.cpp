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

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));


    for(int j = weight[0];j <= bagweight;j++)
        dp[0][j] = value[0];
    PrintVVector(dp);  

    for(int i = 1;i < weight.size();i++) {  //第几个物品
        for(int j = 0;j <= bagweight;j++) { //j不是遍历顺序，就是背包当前的载重
            if(j < weight[i])   //j当前遍历的背包的载重，小于当前要背起的物品的重量weight[i]时候
                dp[i][j] = dp[i - 1][j];    //继承上面的一格
            else   {
                int temp1 = dp[i - 1][j];
                int temp2 = dp[i - 1][j - weight[i]];
                int temp3 = dp[i - 1][j - weight[i]] + value[i];
                //因为这个时候j已经比weight[i]大了，所以也就不止可以装一个物品了，可以看下还能多装多少
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
                cout << temp1 << " " << temp2 << " " << temp3 << endl;
            }
            cout << dp[i][j] << endl;
        }
        PrintVVector(dp);
    }

    

    cout << dp[weight.size()-1][bagweight] << endl;
}
		
int main() {
	test_2_wei_bag_problem1();
	return 0;
}



