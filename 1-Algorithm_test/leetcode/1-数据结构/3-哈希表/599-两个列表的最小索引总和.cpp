#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void printBool(bool val){
	if(val == true)		cout << "YES" << endl;
	else				cout << "NO" << endl;
	cout << endl;
}

void printlVector(vector<string> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printMap(unordered_map<string,int> m) {
	for(unordered_map<string,int>::iterator it = m.begin();it != m.end();it++) 
		cout << (*it).first << " " << it->second << endl;
	cout << endl;
}

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string,int> m1;
		unordered_map<string,int> m2;
		int num1 = 0;
		int num2 = 0;
		int min_num = INT32_MAX; 
		for(auto it = list1.begin();it != list1.end();it++) {//���Բ�ʹ�õ���������
		//����������ķ�ʽ�����ٱ���num1��num2 
			num1++;
			m1[*it] = num1;//��һ�α�����ʱ����ַ�������Ŷ����ȥ 
		}
		vector<string> ans;
		for(auto it = list2.begin();it != list2.end();it++) {
			if(m1.find(*it) != m1.end()) {//�ҵ��� 
				if((m1[*it] + num2) < min_num) {//����ҵ��������ͱ�ԭ����С 
					min_num = m1[*it] + num2;//������С������ 
					ans.clear();//��ԭ���Ĵ������������ 
					ans.push_back(*it);
				}
				else if((m1[*it] + num2) == min_num) {//�����С��������һ���ģ����ϲ��� 
					ans.push_back(*it);
				}	
			}
			//û�ҵ�ʲô��������ֻ��Ҫ��ż�һ�ͺ��ˣ��͵����Թ��� 
			num2++;
		}
//		cout << min_num << endl;
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	vector<string> ans;
	
	ans = solution.findRestaurant(list1,list2);
	
	printlVector(ans);
	
	return 0;
}



