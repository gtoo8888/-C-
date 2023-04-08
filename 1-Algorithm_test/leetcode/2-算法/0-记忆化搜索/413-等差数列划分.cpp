#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 递归
class Solution {
public:
    int cout = 0;
    int integerReplacement(int n) {
        cout++;
        if(n == 1) // 到达1，返回0
            return 0;
        if(n%2 == 0)    // 如果是偶数，从n/2递推过来
            return 1+integerReplacement(n/2);
        // 如果是奇数，需要转换到n+1或者n-1，然后转化到(n+1)/2或者(n-1)/2，所以需要加上2
        // n+1会溢出，所以使用
        // n/2 -> (n-1)/2
        // n/2+1 -> (n+1)/2
        return 2 + min(integerReplacement(n/2),integerReplacement(n/2+1));
    }
};

// 记忆化搜索
class Solution2 {
public:
    // 可以用vector来代替，但是如果n=1000,那就需要v
    unordered_map<int,int> umap;
    int cout = 0;
    int integerReplacement(int n) {
        cout++;
        if(n == 1) 
            return 0;
        if(umap.count(n)) // 如果之前存过，就直接查找返回
            return umap[n];
        if(n%2 == 0)  // 每次计算的结果，都存放到hash表中
            return umap[n] = 1+integerReplacement(n/2);
        return umap[n] = 2 + min(integerReplacement(n/2),integerReplacement(n/2+1));
    }
};

void test(int n){
    Solution sol;
    Solution2 sol2;

    printf("求的答案:%d\n",n);
	auto ans = sol.integerReplacement(n);
    // cout << ans << endl;
    printf("递归,迭代次数:%d\n",sol.cout);

    auto ans2 = sol2.integerReplacement(n);
    // cout << ans2 << endl;
    printf("记忆化搜索,迭代次数:%d\n",sol2.cout);
    // 提升的倍数 = (提升后的数 - 原来的数) ÷ 原来的数
    int s1 = sol.cout,s2 = sol2.cout;
    printf("提升效率:%f\n",(float)(s1-s2)/s2);
    int n2 = sol2.umap.size();
    printf("hash.size:%d vector.size:%d\n",n2,n);
    // 减少的比例 = (原来的数 - 现在的数) ÷ 原来的数
    printf("空间减少比例:%.3f%%\n",(float)(n-n2)/n*100);
    cout << endl;
}

int main() {

	// int n = 8;
    // int n = 7;
    // int n = 4;
    int n = 10800;

    test(8);

    test(100);
    test(1000);
    test(10000);
    test(100000);
    test(1000000);

	return 0;
}



