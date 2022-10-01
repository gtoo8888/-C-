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



// �ȱ����������ٱ�����Ʒ
void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int> dp(bagWeight + 1, 0);

    for(int j = 0; j <= bagWeight; j++) { // ������������
        for(int i = 0; i < weight.size(); i++) { // ������Ʒ
            if (j - weight[i] >= 0) 
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			printVector(dp);
        }
		cout << endl;
    }
    cout << dp[bagWeight] << endl;
}


int main() {
    test_CompletePack();
}
		


