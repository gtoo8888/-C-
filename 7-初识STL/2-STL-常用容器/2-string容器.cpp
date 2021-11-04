#include <iostream> 
using namespace std;
#include <string>

// 本质:
// string是C++风格的字符串，而string本质上是一个类
// string和char*区别;
// char*是一个指针
// string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
// 特点:
// string类内部封装了很多成员方法
// 例如:查找find，拷贝copy，删除delete替换replace，插入insert
// string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

/*
string() ;//创建一个空的字符串例如:string str;
string(const char* s);//使用字符串s初始化
string(const string& str) ;//使用一个string对象初始化另一个string对象
string(int n,char c);//使用n个字符c初始化
*/
//string的构造函数
void test01(){
	string s1;

	const char *str = "he";
	string s2(str);
	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10,'a');
	cout << "s4 = " << s4 << endl;
}


/*
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &sg ;//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign (const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s，int n) ;//把字符串s的前n个字符赋给当前的字符串
string& assign (const string &s) ;//把字符串s赋给当前字符串
string& assign(int n,char c);//用n个字符c赋给当前字符串
*/
//string赋值操作
void test02(){
	string str1;
	str1 = "hello world";
	cout << str1 << endl;

	string str2;
	str2 = str1;
	cout << str2 << endl;

	string str3;
	str3 = 'a';
	cout << str3 << endl;

	string str4;
	str4.assign("hello C++");
	cout << str4 << endl;

	string str5;
	str5.assign("hello C++",5);
	cout << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << str6 << endl;

	string str7;
	str7.assign(10,'w');
	cout << str7 << endl;
}


/*
string& operator+=( const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& operator+=(const string& str);//重载+=操作符
string& append(const char*s );//把字符串s连接到当前字符串结尾
string& append( const char *s， int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s ) ;//同operator+=(const string& str)
string& append(const string &s， int pos，int wn);//字符串s中从pos开始的n个字符连接到字符串结尾
*/
//字符串拼接
void test03(){
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << str1 << endl;

	str1 += ":";
	cout << str1 << endl;

	string str2 = "LOL DNF"; 
	str1 += str2;
	cout << str1 << endl;

	string str3 = "I";
	str3.append("love");
	cout << str3 << endl;
	
	str3.append("game abcde",4);
	cout << str3 << endl;

	str3.append(str2);
	cout << str3 << endl;

	str3.append(str2,0,3);//第0个位置开始到第3个
	cout << str3 << endl;
}
/*
int find(const string& str, int pos = 0) const;//查找str第一-次出现位置，从pos开始查找
int find(const char* s，int pos = 0) const;//查找s第一-次出现位置，从pos开始查找
int find(const char* s，int pos, int n) const;//从pos位置查找s的前n个字符第一次位置
int find(const char C，int pos = 0) const;//查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;} //查找str最后- -次位置，从pos开始查找
int rfind(const char* S，int pos = npos) const;//查找s最后一-次出现位置，从pos开始查找
int rfind(const char* s，int pos, int n) const;//从pos查找s的前n个字符最后一-次位置
int rfind(const char C, int pos = 0) const;//查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str);//替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s);//替换从pos开始的n个字符为字符串S
*/

//查找
void test04(){
	string str1 = "abcdefgde";
	int pos = str1.find("de");//从左往右查找
	
	if(pos == -1)
		cout << "未找到" << endl;
	else
		cout << pos << endl;

	pos = str1.rfind("de");//从右往左查找
	cout << pos << endl;
}

//替换
void test05(){
	string str1 = "abcdefg";
	str1.replace(1,3,"1111");//后面写了几个替换几个

	cout << str1 << endl;
}

// int compare(const string &s) const; //与字符串s比较
// int compare(const char *s) const;//字符串s比较
//字符串比较
void test06(){
	string str1 = "hello";
	string str2 = "xello";

	if(str1.compare(str2) == 0)
		cout << "str1 等于 str2" << endl;
	else if(str1.compare(str2) > 0)
		cout << "str1 大于 str2" << endl;
	else
		cout << "str1 小于 str2" << endl;
}

// char& operator[](int n);//通过[]方式取字符
// char& at(int n);//通过at方法获取字符
//string字符存取
void test07(){
	string str1 = "hello";
	cout << str1 << endl;

	//1.通过[]访问单个字符
	for(int i = 0;i < str1.size();i++)
		cout << str1[i] << " ";
	cout << endl;
	//2、通过at方式访问单个字符
	for(int i = 0;i < str1.size();i++)
		cout << str1.at(i) << " ";
	cout << endl;

	str1[0] = 'X';
	cout << str1 << endl;

	str1.at(1) = 'X';
	cout << str1 << endl;
}

// string& insert(int pos, const char* s);//插入字符串
// string& insert(int pos, const string& str);//插入字符串
// string& insert(int pos, int n, char]c);//在指定位置插入n个字符C
// string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
//字符串的插入和删除
void test08(){
	string str1 = "hello";
	cout << str1 << endl;
	
	str1.insert(1,"111");//插入
	cout << str1 << endl;

	str1.erase(1,4);//删除
	cout << str1 << endl;
}

//string求子串
void test09(){
	string str = "abcdfeg";
	string subStr = str.substr(1,3);
	cout << subStr << endl;
}
//实用操作
void test10(){
	string email = "zhangsan@sina.com";
	int pos = email.find('@');
	cout << pos << endl;

	string userName = email.substr(0,pos);
	cout << userName << endl;
}


int main(){
	test01();
	cout << endl;

	test02();//string赋值操作
	cout << endl;

	//test03();//字符串拼接
	cout << endl;

	test04();//查找
	test05();//替换
	cout << endl;

	test06();//字符串比较
	cout << endl;

	test07();//string字符存取
	cout << endl;

	test08();//字符串的插入和删除
	cout << endl;

	test09();//string求子串
	test10();//实用操作
	return 0;
}



