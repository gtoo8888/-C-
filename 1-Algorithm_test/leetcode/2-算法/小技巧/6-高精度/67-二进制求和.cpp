#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// 太长的模拟
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int n1 = a.size();
//         int n2 = b.size();
//         if(n2 > n1){
//             int tmp = n1;
//             n1 = n2;
//             n2 = tmp;
//             string tmp2 = a;
//             a = b;
//             b = tmp2;
//         }
//         // cout << a << endl;
//         // cout << b << endl;
//         // printf("%d %d\n",n1,n2);
//         string ans(n1,'%');
//         bool flag = false;
//         int i = n1-1,j = n2-1;
//         for(;j >= 0;i--,j--){
//             if(flag)
//                 if(a[i]-'0' + b[j]-'0' + 1 > 1){
//                     flag = true;
//                     ans[i] = (a[i]-'0' + b[j]-'0' + 1)%2 + '0';
//                 }else {
//                     flag = false;
//                     ans[i] = (a[i]-'0' + b[j]-'0' + 1)%2 + '0';
//                 }
//             else
//                 if(a[i]-'0' + b[j]-'0' > 1){
//                     flag = true;
//                     ans[i] = (a[i]-'0' + b[j]-'0')%2 + '0';
//                 }else {
//                     flag = false;
//                     ans[i] = (a[i]-'0' + b[j]-'0')%2 + '0';
//                 }
//             // printf("a[i]:%c b[j]:%c %d %d\n",a[i],b[j],i,j);
//             // cout << ans << endl;
//         }
//         // cout  << endl;
//         while(i >= 0){
//             if(flag){
//                 if(a[i] - '0' + 1 > 1){
//                     flag = true;
//                     ans[i] = (a[i] - '0' + 1)%2 + '0';
//                 }else {
//                     flag = false;
//                     ans[i] = (a[i] - '0' + 1)%2 + '0';
//                 }
//             }else{
//                 flag = false;
//                 ans[i] = a[i] - '0' + '0';
//             }
//             i--;
//             // cout << flag << endl;
//             // cout << ans << endl;
//         }
//         if(flag)
//             ans = '1' + ans;
//         return ans;
//     }
// };
	

// 简化的模拟
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         reverse(a.begin(),a.end());
//         reverse(b.begin(),b.end());
//         cout << a << endl;
//         cout << b << endl;
//         int n = max(a.size(),b.size());
//         int cnt = 0;
//         string ans(n,'%');
//         for(int i = 0;i < n;i++){
//             if(i < a.size())
//                 cnt += (a[i] == '1');
//             if(i < b.size())
//                 cnt += (b[i] == '1');
//             printf("%d \n",cnt);
//             ans[i] = (cnt%2) + '0';
//             cnt /= 2;
//             cout << ans << endl;
//         }
//         if(cnt)
//             ans.push_back('1');
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };


// 再次简化
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n = max(a.size(),b.size());
        int cnt = 0;
        string ans(n,'%');
        for(int i = 0;i < n;i++){
            cnt += i < a.size() ? (a[i] == '1') : 0;
            cnt += i < b.size() ? (b[i] == '1') : 0;
            // printf("%d\n",cnt);
            ans[i] = (cnt%2) + '0';
            cnt /= 2;
            // cout << ans << endl;
        }
        if(cnt)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());        
        return ans;
    }
};


int main() {
	Solution solution;
    // string a = "1010";
    // string b = "1011";

    string a = "1111";
    string b = "1";
	
	auto ans = solution.addBinary(a,b);
	
	cout << ans << endl;
	
	return 0;
}



