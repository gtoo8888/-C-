#include <iostream>
using namespace std;
#include <fstream>
#include <string>
// 文件类型分为两种:
// 1.文本文件 -文件以文本的ASCII码形式存储在计算机中
// 2.二进制文件-文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它??
// 操作文件的三大类:
// 1. ofstream:写操作
// 2. ifstream:读操作
// 3. fstream:读写操作

// ios:in //为读文件而打开文件
// ios:out //为写文件而打开文件
// ios:ate//初始位置:文件尾
// ios:.app//追加方式写文件
// ios::trunc//如果文件存在先删除，再创建
// ios::binary//二进制方式

// 注意:文件打开方式可以配合使用，利用|操作
// 例如:用二进制方式写文件
// ios: :binary|ios:: out
//写文件 
void test01(){
    //1、 包含头文件fstream
    
    ofstream ofs;//2、 创建流对象
    ofs.open("text.txt",ios::out);//3、指定打开方式
    ofs << "姓名：张三" << endl;//4、 写内容
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;
    ofs.close();//5、关闭文件
}
//总结:
//文件操作必须包含头文件fstream
//读文件可以利用ofstream ,或者fstream类
//打开文件时候需要脂定操作文件的路径，以及打开方式·利用<<可以向文件中写数据
//操作完毕，要关闭文件

//读文件 
void test02(){
	ifstream ifs;//2.创建流对象
	ifs.open("text.txt",ios::in);//3.打开文件并判断文件是否打开成功
	if(!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return; 
	}
	//4.读数据
//	//第一种 
//	char buf[1024] = {0};
//	while(ifs >> buf)
//		cout << buf << endl;
//	//第二种
//	char buf[1024] = {0};
//	while(ifs.getline(buf,sizeof(buf)))
//		cout << buf << endl;
//	//第三种
//	string buf;
//	while(getline(ifs,buf)) 
//		cout << buf << endl;
	//第四种
	char c;
	while( (c = ifs.get()) != EOF) 
		cout << c;
	//5.关闭文件
	ifs.close();	
}

//以二进制的方式对文件进行读写操作
//打开方式要指定为ios::binary 
//二进制方式写文件主要利用流对象调用成员函数write
//函数原型:ostream& write(const char * buffer,int len) ;
//参数解释:字符指针buffer指向内存中一段存储空间。len是读写的字节数

//二进制文件 写文件 
class Person{
public:
	char m_name[64];
	int m_age;
};
void test03(){
//    ofstream ofs;
//    ofs.open("person.txt",ios::out | ios ::binary);
    ofstream ofs("person.txt",ios::out | ios ::binary);//在创建对象的同时进行打开
	Person p = {"张三",18}; 
	ofs.write((const char *)&p,sizeof(Person));//写文件 
	ofs.close(); 
}


//读文件
//二进制方式读文件主要利用流对象调用成员函数read
//函数原型:istream& read(char *buffer,int len);
//参数解释:字符指针buffer指向内存中一段存储空间。len是读写的字节数

//二进制读文件 
void test04(){
	ifstream ifs;
	ifs.open("person.txt",ios::in | ios::binary) ;
	if(!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return; 
	}
	Person p;
	ifs.read((char *) &p,sizeof(Person));
	cout << p.m_age << ' ' << p.m_name << endl;
	ifs.close();
}


int main(){
    test01();
    cout << endl; 
    
    test02();
    cout << endl; 
    
    test03();
    cout << endl; 
    
    test04();
    cout << endl; 
    return 0;
}
























