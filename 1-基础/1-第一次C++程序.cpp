//#include <iostream>
//using namespace std;
//
//void swap(int *p1,int *p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//
//void printfarr(int *arr,int len)
//{
//	for(int i = 0;i < len;i++)
//		cout << *(arr + i) << " ";
//	cout << endl;	
//}
//
//void maopao(int *arr,int len)
//{
//	for(int i = 0;i < len;i++)
//	{
//		for(int j = i;j < len;j++)
//		{
//			if(arr[i] > arr[j])
//				swap(arr + i,arr + j);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {6,43,5,345,2,42,42,4,32,56,364,6,3,4,234,2562};
//	int num;
//	num = sizeof(arr)/sizeof(int);
//	
//	printfarr(arr,num);
//		
//	maopao(arr,num);
//	
//	printfarr(arr,num);
//
//	cout << num << endl;
//	return 0; 
//}
