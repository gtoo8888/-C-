#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

 

// 理解愚蠢的题意
// 就是这个题目内置了一个guess函数，并且有一个内定的选好的值pick
// 本来的判断大小被二分的guess的返回值代替了
// 需要通过二分法，不断的猜测，找到pick的值
// class Solution {
// public:
// 	int pick = 6;
// 	int guess(int num){
// 		if(num < pick)
// 			return -1;
// 		else if(num > pick)
// 		 	return 1;
// 		else
// 			return 0;
//  	}

//     int guessNumber(int n) {
// 		for(int i = 0;i < n;i++)
// 			if(!guess(i))
// 				return i;
//     }
// };


class Solution {
public:
	int pick = 6;
	int guess(int num){
		if(num < pick)
			return 1;
		else if(num > pick)
		 	return -1;
		else
			return 0;
 	}

    int guessNumber(int n) {
		int l = 0,r = n;
		while(l < r){
			int mid = l + (r-l)/2;
			printf("%d %d %d\n",l,mid,r);
			if(guess(mid) <= 0)
				r = mid;
			else
				l = mid + 1;
		}
		return l;
    }
};



int main(){
	Solution sol;
	int n = 10;

	
	auto ans = sol.guessNumber(n);
	
	cout << ans <<endl;
	return 0;
}
