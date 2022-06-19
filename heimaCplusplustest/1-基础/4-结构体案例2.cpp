#include <iostream> 
using namespace std;

struct hero{
	string name;
	int age;
	string sex;
};

void sorthero(struct hero harr[],int len)
{
	for(int i = 0;i < len;i++)
	{
		for(int j = i;j < len;j++)
		{
			if(harr[i].age < harr[j].age)
			{
				struct hero temp = harr[i];
				harr[j] = harr[i];
				harr[i] = temp;
			}
		}
	}
}

void printfhero(struct hero harr[],int len)
{
	for(int i = 0;i < len;i++)
	{
		cout << harr[i].name << ' ' << harr[i].age << ' ' << harr[i].sex << endl;
	}
	cout << endl;
}


int main()
{
	struct hero heroarry[5] = {
		{"����" ,23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����" ,21,"��"},
		{"����",19,"Ů"}
	};
	int len = sizeof(heroarry)/sizeof(struct hero);
	
	printfhero(heroarry,len);
	
	sorthero(heroarry,len);
	
	printfhero(heroarry,len);
	return 0;
}

