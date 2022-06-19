#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    // 暴力
    vector<int> runningSum_baoli(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        for(int i = 0;i < n;i++) {
            int tmp_sum = 0;
            for(int j = 0;j <= i;j++) {
                tmp_sum += nums[j];
            }
            pre[i] = tmp_sum;
        }
        return pre;
    }
    // 一维前缀和模板
    vector<int> runningSum_pre(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1;i < n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        return pre;
    }
    // 一维前缀和模板 前面有空0
    vector<int> runningSum_pre2(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1);
        for(int i = 0;i < n;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        return pre;
    }
};


vector<int> Create_Vector(int rand_n,int rand_scope){
    // vector<int> num = {49, 38 , 65, 97, 78, 13, 27, 49};
    // vector<int> num;
    vector<int> num(rand_n);

    srand((unsigned)time(NULL));
    // for(int i = 0;i < rand_n;i++)
    for(int i = 0;i < rand_n;i++)
        // num.push_back(rand()%rand_scope);
        // num.push_back(rand() & (rand_scope - 1));
        // num[i] = rand()%rand_scope;
        num[i] = rand() & (rand_scope - 1);
        
    return num;
}

// 当数据量在105的时候，O(n2)的算法已经不行了
// 前缀和在数据量108的时候，运行时间1024ms
int main() {
	Solution solution;
	// vector<int> nums = {3,1,2,10,1};

    int rand_n = 100;
    int rand_scope = 100;
    int test_n = 2;
    vector<int> nums = Create_Vector(rand_n,rand_scope);
	PrintVector(nums);

    clock_t start,end; 
	start = clock();
	// auto ans = solution.runningSum_baoli(nums);
    // auto ans = solution.runningSum_pre(nums);
    auto ans = solution.runningSum_pre2(nums);
    end = clock();
    printf("time = %.0fms\n",double(end-start)/CLOCKS_PER_SEC * 1000);
	PrintVector(ans);
	
	return 0;
}



