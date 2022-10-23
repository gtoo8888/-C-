#include <iostream> 
#include <cmath> 
#include <vector> 
#include <ctime> 
#include <algorithm> 
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"
using namespace std;

const long size1 = 39000L;

int main(void){
	vector<int> numbers(size1);

	srand(time(0));
	generate(numbers.begin(),numbers.end(),rand);
	cout << size1 << endl;

	// 两个独立lambda方法
	int count3 = count_if(numbers.begin(),numbers.end(),
			 [](int x){return x%3 == 0;});			 
	cout << count3 << endl;

	int count13 = 0;
	for_each(numbers.begin(),numbers.end(),
			[&count13](int x){count13 += x % 13;});		// 等价于上面的count_if操作
	cout << count13 << endl;

	// 单个lambda方法
	count3 = count13 = 0;
	for_each(numbers.begin(),numbers.end(),
	[&](int x){count3 += x%3 == 0;count13 += x%13;});	// 使用&同时捕获
	cout << count3 << endl;
	cout << count13 << endl;
	return 0;
}

