#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

// ����ⷨ������ܳ�
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




// �򵥵��жϾͿ�����
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		int n = letters.size();
		int l = 0,mid,r = n-1;
		int ans = 0;// ���'a'����'z'���֣���ǰ����󣬶�û����letters�г��֣���󶼻�ѭ������
		// ��ֵΪ0����ڷ�Χ�������
		while(l <= r){
			mid = l + (r - l)/2;
			printf("%c %d %d %d\n",letters[mid],l,mid,r);
			if(letters[mid] <= target)// ���������һ������ĸ���᲻�ϵ�������߽�
			// Ҳ������������ͬ��ĸ���ұߵ��Ǹ���
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
