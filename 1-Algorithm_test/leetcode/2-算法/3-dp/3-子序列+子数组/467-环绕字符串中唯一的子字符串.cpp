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

// �����ַ���s="abcdefghijklmnopqrstuvwxyzabcd..."
// ����һ���ַ��� p����� p ���Ӵ�����������������
// 1���Ӵ�ͬʱ�� s ���Ӵ�
// 2���ظ����Ӵ�������
// 3���Ӵ��� p ����������
// 4���Ӵ��� s ����������
// 5���Ӵ��Ƿǿյ�
// ע�⣺p ��������ѭ���ַ����ĸ�
// ����
// ���� p="a"��p ���Ӵ��� "", "a"
// �����������Ӵ��������� 1
// ���� p="cac"��p���Ӵ��� "", "c", "a", "ca", "ac", "cac"
// �����������Ӵ��������� 2��Ҳ����˵ "ca"��"ac"��"cac"���� s ���Ӵ�
// ���� p="zab"��p���Ӵ��� "", "z", "a", "b", "za", "ab", "zab"
// �����������Ӵ��������� 6��Ҳ����˵ "z", "a", "b", "za", "ab", "zab" ���� s ���Ӵ�


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        int ans = 0;
        int k = 0;
        vector<int> dp(26);
        for(int i = 0;i < n;i++){
            if(i && (p[i] - p[i-1] + 26)%26 == 1) {// ÿ�ξ��жϣ�ǰ�������ַ����ǲ���������
            // ��ǰab������,baҲ���ԣ�ͬʱabc���ԣ�cba����
                ++k;    // ֻҪ�������ģ�Ҳ������s���棬�Ϳ��Ե����������Ӵ���ͳ����ֵ�Լ� 
            }
            else
                k = 1;  // ��������Ϊ1
            // printf("%d %c %c %d %d %d\n",k,p[i],p[i-1],abs(p[i] - p[i-1]),(p[i] - p[i-1] + 26)%26,p[i] - p[i-1]);
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'],k); // ��ͣ�ĸ������ֵ
            printVector(dp);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};




int main() {
	freopen("out.out","w",stdout);
	Solution solution;
	// string p = "zababa";
    // string p = "cac";
    string p = "zababababahytjncxcgrstr";
	
	auto ans = solution.findSubstringInWraproundString(p);
	cout << ans << endl;
	return 0;
}



