//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <ctime>
//using namespace std;
//
//
//struct student{
//	string name;
//	int num;
//};
//
//struct teacher{
//	string name;
//	struct student s1[5];
//};
//
//void malloc_teacher(struct teacher tArr[],int len)
//{
//	char nameSpace[] = "ABCDE";
//	for(int i = 0;i < len;i++)
//	{
//		tArr[i].name = "teacher_" ;
//		tArr[i].name += nameSpace[i];
//		for(int j = 0;j < 5;j++)
//		{
//			tArr[i].s1[j].name = "student_";
//			tArr[i].s1[j].name += nameSpace[i];
//			
//			int num = rand()%60;
//			tArr[i].s1[j].num = num;
//		}
//		
//	}
//}
//
//void print_teacher(struct teacher tarr[],int len)
//{
//	for(int i = 0;i < len;i++)
//	{
//		cout << tarr[i].name << endl;
//		for(int j = 0;j < 5;j++)
//		{
//			cout << '\t' << tarr[i].s1[i].name << '\t' << tarr[i].s1[j].num << endl;
//		}
//	}
//}
//
//
//int main()
//{
//	struct teacher tarr[3];
//	int len;
//	
//	//srand((unsigned int) time(NULL));
//	len = sizeof(tarr)/sizeof(struct teacher);
//	malloc_teacher(tarr,len);
//	print_teacher(tarr,len);
//	return 0; 
//}
