#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


// 提取出arr1中的一个数字n，查找这个数字在arr2中比他大的第一个x1和比他小的第一个x2
// 如果|x1-n|>d && |x2-n|>d也就是n肯定满足条件的，就记为答案
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int n1 = arr1.size(),n2 = arr2.size();
		sort(arr2.begin(),arr2.end());// 二分之前进行排序
		int ans = 0;
		for(int i = 0;i < n1;i++){
			int l = 0,mid,r = n2-1;
			int b_down = 0,b_up = 0;
			while(l <= r){
				mid = l + (r - l)/2;
				// printf("%d %d %d %d\n",arr2[mid],l,mid,r);
				if(arr2[mid] <= arr1[i]){
					b_down = mid;
					l = mid+1;
				}else{
					b_up = mid;
					r = mid-1;
				}
			}
			// printf("%d %d %d %d\n\n",b_down,b_up,arr2[b_down],arr2[b_up]);
			if(abs(arr1[i] - arr2[b_down]) > d && abs(arr1[i] - arr2[b_up]) > d)
				ans++;
		}
		return ans;
    }
};




int main(){
	Solution sol;
	vector<int> arr1 = {2,1,100,3};
	vector<int> arr2 = {-5,-2,10,-3,7};
	char d = 6;

	auto ans = sol.findTheDistanceValue(arr1,arr2,d);
	
	cout << ans <<endl;
	return 0;
}
