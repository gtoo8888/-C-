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
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2��ɾ����ϵ��*****" << endl;
	cout << "*****3��������ϵ��*****" << endl;
	cout << "*****4���޸���ϵ��*****" << endl;
	cout << "*****5�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl; 
} 

void addperson(address_book *abs)
{
	if(abs -> size > MAX)	
	{
		cout << "����" << endl; 
	}
	else
	{
		string name;
		cout << "����" << endl;
		cin >> name;
		abs -> person_addr[abs -> size].name = name;
		
		int sex;
		cout << "�Ա�" << endl;
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
		cout << "����" << endl;
		cin >> age;
		abs -> person_addr[abs -> size].age = age;
		
		string phone;
		cout << "�绰" << endl;
		cin >> phone;
		abs -> person_addr[abs -> size].phone = phone;
		
		string addr;
		cout << "��ַ" << endl;
		cin >> addr;
		abs -> person_addr[abs -> size].addr = addr;
		
		abs -> size++;
		cout << "��ӳɹ�" << endl; 
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
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			
				
		}
		
	}
	system("pause");
	return 0;
}
