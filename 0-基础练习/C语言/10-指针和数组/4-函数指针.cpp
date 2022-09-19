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
//int (*fun)(int x,int y);//函数指针声明 
//
//int main(void)
//{
//	fun = add;//赋值的第一种写法 
//	printf("%d\n\n",(*fun)(1,2));
//	
//	fun = &sub;//赋值的第二种写法，&不是必需的，因为一个函数标识符就表示了它的地址
//	//如果是函数调用，还必须包含一个圆括号括起来的参数表。
//	printf("%d\n\n",(*fun)(7,2));//调用的写法一 
//	
//	printf("%d\n\n",fun(13,6));//调用的写法二 
//	return 0;
//}
//

