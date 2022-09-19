#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
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

// ST表应用最广泛的领域便是解决RMQ问题：
// 给定n个数，m个询问，对于每个询问，需要回答区间[l,r]中的最大值或最小值(可以采用两个数组同时进行处理)。

// 暴力法，每次对输入的区间进行查询
// 时间复杂度O(nm)
// 当n很小，m很大的时候，时间复杂度巨大
// n = 100,m = 1e7,O(1e9)
// 因为询问次数过多，拖累了这个算法
void test1(vector<int> arr){
    int ans,l,r;
    while(cin >> l >> r){
        ans = INT_MIN;
        // printf("%d %d %d\n",l,r,ans);
        for(int i = l;i <= r;i++)
            ans = max(ans,arr[i]);
        cout << ans << endl;
    }
}

// 使用打表优化，将每个区间之间的最大值，全都提前记录下来，做预处理
// 用动态规划的方法计算出打表的值，通过之前的小区域，推出后面的大区域
// 空间复杂度O(n2)
// 时间复杂度O(n2+m)
// 当n = 100,m = 2的时候，数组比较长，但是就询问个一两次
// 需要10000的空间去存，但是用的很少
// 当n很大的时候，空间会炸掉，而且时间复杂度也会在预处理的时候很大
void test2(vector<int> arr){
    int l,r;
    int n = arr.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(i == j)
                ans[i][j] = arr[i];
            else    
                ans[i][j] = max(ans[i][j-1],arr[j]);
        }
    }
    PrintVVector(ans);
    while(cin >> l >> r){
        cout << ans[l][r] << endl;
    }
}



// 对这个储存方式进行了优化，用一个稀疏表进行存储
// 预处理O(nlogn)
// 查询 O(m)
vector<vector<int>> dp;// dp[i][j]表示左端点为i长度为2^j这样的区间也就是[i,i+2^j-1]
int querry(int l,int r){
    int j = (int)log2(r - l + 1);
    return  max(dp[l][j],dp[r - (1 << j) + 1][j]);
}

void test3(vector<int> arr){
    int l,r;
    int n = arr.size();
    int dp_log = (int)log2(n);
    cout << dp_log << endl;
    dp = vector<vector<int>>(n,vector<int>((int)log2(n),0 ));
    for(int i = 0;i < n;i++)
        dp[i][0] = arr[i];
    PrintVVector(dp);
    for(int j = 1;j < log2(n);j++){
        for(int i = 0;i + (1 << j) - 1 < n;i++){
            dp[i][j] = max(dp[i][j-1],dp[i + (1 << (j-1))][j-1]);
        } 
    }
    PrintVVector(dp);
    while(cin >> l >> r){
        cout << querry(l,r) << endl;
    }
}


	
int main() {
	vector<int> arr = {9,3,1,7,5,6,0,8};
    // test1(arr);
    // test2(arr);
    test3(arr);
	return 0;
}




// 5 7
// 8
// 4 5
// 6
// 3 7
// 7

