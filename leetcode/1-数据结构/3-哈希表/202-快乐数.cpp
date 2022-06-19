#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void printBool(bool val){
	if(val == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << endl;
}

class Solution {
public:
	vector<int> NumSeparate(int n) {//��ÿ�����𿪲������ 
		vector<int> ans;
		int temp = n;
		while(temp != 0){
			ans.push_back(temp%10);
			temp = temp / 10;			
		}
		return ans;
	}
	
    bool isHappy(int n) {
    	vector<int> nums;
    	unordered_set<int> sign;//������� �ظ�Ԫ�صĹ�ϣ�� 
    	int SumSquare = n;
    	while(SumSquare != 1){
    		nums = NumSeparate(SumSquare);//��ÿ�����𿪷���һ������ 
    		SumSquare = 0;//Ϊ��֮��ĸ�ֵ 
    		for(vector<int>::iterator it = nums.begin();it != nums.end();it++)//�����������㷽ʽ 
    			SumSquare += (*it) * (*it);
//    		auto ptr = sign.insert(SumSquare);//��������ĺͲ����ϣ�� 
    		pair<unordered_set<int>::iterator,bool> ptr = sign.insert(SumSquare);//���ص���һ�����飬������+bool 
    		cout << SumSquare << " " << ptr.second <<endl;
    		if(ptr.second == 0)//insert�ķ���pair���ʾ����ɹ�����ʧ�ܣ����ʧ�ܾͽ���ѭ�� 
    			return false;
//    		printVector(nums);
		}
		return true;
    }
};


int main() {
	Solution solution;
	bool ans;
	int n = 7;
	
	ans = solution.isHappy(n);

	
	printBool(ans);
	
	return 0;
}



