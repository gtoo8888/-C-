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

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));


    for(int j = weight[0];j <= bagweight;j++)
        dp[0][j] = value[0];
    PrintVVector(dp);  

    for(int i = 1;i < weight.size();i++) {  //�ڼ�����Ʒ
        for(int j = 0;j <= bagweight;j++) { //j���Ǳ���˳�򣬾��Ǳ�����ǰ������
            if(j < weight[i])   //j��ǰ�����ı��������أ�С�ڵ�ǰҪ�������Ʒ������weight[i]ʱ��
                dp[i][j] = dp[i - 1][j];    //�̳������һ��
            else   {
                int temp1 = dp[i - 1][j];
                int temp2 = dp[i - 1][j - weight[i]];
                int temp3 = dp[i - 1][j - weight[i]] + value[i];
                //��Ϊ���ʱ��j�Ѿ���weight[i]���ˣ�����Ҳ�Ͳ�ֹ����װһ����Ʒ�ˣ����Կ��»��ܶ�װ����
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
                cout << temp1 << " " << temp2 << " " << temp3 << endl;
            }
            cout << dp[i][j] << endl;
        }
        PrintVVector(dp);
    }

    

    cout << dp[weight.size()-1][bagweight] << endl;
}
		
int main() {
	test_2_wei_bag_problem1();
	return 0;
}



