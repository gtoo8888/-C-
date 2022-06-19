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
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> u(m,0);
	vector<int> v(m,0);
	vector<int> w(m,0);
	for(int i = 0;i < m;i++) 
		scanf("%d",&u[i]);
	for(int i = 0;i < m;i++) 
		scanf("%d",&v[i]);
	for(int i = 0;i < m;i++) 
		scanf("%d",&w[i]);	
		
//	printV(u);
//	printV(v);
//	printV(w);
//	
//	for(int i = 0;i < n;i++) {
//	}
    printf("%d",w[0]+w[1]);
	
	return 0;
}


//老张修路
//时间限制： 1000MS
//内存限制： 65536KB
//题目描述：
//老张在一家工程公司担任规划师。
// 一天，这个工程公司接到了市政府的道路翻新任务，需要在已有的路网上规划一些路段进行翻新，
// 并保证规划中的翻新道路经过了所给路网上所有的结点（一段翻新道路经过其两端的结点），
// 同时所有翻新的路段必须构成一棵树，也就是说不可以存在一段不与其他翻新路段相连的翻新路段。
// 因为翻新成本与道路长度有关，所以需要规划翻新的道路长度和最小，老张想请你帮忙计算这个最小长度和。

//输入描述
//第一行有2个正整数n和m，表示所给路网的结点数和道路数。
//接下来有3行，每一行有m个正整数，每行分别对应ui、vi、wi。
//相同位置的一组<ui, vi, wi>表示结点ui和vi之间有一条长度为wi的道路。
//输入中的数字，两两间均有空格隔开
//1 ≤ ui, vi ≤ n，0 ≤ wi ≤ 1000，1 ≤ m ≤min{30000, n2}。

//输出描述
//输出1行，只包括1个整数，表示题目所求的最小长度和。

//样例输入
//3 3
//1 1 2 
//2 3 3 
//885 513 817
//样例输出
//1330

//提示
//样例中<u1, v1, w1>对应<1,2,885>,<u2, v2, w2>对应为<1,3,513>,<u3, v3, w3>对应为<2,3,817>。 修路时选择1-3和2-3即可完成，此时最小长度和为1330
