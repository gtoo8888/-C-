#include <iostream> 
#include <string>
using namespace std;
#define MAX 10000

struct person{
	string name;
	int sex;
	int age;	
	string phone;
	string addr;
};

struct address_book{
	struct person person_addr[MAX];
	int size;
};

void ShowMeum(void)
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、删除联系人*****" << endl;
	cout << "*****3、查找联系人*****" << endl;
	cout << "*****4、修改联系人*****" << endl;
	cout << "*****5、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl; 
} 

void addperson(address_book *abs)
{
	if(abs -> size > MAX)	
	{
		cout << "满了" << endl; 
	}
	else
	{
		string name;
		cout << "姓名" << endl;
		cin >> name;
		abs -> person_addr[abs -> size].name = name;
		
		int sex;
		cout << "性别" << endl;
 		while(1)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs -> person_addr[abs -> size].sex = sex;
				break;
			}
			cout << "wrong!" << endl;
		}
		
		int age;
		cout << "年龄" << endl;
		cin >> age;
		abs -> person_addr[abs -> size].age = age;
		
		string phone;
		cout << "电话" << endl;
		cin >> phone;
		abs -> person_addr[abs -> size].phone = phone;
		
		string addr;
		cout << "地址" << endl;
		cin >> addr;
		abs -> person_addr[abs -> size].addr = addr;
		
		abs -> size++;
		cout << "添加成功" << endl; 
	}
	system("pause");
	system("cls");
}

int main()
{
	struct address_book abs;
	abs.size = 0;
	
	int select;
	while(true)
	{
		ShowMeum();
		cin >> select;
		switch(select)
		{
			case 1:
				addperson(&abs);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 0:
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;
			
				
		}
		
	}
	system("pause");
	return 0;
}
