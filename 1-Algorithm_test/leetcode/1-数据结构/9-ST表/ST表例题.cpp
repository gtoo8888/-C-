#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
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

// ST��Ӧ����㷺��������ǽ��RMQ���⣺
// ����n������m��ѯ�ʣ�����ÿ��ѯ�ʣ���Ҫ�ش�����[l,r]�е����ֵ����Сֵ(���Բ�����������ͬʱ���д���)��

// ��������ÿ�ζ������������в�ѯ
// ʱ�临�Ӷ�O(nm)
// ��n��С��m�ܴ��ʱ��ʱ�临�ӶȾ޴�
// n = 100,m = 1e7,O(1e9)
// ��Ϊѯ�ʴ������࣬����������㷨
void test1(vector<int> arr){
    int ans,l,r;
    while(cin >> l >> r){
        ans = INT_MIN;
        // printf("%d %d %d\n",l,r,ans);
        for(int i = l;i <= r;i++)
            ans = max(ans,arr[i]);
        cout << ans << endl;
    }
}

// ʹ�ô���Ż�����ÿ������֮������ֵ��ȫ����ǰ��¼��������Ԥ����
// �ö�̬�滮�ķ������������ֵ��ͨ��֮ǰ��С�����Ƴ�����Ĵ�����
// �ռ临�Ӷ�O(n2)
// ʱ�临�Ӷ�O(n2+m)
// ��n = 100,m = 2��ʱ������Ƚϳ������Ǿ�ѯ�ʸ�һ����
// ��Ҫ10000�Ŀռ�ȥ�棬�����õĺ���
// ��n�ܴ��ʱ�򣬿ռ��ը��������ʱ�临�Ӷ�Ҳ����Ԥ�����ʱ��ܴ�
void test2(vector<int> arr){
    int l,r;
    int n = arr.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(i == j)
                ans[i][j] = arr[i];
            else    
                ans[i][j] = max(ans[i][j-1],arr[j]);
        }
    }
    PrintVVector(ans);
    while(cin >> l >> r){
        cout << ans[l][r] << endl;
    }
}



// ��������淽ʽ�������Ż�����һ��ϡ�����д洢
// Ԥ����O(nlogn)
// ��ѯ O(m)
vector<vector<int>> dp;// dp[i][j]��ʾ��˵�Ϊi����Ϊ2^j����������Ҳ����[i,i+2^j-1]
int querry(int l,int r){
    int j = (int)log2(r - l + 1);
    return  max(dp[l][j],dp[r - (1 << j) + 1][j]);
}

void test3(vector<int> arr){
    int l,r;
    int n = arr.size();
    int dp_log = (int)log2(n);
    cout << dp_log << endl;
    dp = vector<vector<int>>(n,vector<int>((int)log2(n),0 ));
    for(int i = 0;i < n;i++)
        dp[i][0] = arr[i];
    PrintVVector(dp);
    for(int j = 1;j < log2(n);j++){
        for(int i = 0;i + (1 << j) - 1 < n;i++){
            dp[i][j] = max(dp[i][j-1],dp[i + (1 << (j-1))][j-1]);
        } 
    }
    PrintVVector(dp);
    while(cin >> l >> r){
        cout << querry(l,r) << endl;
    }
}


	
int main() {
	vector<int> arr = {9,3,1,7,5,6,0,8};
    // test1(arr);
    // test2(arr);
    test3(arr);
	return 0;
}




// 5 7
// 8
// 4 5
// 6
// 3 7
// 7

