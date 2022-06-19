#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

// 错误解法，代码很长
// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
// 		int n = letters.size();
// 		int l = 0,mid,r = n-1;
// 		if(target < letters[0])
// 			return letters[0];
// 		if(target > letters[n-1])
// 			return letters[0];
// 		int ans;
// 		while(l <= r){
// 			mid = l + (r - l)/2;
// 			// printf("%c %d %d %d\n",letters[mid],l,mid,r);
// 			if(letters[mid] == target){
// 				if(mid+1 >= n)
// 					return letters[0];
// 				return letters[mid+1];
// 			}
// 			else if(letters[mid] < target)
// 				l = mid+1;
// 			else{
// 				ans = mid;
// 				r = mid-1;
// 			}
// 		}
// 		// printf("%c %d %d %d\n",letters[mid],l,mid,r);
// 		return letters[ans];
//     }
// };




// 简单的判断就可以了
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		int n = letters.size();
		int l = 0,mid,r = n-1;
		int ans = 0;// 如果'a'或者'z'这种，最前和最后，都没有在letters中出现，最后都会循环回来
		// 赋值为0解决在范围外的问题
		while(l <= r){
			mid = l + (r - l)/2;
			printf("%c %d %d %d\n",letters[mid],l,mid,r);
			if(letters[mid] <= target)// 如果出现了一样的字母，会不断的收缩左边界
			// 也就是收缩到相同字母最右边的那个上
				l = mid+1;
			else{
				ans = mid;
				r = mid-1;
			}
		}
		return letters[ans];
    }
};



int main(){
	Solution sol;
	// vector<char> letters = {'c', 'f', 'j','m','o'};
	vector<char> letters = {'e','e','e','e','e','e','n','n','n','n'};
	char target = 'e';

	auto ans = sol.nextGreatestLetter(letters,target);
	
	cout << ans <<endl;
	return 0;
}
