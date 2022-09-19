/*************************10.8指针和数组的初步使用以及一大堆解释*************************/
//#include <stdio.h>
//#define SIZE 4
//int main(void)
//{
//	short index;
//	
//	short dates[SIZE];
//	short *pti;
//	double bills[SIZE];
//	double *ptf;
//	
//	pti = dates;//把数组的地址赋值给指针,数组名dates是该数组首元素的地址 
//	ptf = bills;
//	
//	printf("%23s %15s\n","short","double");
//	for(index = 0;index < SIZE;index++)
//		printf("ptr + %d : %10p %10p\n",index,pti + index,ptf + index);//%p以十六进制显示指针的值 
//	//指针加1表示增加一个储存单元
//	//对于数组，加1后的地址是下一元素的地址(000000000062FE02)，而不是下一个字节的地址(000000000062FE01) 
//	//对于short,指针加1，每次递增2字节 
//	//必须声明 指针 所指向 对象类型 的原因之一 
//	printf("\n\n%p %p\n",dates + 2,&dates[2]);// dates + 2 == &dates[2] 都是地址 
//	printf("%10d %10d\n",*(dates + 2),dates[2]);//*(dates + 2) == dates[2] 都是值 ，很好的体现了C语言的灵活性，数组和指针关系密切
//	//如果使用数组的时候 dates[2]完全等同于 *(dates + 2),都是一个值
//	//*(dates + 2)可以认为“到内存中datas的位置（数组头的位置），然后移动n个单位（是定义的dates的数据类型的字节数），检索储存在那里的值” 
//	printf("\n\n%10d %10d\n",*(dates + 2),*(dates) + 2);
//	//*(dates + 2) //dates第三个元素的值 
//	//*(dates) + 2 //dates第一个元素加2的值 
//	return 0;
//}
///*输出为： 
//                  short          					double
//ptr + 0 : 000000000062FE00（两个数组开始的地址） 000000000062FDE0
//ptr + 1 : 000000000062FE02（指针加1后的地址） 	 000000000062FDE8
//ptr + 2 : 000000000062FE04 						 000000000062FDF0
//ptr + 3 : 000000000062FE06 						 000000000062FDF8
//地址按字节编址，short 2字节，double 8字节	
//*/

///*************************10.9 指针和数组的初步使用*************************/
//#include <stdio.h>
//#define MONTHS 12
//int main(void)
//{
//	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
//	int i;
//	
//	for(i = 0; i < MONTHS;i++)
//		printf("%2d %d\n",i + 1,*(days + i));
//	return 0;
//}


///*************************10.10 函数中使用数组和指针*************************/
//#include <stdio.h> 
//#define SIZE 10
//int sum (int ar[],int n);
////int sum (int *ar,int n);
////		   第一个形参告诉了函数数组的数据类型和地址 
////int sum (int *,int );
////int sum (int ar[],int n);
////int sum (int [],int );
////以上四种全部等价 
////只有在函数原型或函数定义头中，才可以用 int ar[]代替 int *ar，都表示ar是一个指向int类型的指针
////ar[i]与*(ar+i)是等价的，但是只有当ar是指针变量时，才能使用ar++这个表达式 
////int ar[]提醒了ar指向的不仅仅是一个int类型值，还是一个int类型元素 
//
//int main(void)
//{
//	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
//	long answer;
//	
//	answer = sum(marbles,SIZE);
//	
//	printf("%ld\n",answer);
//	printf("%zd\n",sizeof marbles);//%zd用来打印sizeof的返回值 
//	//sizeof marbles后面一个是数组，数组名字用来表示他的首地址 
//	
//	return 0;
//}
//
//int sum (int ar[],int n)//这里写数组是用了数组和指针的特殊关系 
////请问ar[]数组的大小 
//{
//	int i;
//	int total = 0;
//	
//	for(i = 0;i < n;i++)
//		total += ar[i];
//	printf("%zd\n",sizeof ar);
//	//ar数组只有8个字节，ar不是数组本身，它是一个指向marbles数组首元素的指针，用8字节储存地址，所以大小为8 
//	
//	return total;
//}

///*************************10.11 传递两个指针，数组中指针的比较*************************/
//#include <stdio.h> 
//#define SIZE 10
//int sump(int *start,int *end);
//
//int main(void)
//{
//	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
//	long answer;
//	
//	answer = sump(marbles,marbles + SIZE);//C保证marbles + SIZE位置有效，但是marbles[SIZE]这个值没有保证，不能访问 
//	
//	printf("%ld\n",answer);
//	printf("%zd\n",sizeof marbles);
//	
//	return 0;
//}
//
////使用指针累加运算，其实指明开始处的方法和10.10一致 
//int sump(int *start,int *end)
//{
//	int total = 0;
//	while(start < end)//循环最后处理的一个元素是end所指向位置的前一个元素，end指向的位置实际上在数组最后一个元素后面
//	//C能保证给数组分配空间时，数组后面第一个位置指针仍然是有效的指针，while就可以这么写
//	//这种“越界”指针调用更加简洁 ，最后一次执行完start++，start就是end的值 
//	{
//		total += *start;
//		start++;//递增指针变量，让指针指向下一个值 ，start是 int类型，start++是递增一个int类型的大小 
//		//指针与递增一起使用的时候，更加接近机器语言，编译器在编译时能生成更加有效率的代码 
//		//total += *start++;//简洁的写法
//		//*和++ 优先级相同，结合律从右往左 ,先把指针指向位置上的值加到total上，然后再递增指针 P294
//		//*++start，先递增指针，然后把指针指向位置上的值加到total上
//		//*(start++)这样写更加清楚 
//	}
//	return total;
//}

///*************************10.12 *和++的运算*************************/
//#include <stdio.h> 
//int data[2] = {100,200};
//int moredata[2] = {300,400};
//
//int main(void)
//{
//	int *p1,*p2,*p3;
//	
//	p1 = p2 = data;
//	p3 = moredata;
//	printf("  *p1 = %d,   *p2 = %d,     *p3 = %d,\n",*p1,*p2,*p3);
//	printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d,\n",*p1++,*++p2,(*p3)++);
//	printf("  *p1 = %d,   *p2 = %d,     *p3 = %d,\n",*p1,*p2,*p3);
//	
//	return 0;
//}

/*************************10.13 基本的指针操作*************************/
/*************************还可以用关系运算符比较指针 10.11while中使用的那样*************************/
#include <stdio.h> 

int main(void)
{
	int urn[5] = {100,200,300,400,500};
	int *ptr1,*ptr2,*ptr3;
	
	printf("%d\n\n",sizeof(int));
	ptr1 = urn;//赋值：把地址赋值给指针，可以赋值过去的：数组名，带&的变量名，另一个指针（已经初始化了的？） 
	//地址应该和指针类型兼容，不能把dobule类型地址赋值给int的指针 
	ptr2 = &urn[2];
	
	printf("直接指针的值，取消应用指针的值，指针地址\n");
	printf("ptr1 = %p,*ptr1 = %d,&ptr1 = %p\n\n",ptr1,*ptr1,&ptr1);
	//解引用：*给出了指针指向地址上储存的值 
	//取址 ：和所有变量一样，指针变量也有自己的地址和值 
	
	ptr3 = ptr1 + 4;//等价&urn[4] ，超过数组范围，计算结果未定义，除非正好超过数组末尾第一个位置，C保证该指针有效 
	printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n\n",ptr1 + 4,*(ptr1 + 4));
	
	ptr1++;//ptr1指向了urn[1] 
	printf("ptr1 = %p,*ptr1 = %d,&ptr1 = %p\n\n",ptr1,*ptr1,&ptr1);
	
	ptr2--;//ptr1指向了urn[2] 
	printf("ptr2 = %p,*ptr2 = %d,&ptr2 = %p\n\n",ptr2,*ptr2,&ptr2);
	--ptr1;
	++ptr2;
	printf("ptr1 = %p,ptr2 = %p\n\n",ptr1,ptr2);
	printf("ptr2 = %p,ptr1 = %p,ptr2 - ptr1 = %td\n\n",ptr2,ptr1,ptr2 - ptr1);
	//求差指计算两个元素之间的距离，这句话里面指相隔两个int，而不是2字节，只有指向同一个数组的两个指针相减才有效 
	printf("ptr3 = %p,ptr3 - 2 = %p\n\n",ptr3,ptr3 - 2);//ptr3 - 2等价&urn[2] 
	
//	int *pt; 
//	*pt = 5;//恐怖的实验，程序崩溃，头文件也没了 
//	printf("%p,%d,%p\n\n",pt,*pt,&pt);

	return 0;
}
/*注意：不要解引用未初始化的指针
int *pt;
*pt = 5;//原意：把5储存在pt指向的位置
但pt未初始化，它的值是一个随机值，不知道5储存在哪里，会出错或者程序崩溃 
创建一个指针的时候，系统只是分配了储存指针本身的内存，没有分配储存数据的内存 
因此，使用指针前，必须初始化它，比如用现有变量的地址初始化该指针 
翻译：创建一个指针后，必须初始化它！！！！
不能直接 *pt = 5;这样赋值,也不能用printf("%p,%d,%p\n\n",pt,*pt,&pt);这样直接打印它所存放的的变量地址和 自己所在的地址 

假设
int urn[3];
int *ptr1,*ptr2;
有效语句，			无效语句
ptr1++;				urn++ 
ptr2 = ptr1 + 2; 	ptr2 = ptr1 + ptr2; 
ptr2 = urn + 1;		ptr2 = urn * ptr1;	

指针数组、函数指针、指针向指针的指针数组、指向函数的指针数组	
基本用法：
1.函数间传递信息
2.处理数据的函数中 
*/

///*************************10.15 指针和多维数组*************************/
//#include <stdio.h> 
//int main(void)
//{
//	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
//	
//	printf("              zippo = %p,   zippo + 1 = %p\n\n",zippo,zippo + 1);
//	printf("           zippo[0] = %p,zippo[0] + 1 = %p\n\n",zippo[0],zippo[0] + 1);
//	printf("             *zippo = %p,  *zippo + 1 = %p\n\n",*zippo,*zippo + 1);//zippo[0]与*zipoo完全相同 
//	printf("        zippo[0][0] = %16d\n\n",zippo[0][0]);
//	printf("          *zippo[0] = %16d\n\n",*zippo[0]);
//	printf("            **zippo = %16d\n\n",**zippo);//双重间接 ，解引用两次 
//	printf("        zippo[2][1] = %16d\n\n",zippo[2][1]);
//	printf("*(*(zippo + 2) + 1) = %16d\n\n",*(*(zippo + 2) + 1));//为了说明如果有二维数组应该用数组表示法而不是指针表示法 
//
//	return 0;
//} 

/*************************10.15 声明一个指向多维数组的指针*************************/
//#include <stdio.h> 
//int main(void)
//{
//	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
//	int (*pz)[2];//指向多维数组的指针唯一的声明方法，解释：pz指向一个内含两个int类型值的数组  
//	//仅仅声明为指向int类型还不够，因为仅仅 指向int类型只能与zippo[0]匹配，pz必须指向一个内含两个int类型值的数组 
//	//int *pz[2];//[]的优先级高于* ,解释：pz是一个内含两个指针元素的数组，每个元素都指向int的指针 
//	pz = zippo;
//	
//	printf("              pz = %p,   pz + 1 = %p\n\n",pz,pz + 1);
//	printf("           pz[0] = %p,pz[0] + 1 = %p\n\n",pz[0],pz[0] + 1);
//	printf("             *pz = %p,  *pz + 1 = %p\n\n",*pz,*pz + 1);
//	printf("        pz[0][0] = %16d\n\n",pz[0][0]);
//	printf("          *pz[0] = %16d\n\n",*pz[0]);
//	printf("            **pz = %16d\n\n",**pz);
//	printf("        pz[2][1] = %16d\n\n",pz[2][1]);
//	printf("*(*(pz + 2) + 1) = %16d\n\n",*(*(pz + 2) + 1));
////zippo[m][n] == *(*(zippo + m) + n);
////pz[m][m] == *(*(pz + m) + n);
//
//	return 0;
//} 







