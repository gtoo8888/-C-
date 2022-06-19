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


//老师捞我
//时间限制： 1000MS
//内存限制： 524288KB
//题目描述：
//       又到了一学期一次的大学生期末考试。但很多人期末考试的卷面成绩是不能及格的，需要靠较高的平时成绩来拖上去。平时成绩与期末考试的占比已经确定，假设平时成绩占比为p，期末考试占比为q，平时分为a，期末考试分数为b，则总成绩为(p*a+q*b)/100。（平时分与期末成绩都是整数，但总成绩可以是小数。）
//
//       饶老师心肠特别好，他希望自己的学生及格率尽可能的高。但他也坚持期末考试分数更高的学生平时成绩也一定要更高。饶老师想知道在这种情况下，他们班的最大及格人数是多少（及格是指总成绩不低于60分）。
//
//
//
//输入描述
//第一行三个正整数n，p，q（1<=n<=200,0<=p<=100,0<=q<=100,p+q=100）
//
//第二行n个正整数表示n个学生的期末考试分数（0<=分数<=100）
//
//输出描述
//仅一行，一个正整数，表示最大及格人数。

