#include <iostream>  
#include <vector>  
#include <algorithm>
using namespace std;

void printV(vector<int> v) {
	for(auto it = v.begin();it != v.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main(){
	int n,p,q;
	scanf("%d %d %d ",&n,&p,&q);
	vector<int> range(n,0);
	for(int i = 0;i < n;i++) {
		scanf("%d",&range[i]);
	}
	sort(range.begin(),range.end());
//	printV(range);
	vector<int> a(n,100);

	for(int i = range.size()-2;i >= 0;i--) {
//		printf("%d %d\n",range[i],range[i+1]);
		if(range[i] < range[i+1])
			a[i] = a[i+1] - 1;
		else if(range[i] == range[i+1]){
			a[i] = a[i+1];
		}
	}
//	printV(a);	
	
	int ans = 0;
	for(int i = 0;i < n;i++) {
		double result = 0;
		result = (p * a[i] + q * range[i])/100;
		if(result >= 60)
			ans++;
//		printf("%.2lf ",result);
	}
//	printf("\n%d\n",ans);
	printf("%d\n",ans);
	return 0;
}


//6 20 80
//51 51 51 50 50 49
//3
//
//2 50 50
//50 50
//2
//
//2 20 80
//51 50
//1


//��ʦ����
//ʱ�����ƣ� 1000MS
//�ڴ����ƣ� 524288KB
//��Ŀ������
//       �ֵ���һѧ��һ�εĴ�ѧ����ĩ���ԡ����ܶ�����ĩ���Եľ���ɼ��ǲ��ܼ���ģ���Ҫ���ϸߵ�ƽʱ�ɼ�������ȥ��ƽʱ�ɼ�����ĩ���Ե�ռ���Ѿ�ȷ��������ƽʱ�ɼ�ռ��Ϊp����ĩ����ռ��Ϊq��ƽʱ��Ϊa����ĩ���Է���Ϊb�����ܳɼ�Ϊ(p*a+q*b)/100����ƽʱ������ĩ�ɼ��������������ܳɼ�������С������
//
//       ����ʦ�ĳ��ر�ã���ϣ���Լ���ѧ�������ʾ����ܵĸߡ�����Ҳ�����ĩ���Է������ߵ�ѧ��ƽʱ�ɼ�Ҳһ��Ҫ���ߡ�����ʦ��֪������������£����ǰ����󼰸������Ƕ��٣�������ָ�ܳɼ�������60�֣���
//
//
//
//��������
//��һ������������n��p��q��1<=n<=200,0<=p<=100,0<=q<=100,p+q=100��
//
//�ڶ���n����������ʾn��ѧ������ĩ���Է�����0<=����<=100��
//
//�������
//��һ�У�һ������������ʾ��󼰸�������

