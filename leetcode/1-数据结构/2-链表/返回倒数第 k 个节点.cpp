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
	//不能用free释放空间，不然就没有值了 
	return test;
}

int main(void)
{
	data *a = shu(4,5);
	printf("%d %d\n\n",a -> a,a -> b);
	return 0;
}


/*
指针函数的问题
先是定义了一个结构体，并且重命名为data
主函数中定义了一个data类型的指针a
有一个指针函数shu，它的返回值为int类型的指针
指针函数shu中，创建了一个data类型的test变量，并且分配了空间
对结构体指针的成员a,b分别赋值，然后显示了一下是4,5


*/

