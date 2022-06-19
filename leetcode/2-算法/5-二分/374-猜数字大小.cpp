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

 

// ����޴�������
// ���������Ŀ������һ��guess������������һ���ڶ���ѡ�õ�ֵpick
// �������жϴ�С�����ֵ�guess�ķ���ֵ������
// ��Ҫͨ�����ַ������ϵĲ²⣬�ҵ�pick��ֵ
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
