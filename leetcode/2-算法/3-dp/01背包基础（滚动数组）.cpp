#include <iostream>
#include <vector>
using namespace std;

// �����������Ϊ4��
// ��ƷΪ��
//               ����	��ֵ
//     ��Ʒ0    1    15
//     ��Ʒ1	3	20
//     ��Ʒ2	4	30
// �ʱ����ܱ�����Ʒ����ֵ�Ƕ��٣�
void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<int> dp(bagweight + 1,0) ;
    for(int i = 0;i < weight.size();i++) {
    	for(int j = bagweight;j >= weight[i];j--){//��������Ϊ���ظ�ȡ��Ʒ 
    		int temp = dp[j - weight[i]];	//����Ϊj - weight[i]�ı�������������ֵ
    		dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
    		printVector(dp);
		}
		cout << endl; 
	}
    cout << dp[bagweight] << endl;
}
		
int main() {
	test_2_wei_bag_problem1();
	return 0;
}



