//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct{
//	int a;
//	int b;
//}data;
//
//int add(int x,int y){
//    return x+y;
//}
//
//int sub(int x,int y){
//    return x-y;
//}
//
//int (*fun)(int x,int y);//����ָ������ 
//
//int main(void)
//{
//	fun = add;//��ֵ�ĵ�һ��д�� 
//	printf("%d\n\n",(*fun)(1,2));
//	
//	fun = &sub;//��ֵ�ĵڶ���д����&���Ǳ���ģ���Ϊһ��������ʶ���ͱ�ʾ�����ĵ�ַ
//	//����Ǻ������ã����������һ��Բ�����������Ĳ�����
//	printf("%d\n\n",(*fun)(7,2));//���õ�д��һ 
//	
//	printf("%d\n\n",fun(13,6));//���õ�д���� 
//	return 0;
//}
//

