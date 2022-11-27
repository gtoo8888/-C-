#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"




// class Solution {
// public:
//     int subarrayLCM(vector<int>& nums, int k) {
//         printf("%d\n",lcm(5,1));
//         int n = nums.size();
//         int ans = 0;
//         for(int i = 0;i < n;i++) {
//             int a = nums[i];
//             for(int j = i;j < n;j++){
//                 if(j == i && nums[j] == k){
//                     printf("%d %d\n",a,nums[j]);
//                     ans++;
//                 }
//                 if(j != i){
//                     if((lcm(a,nums[j]) == k)){
//                         printf("%d %d\n",a,nums[j]);
//                         ans++;
//                     }
//                     // else    
//                     //     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };


int fun(long long a,long long b)
{
    long long temp;
    long long x,y;
    x=a;
    y=b;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return x/a*y;
}

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        // printf("%d\n",lcm(5,1));
        int n = nums.size();
        // PrintVector(nums);
        int ans = 0;
        for(int i = 0;i < n;i++) {
            for(int j = i+1;j <= n;j++){
                vector<int> tmp(nums.begin()+i,nums.begin()+j);
                // PrintVector(tmp);
                int n2 = tmp.size();
                if(n2 >= 2){
                    for(int i = 1;i < tmp.size();i++){
                        tmp[i] = fun(tmp[i],tmp[i-1]);
                    }
                    // printf("lcm%d\n",tmp[n2-1]);
                    if(tmp[n2-1] > k)
                        break;
                    if(tmp[n2-1] == k)
                        ans++;
                }else{
                    // printf("nums[i]%d\n",nums[i]);
                    if(nums[i] == k)
                        ans++;
                }
            }
        }
        return ans;
    }
};


int main() {
	Solution solution;

    vector<int> views = {3,6,2,7,1};
    int k = 6;

    // vector<int> views = {3};
    // int k = 2;

    // vector<int> views = {2,1,1,5};
    // int k = 5;


    auto ans = solution.subarrayLCM(views,k);

	cout << ans << endl;
	return 0;
}




