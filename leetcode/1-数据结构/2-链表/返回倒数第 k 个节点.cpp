#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int a;
	int b;
}data;

data *shu(int x,int y)
{
	data *test;
	test = (data *)malloc(sizeof(data *));
	test -> a = x;
	test -> b = y;
	printf("%d %d\n\n",test -> a,test -> b);
	//������free�ͷſռ䣬��Ȼ��û��ֵ�� 
	return test;
}

int main(void)
{
	data *a = shu(4,5);
	printf("%d %d\n\n",a -> a,a -> b);
	return 0;
}


/*
ָ�뺯��������
���Ƕ�����һ���ṹ�壬����������Ϊdata
�������ж�����һ��data���͵�ָ��a
��һ��ָ�뺯��shu�����ķ���ֵΪint���͵�ָ��
ָ�뺯��shu�У�������һ��data���͵�test���������ҷ����˿ռ�
�Խṹ��ָ��ĳ�Աa,b�ֱ�ֵ��Ȼ����ʾ��һ����4,5


*/

