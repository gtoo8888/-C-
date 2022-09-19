/*
指针是一个值为内存地址的变量，一种以符号形式使用地址的方法
数组表示法变相的使用指针 
char类型变量的值为字符
int类型变量的值为整数
指针变量的值为地址 
*/
/***************9.15前置 指针的基本写法********************/ 
#include <stdio.h>

int main(void)
{
	int nurse = 5,val; 
	int *ptr;//对指针的声明的方法，必须指定指针所指向变量的类型，不同类型占用的空间不同 
//程序必须知道储存在指定地址上的数据类型，long float空间相同，但是存的数字却不同 
//int* ptr; int *ptr;都是可以的，但是应该统一
//ptr本身是什么类型？是指向int类型的指针，ptr的值是一个地址，一个无符号整数，但是不能认为是整数类型，不能用整数运算，一个新类型 
	
//int *pi;//指向int类型变量的指针 
//char *pc;//指向char类型变量的指针
//float *pf,*pg; //指向float类型变量的指针

	ptr = &nurse;//把nurse的地址赋值给ptr（ptr指向nurse）（指向nurse的指针） 
/*ptr和nurse区别：
ptr变量，nurse常量 
ptr左值，nurse右值
ptr还可以指向别处 */
	val = *ptr;//*为间接运算符（解引用运算符），找出ptr指向的值
	//{ptr = &nurse;	val = *ptr;} 两句放在一起 等于 val = nurse; 
	printf("%d\n",val);
	return 0;
}
/*小结： 
地址运算符 		& 后面跟变量名 			&nurse 给出变量的地址
地址运算符 		* 后面跟指针名或地址 	*ptr 给出指针指向地址上的值 
*/

/***************9.15********************/ 	
#include <stdio.h>

void interchange(int *u,int *v)//函数中的形参把地址作为他们的值，所以应该声明为指针 
{
	int temp;//声明一个变量
	temp = *u;//u的值是&x（x的地址），u指向x，可以用*u表示x的值 
  //temp = u;赋值给temp是x的地址，不是x的值 
	*u = *v;//相当于x = y; 
	*v = temp;
	printf("%d %d\n",u,v);//显示了uv所指向的地址 
}

int main(void)
{
	int x = 5,y = 10;
	printf("x = %d y = %d\n",x,y);
	interchange(&x,&y);//传递的不是xy的值，是他们的地址 
	printf("x = %d y = %d\n",x,y);
	return 0;
}
