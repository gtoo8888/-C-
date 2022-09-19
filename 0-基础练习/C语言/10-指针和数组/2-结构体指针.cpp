//#include <stdio.h> 
//#include <stdlib.h>
//typedef struct test1{
//	char a1;
//	int b1;
//}wenhao1,wenhao11,wenhao33,wenhao44,*cnm1;
//
//typedef struct{
//	int b2;
//	char a2;
//}wenhao2,*cnm2;
//
//typedef struct wenhao3{
//	int b3;
//	char a3;
//	wenhao3 *c3;
//}wenhao3,*cnm3;
//
//typedef double yigehenchangdeshu;
//
//int main(void)
//{
//	yigehenchangdeshu aaa;
//	aaa = 23.44;
//	
//	printf("%f\n\n",aaa);
///**************************************************************/
//	wenhao44 tmd1;
//	tmd1.a1 = '?';
//	tmd1.b1 = 777;
//	
//	wenhao2 tmd2;
//	tmd2.a2 = '^';
//	tmd2.b2 = 333;
//
//	
//	printf("%c %d\n\n",tmd1.a1,tmd1.b1);
//	printf("%c %d\n\n",tmd2.a2,tmd2.b2);
//
///**************************************************************/		
//	cnm3 bm1,bm2;//这是一个结构体指针
//
//	//给结构体指针赋值的两种方法 
//	bm1 = (wenhao3 *)malloc(sizeof(wenhao3 *));//方法1:可以给p分配一段内存空间，并使其指向此空间：
//	//bm1 = (cnm3 )malloc(sizeof(cnm3));//方法1:可以给p分配一段内存空间，并使其指向此空间：
//	//bm1 = &tmd1;//方法2：可以让p指向一个已存在的内存空间：
//	(*bm1).a3 = '$';
//	bm1 -> b3 = 1234;
//	
//	
//	bm2 = (cnm3)malloc(sizeof(cnm3));
//	//bm2 -> a3 = bm1 -> a3;
//	
//	bm2 = bm1 -> c3;//这是结构体里的结构体指针，所以可以这么赋值，这两个是嵌套的关系 
//
//	printf("%c %d %p\n\n",bm2 -> a3,bm2 -> b3,bm2 -> c3);
//
//	return 0;
//}
