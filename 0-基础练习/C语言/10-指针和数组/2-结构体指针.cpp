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
//	cnm3 bm1,bm2;//����һ���ṹ��ָ��
//
//	//���ṹ��ָ�븳ֵ�����ַ��� 
//	bm1 = (wenhao3 *)malloc(sizeof(wenhao3 *));//����1:���Ը�p����һ���ڴ�ռ䣬��ʹ��ָ��˿ռ䣺
//	//bm1 = (cnm3 )malloc(sizeof(cnm3));//����1:���Ը�p����һ���ڴ�ռ䣬��ʹ��ָ��˿ռ䣺
//	//bm1 = &tmd1;//����2��������pָ��һ���Ѵ��ڵ��ڴ�ռ䣺
//	(*bm1).a3 = '$';
//	bm1 -> b3 = 1234;
//	
//	
//	bm2 = (cnm3)malloc(sizeof(cnm3));
//	//bm2 -> a3 = bm1 -> a3;
//	
//	bm2 = bm1 -> c3;//���ǽṹ����Ľṹ��ָ�룬���Կ�����ô��ֵ����������Ƕ�׵Ĺ�ϵ 
//
//	printf("%c %d %p\n\n",bm2 -> a3,bm2 -> b3,bm2 -> c3);
//
//	return 0;
//}
