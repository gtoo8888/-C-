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
		{"Áõ±¸" ,23,"ÄÐ"},
		{"¹ØÓð",22,"ÄÐ"},
		{"ÕÅ·É",20,"ÄÐ"},
		{"ÕÔÔÆ" ,21,"ÄÐ"},
		{"õõ²õ",19,"Å®"}
	};
	int len = sizeof(heroarry)/sizeof(struct hero);
	
	printfhero(heroarry,len);
	
	sorthero(heroarry,len);
	
	printfhero(heroarry,len);
	return 0;
}

